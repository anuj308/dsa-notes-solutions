# INT332 - DevOps, Virtualization & Configuration Management
## Complete Study Notes for End Term Exam (Practical + Viva)

---

# UNIT 1: BASICS OF DEVOPS INFRASTRUCTURE

## 1.1 Introduction to Containers

### Origin of Containers
- **chroot** (1979): First isolation mechanism — changed root directory for processes
- **FreeBSD Jails** (2000): Added processes isolation to chroot
- **Linux VServer** (2001): Partitioned resources on Linux
- **OpenVZ** (2005): OS-level virtualization for Linux
- **LXC (Linux Containers)** (2008): First complete container management using cgroups + namespaces
- **Docker** (2013): Made containers mainstream with easy-to-use tooling

### Emergence of Modern Containerization
- **Why containers became popular:**
  - Earlier apps were **monolithic** → physical servers were apt
  - Later components split (backend, frontend, DB) → **VMs** took over
  - Now apps are **microservices** → containerization tools like Docker serve the purpose
  - **Portability problem** solved using containerization

### Containers vs VMs
| Feature | Containers | Virtual Machines |
|---------|-----------|-----------------|
| OS | Share host OS kernel | Each has full OS |
| Start time | Seconds | Minutes |
| Size | MBs | GBs |
| Resource usage | Minimal | Heavy |
| Isolation | Process-level (namespaces) | Hypervisor-level |
| Can run dozens/hundreds on same machine | ✅ Yes | ❌ Limited |

## 1.2 Container Runtime

**Definition:** A container runtime is the software responsible for creating, starting, stopping, and managing containers on a host system. It acts as the execution engine that turns a container image into a running container.

**Analogy:** Container Image → Packed lunch box | Container Runtime → Person who opens it, serves food, and cleans up

### Types of Container Runtimes

1. **High-Level Runtimes** (Used by users and DevOps tools):
   - Docker Engine
   - containerd
   - CRI-O (Kubernetes-focused)
   - Handle: Image pulling, Networking, Storage, Container lifecycle

2. **Low-Level Runtimes** (Responsible for actually running the container process):
   - runc (OCI-compliant)
   - Directly interact with: Linux kernel, Namespaces, cgroups

### Need for Container Runtime
- Container image is just a read-only package (application + dependencies)
- To run it, system needs runtime to:
  - Create an isolated environment
  - Apply resource limits
  - Start the application process
  - Monitor and stop it when required

## 1.3 Process Isolation & Namespaces

**Namespaces** are Linux kernel features that partition system resources so that processes see only what belongs to them.

> *"Namespaces create the illusion of a separate system for each container."*

### Types of Namespaces Used in Containers

1. **PID Namespace (Process Isolation)**
   - Each container has its own process tree
   - Process IDs inside container start from PID 1
   - A container cannot see host or other container processes
   - **Example:** Inside a container, main app runs as PID 1 (like init/systemd in a VM)

2. **Network Namespace**
   - Each container gets its own IP address and ports
   - Containers can run apps on same port without conflict
   - **Example:** Multiple Nginx containers all listen on port 80 internally

3. **Mount Namespace**
   - Each container has its own filesystem view
   - File changes inside container do not affect host

4. **UTS Namespace**
   - Allows each container to have its own hostname

5. **User Namespace (Advanced)**
   - Maps container users to non-root users on host
   - Improves security

**Analogy:** Namespaces are like separate cabins in a train:
- Same engine (kernel)
- Different passengers
- No visibility between cabins

## 1.4 Control Groups (cgroups) for Resource Limits

**cgroups** are Linux kernel features that limit, control, and monitor resource usage of processes.

**What cgroups can control:**
- CPU limits/shares
- Memory limits
- Disk I/O
- Network bandwidth

**Why cgroups matter:**
- Without cgroups, a single container could consume all system resources
- Prevents "noisy neighbor" problem
- Essential for multi-tenant environments

## 1.5 Container Images & Layers

- Container images are **read-only packages** (application + dependencies)
- Images consist of **layers** stacked on top of each other
- Each layer represents a set of filesystem changes
- **Copy-on-Write (CoW):** When a container runs, a thin writable layer is added on top
- Multiple containers can share the same image layers, saving disk space

### Image Registries & Distribution
- **Docker Hub** — Default public registry
- **GitHub Container Registry (GHCR)**
- **Private registries** — For enterprise use
- Authentication & access tokens needed for private registries

## 1.6 Docker Architecture

### Docker Components

1. **Docker Daemon (dockerd)**
   - Background service running on host
   - Manages Docker objects (containers, images, networks, volumes)
   - Listens for Docker API requests

2. **Docker CLI (docker)**
   - Command-line interface to interact with Docker Daemon
   - Commands: `docker run`, `docker build`, `docker pull`, etc.

3. **Docker Registry & Hub**
   - Stores and distributes container images
   - Docker Hub is the default public registry
   - `docker pull` downloads images from registry
   - `docker push` uploads images to registry

### Docker Object Types
- **Container** — Running instance of an image
- **Image** — Read-only template with instructions for creating a container
- **Network** — Connects containers to each other and host
- **Volume** — Persists data generated by containers

### Docker Layering & Filesystem
- Images built in layers (each Dockerfile instruction = 1 layer)
- Layers cached for faster builds
- Copy-on-Write mechanism for efficient storage

---

# UNIT 2: IMAGE BUILDING & CONTAINER MANAGEMENT

## 2.1 Dockerfile Core Concepts

### Image Layering
- Each instruction in Dockerfile creates a new layer
- Layers are cached — only changed layers rebuild
- Order matters: put infrequently changing instructions first

### Build Context & .dockerignore
- **Build context:** The directory sent to Docker daemon during build
- `.dockerignore`: Exclude files from build context (like `.gitignore`)

### Dockerfile Instructions

| Instruction | Purpose | Example |
|-------------|---------|---------|
| `FROM` | Sets base image | `FROM node:22-alpine` |
| `RUN` | Executes commands during build | `RUN npm install` |
| `COPY` | Copies files from host to image | `COPY . .` |
| `ADD` | Like COPY + URL/tar extraction | `ADD app.tar.gz /app` |
| `CMD` | Default command when container starts | `CMD ["npm", "start"]` |
| `ENTRYPOINT` | Main executable for container | `ENTRYPOINT ["java","-jar","app.jar"]` |
| `WORKDIR` | Sets working directory | `WORKDIR /app` |
| `ENV` | Sets environment variable | `ENV NODE_ENV=production` |
| `EXPOSE` | Documents port (doesn't publish) | `EXPOSE 8080` |
| `VOLUME` | Creates mount point | `VOLUME /data` |

### CMD vs ENTRYPOINT
- **CMD:** Can be overridden when running container (`docker run ... command`)
- **ENTRYPOINT:** Cannot be overridden easily, container always runs this
- **Combined:** ENTRYPOINT is the executable, CMD provides default arguments

### Example Dockerfiles

**Apache HTTP Server:**
```dockerfile
FROM httpd:2.4
COPY ./index.html /usr/local/apache2/htdocs/
```

**Nginx:**
```dockerfile
FROM nginx
COPY index.html /usr/share/nginx/html
```

**Python Flask App:**
```dockerfile
FROM python:3.9-slim
WORKDIR /app
COPY . .
RUN pip install -r requirements.txt
CMD ["python", "app.py"]
```

**Java App (Multi-stage Dockerfile):**
```dockerfile
FROM eclipse-temurin:17-jdk AS build
WORKDIR /app
COPY . .
RUN ./mvnw package -DskipTests

FROM eclipse-temurin:17-jre
WORKDIR /app
COPY --from=build /app/target/*.jar app.jar
EXPOSE 8080
ENTRYPOINT ["java","-jar","app.jar"]
```

**Node.js App:**
```dockerfile
FROM node:22-alpine
WORKDIR /app
COPY package*.json ./
RUN npm ci --omit=dev
COPY . .
ENV NODE_ENV=production
EXPOSE 5006
CMD ["npm", "start"]
```

## 2.2 Image Creation in Detail

### docker build Process
```bash
docker build -t my-image:tag .
# -t = tag, . = build context (current directory)
```

### Image Tagging/Versioning
```bash
docker tag my-image:latest my-image:v1.0
docker tag my-image username/my-image:latest  # for Docker Hub push
```

### Inspecting Images
```bash
docker images         # List all images
docker history <image>  # Show layers and build history
docker inspect <image>  # Detailed metadata
docker image prune     # Remove unused images
```

## 2.3 Docker Networking

### Network Types
1. **Bridge Network (Default)**
   - Internal private network for containers on same host
   - Containers can communicate via IP
   - Default network driver

2. **Host Network**
   - Container shares host's network stack
   - No port mapping needed
   - Less isolation

3. **Overlay Network**
   - For multi-host communication (Docker Swarm)
   - Enables container communication across nodes

### Port Mapping
```bash
# Format: -p <HOST_PORT>:<CONTAINER_PORT>
docker run -p 8080:80 nginx         # Map host 8080 → container 80
docker run -p 80:8082 mongo          # Map host 80 → container 8082
docker run -p 3307:3306 mysql:8     # Map host 3307 → container 3306
```

### DNS Inside Docker
- Docker provides built-in DNS resolution
- Containers can reach each other by container name
- `--link` (legacy) or custom networks for container discovery

## 2.4 Docker Storage

### Volumes vs Bind Mounts

| Feature | Volumes | Bind Mounts |
|---------|---------|-------------|
| Managed by Docker | ✅ Yes | ❌ No |
| Stored in | `/var/lib/docker/volumes/` | Any host path |
| Backup/Restore | Easy | Manual |
| Portable | ✅ | ❌ |
| Use case | Persistent data | Development code sharing |

### Commands
```bash
# Volume
docker volume create projectdata
docker volume ls
docker volume inspect projectdata
docker run -v projectdata:/app/data ubuntu

# Bind Mount
docker run -v /host/path:/container/path ubuntu
```

### Copy-on-Write (CoW) Mechanism
- When container modifies a file, it's copied to the writable container layer
- Original image layer remains unchanged
- Multiple containers share same image layers until they write

## 2.5 Registries

| Registry | URL | Use Case |
|----------|-----|----------|
| Docker Hub | hub.docker.com | Default public registry |
| GHCR | ghcr.io | GitHub Container Registry |
| Private Registry | Self-hosted | Enterprise/internal use |

### Authentication
```bash
docker login          # Login to Docker Hub
docker login ghcr.io  # Login to GHCR
docker push username/image:tag
docker pull username/image:tag
```

---

# UNIT 3: MICROSERVICES WITH DOCKER COMPOSE

## 3.1 Microservices Architecture

### Need for Microservices
- **Scalability:** Scale individual components independently
- **Isolation:** Failure in one service doesn't crash others
- **Agility:** Faster development, deployment cycles
- **Technology diversity:** Each service can use different tech stack

### Monolithic vs Microservices
| Aspect | Monolithic | Microservices |
|--------|-----------|---------------|
| Structure | Single codebase | Multiple services |
| Deployment | One unit | Independent |
| Scaling | Scale entire app | Scale individual services |
| Development | Single team | Multiple teams |
| Database | Single DB | Database per service |

### API Gateway
- Single entry point for all microservices
- Handles: Routing, Authentication, Rate limiting, Load balancing

## 3.2 Docker Compose

### YAML Structure
```yaml
version: '3.8'
services:
  web:
    build: .
    ports:
      - "5000:5000"
    environment:
      - DB_HOST=db
  db:
    image: postgres:13
    volumes:
      - pgdata:/var/lib/postgresql/data

volumes:
  pgdata:
```

### Key Fields
- **version:** Compose file format version
- **services:** Container definitions
- **volumes:** Named volumes
- **networks:** Custom networks
- **environment:** Environment variables
- **build:** Build context for Dockerfile
- **image:** Pre-built image to use
- **depends_on:** Service dependency ordering

### Common Commands
```bash
docker-compose up        # Start all services
docker-compose up -d     # Start in detached mode
docker-compose down      # Stop and remove containers
docker-compose ps        # List services
docker-compose logs      # View logs
docker-compose build     # Rebuild images
```

### Example: WordPress + MySQL
```yaml
version: '3.8'
services:
  db:
    image: mysql:8
    environment:
      MYSQL_ROOT_PASSWORD: rootpass
      MYSQL_DATABASE: wordpress
      MYSQL_USER: wpuser
      MYSQL_PASSWORD: wppass
    volumes:
      - db_data:/var/lib/mysql

  wordpress:
    depends_on:
      - db
    image: wordpress:latest
    ports:
      - "8000:80"
    environment:
      WORDPRESS_DB_HOST: db
      WORDPRESS_DB_USER: wpuser
      WORDPRESS_DB_PASSWORD: wppass
      WORDPRESS_DB_NAME: wordpress

volumes:
  db_data:
```

### Example: Node.js + MongoDB
```yaml
services:
  app:
    build: .
    ports:
      - "3000:3000"
    environment:
      MONGO_URI: mongodb://mongo:27017/myapp
  mongo:
    image: mongo:6
    volumes:
      - mongo_data:/data/db

volumes:
  mongo_data:
```

### Example: Java Spring Boot + PostgreSQL
```yaml
services:
  backend:
    build: .
    ports:
      - "8080:8080"
    environment:
      SPRING_DATASOURCE_URL: jdbc:postgresql://db:5432/mydb
  db:
    image: postgres:15
    environment:
      POSTGRES_DB: mydb
      POSTGRES_PASSWORD: secret
```

---

# UNIT 4: MAVEN BUILD AUTOMATION

## 4.1 Why Build Tools Exist

### Problems Solved by Automated Builds
1. **Manual Compilation Pain** — Remembering exact javac commands, classpaths
2. **Dependency Hell** — JAR version conflicts, missing libraries
3. **Inconsistent Builds** — "Works on my machine" syndrome
4. **Repetitive Tasks** — Testing, packaging, deploying manually

## 4.2 Project Object Model (POM)

### POM Elements
```xml
<project>
  <groupId>com.example</groupId>       <!-- Unique org identifier -->
  <artifactId>my-app</artifactId>       <!-- Project/module name -->
  <version>1.0.0-SNAPSHOT</version>    <!-- Version (-SNAPSHOT = in development) -->
  <packaging>jar</packaging>            <!-- jar, war, pom -->
  <dependencies>...</dependencies>      <!-- Library declarations -->
  <build>...</build>                    <!-- Plugin config, source dirs -->
  <profiles>...</profiles>              <!-- Environment-specific configs -->
</project>
```

### Standard Maven Directory Structure
```
my-project/
├── pom.xml
└── src/
    ├── main/
    │   ├── java/com/example/    ← Production Java source
    │   └── resources/           ← Config files
    └── test/
        ├── java/                ← Test classes
        └── resources/           ← Test config files
target/                          ← Generated output
```

## 4.3 Build Lifecycle Phases

Maven's three built-in lifecycles: **default**, **clean**, **site**

### Default Lifecycle (Order)
| Phase | Description |
|-------|-------------|
| 1. **validate** | Check project is correct & all required info available |
| 2. **compile** | Compile source code → `.class` files |
| 3. **test** | Run unit tests (JUnit) |
| 4. **package** | Bundle compiled code → JAR/WAR |
| 5. **verify** | Integration checks for quality criteria |
| 6. **install** | Install artifact into local repo (`~/.m2`) |
| 7. **deploy** | Copy final artifact to remote repository |

**Each phase triggers all previous phases automatically!**

### Commands
```bash
mvn compile     # Compile only
mvn test        # Compile + Test
mvn package     # Compile + Test + Package
mvn install     # All of the above + Install to local repo
mvn deploy      # All of the above + Deploy to remote repo
mvn clean       # Clean target directory
mvn clean install  # Clean + Full build
```

## 4.4 Parent POM

Centralizing configuration across multi-module projects.

**Key Benefits:**
- Centralized dependency version management
- Shared plugin configuration
- Consistent build behavior
- Single place to update versions

**Example: Spring Boot Parent POM**
```xml
<parent>
  <groupId>org.springframework.boot</groupId>
  <artifactId>spring-boot-starter-parent</artifactId>
  <version>3.2.0</version>
  <relativePath/>
</parent>
```

## 4.5 Dependency Scope

| Scope | Compile | Test | Runtime | Description |
|-------|---------|------|---------|-------------|
| **compile** | ✅ | ✅ | ✅ | Default. Available everywhere |
| **provided** | ✅ | ✅ | ❌ | Available at compile/test only. Tomcat provides at runtime |
| **runtime** | ❌ | ✅ | ✅ | Not needed at compile, needed at runtime (JDBC drivers) |
| **test** | ❌ | ✅ | ❌ | Only for test (JUnit, Mockito) |
| **system** | ✅ | ✅ | ❌ | Like provided but explicit path. Not portable |
| **import** | – | – | – | Only for `<dependencyManagement>`. Imports BOM |

## 4.6 Transitive Dependencies & Version Conflicts

**Transitive Dependencies:** When A→B, Maven pulls in B's dependencies (B→C, C→D...)

**Conflict Resolution — Nearest Wins:** Maven picks version closest to project root in dependency tree (shortest path)

**Solutions for conflicts:**
1. Explicit direct dependency declaration
2. `<exclusions>` to remove unwanted transitive deps
3. `<dependencyManagement>` to enforce version
4. BOM (Bill of Materials) import

```xml
<!-- Excluding a transitive dependency -->
<dependency>
  <groupId>com.example</groupId>
  <artifactId>lib-a</artifactId>
  <exclusions>
    <exclusion>
      <groupId>com.bad</groupId>
      <artifactId>old-lib</artifactId>
    </exclusion>
  </exclusions>
</dependency>

<!-- Force version via dependencyManagement -->
<dependencyManagement>
  <dependencies>
    <dependency>
      <groupId>com.example</groupId>
      <artifactId>conflicting-lib</artifactId>
      <version>2.0</version>
    </dependency>
  </dependencies>
</dependencyManagement>
```

## 4.7 Maven Plugins & Execution

Plugins bind **goals** to **lifecycle phases**. A goal is a specific task.

### Compiler Plugin
Controls Java source/target version:
```xml
<plugin>
  <groupId>org.apache.maven.plugins</groupId>
  <artifactId>maven-compiler-plugin</artifactId>
  <configuration>
    <source>17</source>
    <target>17</target>
  </configuration>
</plugin>
```

### Surefire Plugin (Unit Testing)
```xml
<plugin>
  <artifactId>maven-surefire-plugin</artifactId>
  <version>3.1.2</version>
  <configuration>
    <includes>**/*Test.java</includes>
  </configuration>
</plugin>
```
Skip tests: `mvn package -DskipTests`

### Shade Plugin (Uber JAR)
Creates a single "fat" JAR with all dependencies merged:
```xml
<plugin>
  <groupId>org.apache.maven.plugins</groupId>
  <artifactId>maven-shade-plugin</artifactId>
  <version>3.5.0</version>
  <executions>
    <execution>
      <phase>package</phase>
      <goals><goal>shade</goal></goals>
      <configuration>
        <transformers>
          <transformer impl="ManifestResourceTransformer">
            <mainClass>com.App</mainClass>
          </transformer>
        </transformers>
      </configuration>
    </execution>
  </executions>
</plugin>
```

### Maven Wrapper (mvnw)
**Problem:** Different devs/CI servers have different Maven versions
**Solution:** `mvnw` script auto-downloads and uses exact Maven version

```bash
# Generate wrapper
mvn wrapper:wrapper

# Use wrapper (no Maven pre-installation needed)
./mvnw clean package
./mvnw spring-boot:run
```

## 4.8 Maven & Docker Integration

### Integration Overview
1. `mvn package` → Produces application JAR
2. Write Dockerfile → Multi-stage: base image → copy JAR → ENTRYPOINT
3. `dockerfile-maven-plugin` → Runs `docker build` as part of `mvn install`
4. Plugin tags image with project version automatically
5. `mvn deploy` → Pushes image to Docker Hub/ECR/GCR

### Using Maven Image in Docker
```bash
# Pull Maven image
docker pull maven:3.9.10-eclipse-temurin-17

# Run Maven inside container
docker run --rm -it -v ${PWD}:/app -w /app maven:3.9.10-eclipse-temurin-17 \
  mvn archetype:generate \
  -DgroupId=com.example \
  -DartifactId=demo-app \
  -DarchetypeArtifactId=maven-archetype-quickstart \
  -DinteractiveMode=false
```

### dockerfile-maven-plugin (Spotify)
```xml
<plugin>
  <groupId>com.spotify</groupId>
  <artifactId>dockerfile-maven-plugin</artifactId>
  <version>1.4.13</version>
  <configuration>
    <repository>docker-maven-demo</repository>
    <tag>${project.version}</tag>
  </configuration>
</plugin>
```

**Build & push via Maven:**
```bash
mvn dockerfile:build
mvn dockerfile:push
```

---

# UNIT 5: CONTINUOUS INTEGRATION (CI) WITH GITHUB ACTIONS

## 5.1 Introduction to GitHub Actions

**GitHub Actions** is a CI/CD platform that allows you to automate workflows directly inside your GitHub repository.

**What it helps with:**
- Building code
- Running tests
- Deploying applications
- Automating repetitive development tasks

> *Analogy: Think of GitHub Actions like a smart assistant that automatically performs tasks whenever something happens in your repository.*

## 5.2 Understanding Workflow Automation

### What is a Workflow?
- An automated process defined in a **YAML file**
- Stored inside `.github/workflows/`
- Contains one or more **jobs**
- Each job has **steps** (commands/actions)

### Basic Workflow Structure
```yaml
name: My First Workflow
on: push
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v3
      - name: Run a script
        run: echo "Hello World"
```

### Components
- **Event (on)** → When to run
- **Jobs** → What to do
- **Steps** → How to do it
- **Actions** → Predefined reusable tasks

## 5.3 Events & Triggers

### Events
| Event | Description |
|-------|-------------|
| `push` | When code is pushed |
| `pull_request` | When PR is created/updated |
| `workflow_dispatch` | Manual trigger |
| `schedule` | Runs on cron timing |
| `issues` | When issue is created/updated |

### Trigger Filters
```yaml
# Branch-based trigger
on:
  push:
    branches: [main, dev]

# Path-based trigger
on:
  push:
    paths:
      - 'src/**'

# Tag-based trigger
on:
  push:
    tags:
      - 'v1.*'

# Schedule (cron) trigger
on:
  schedule:
    - cron: '0 0 * * *'   # Every day at midnight

# Manual trigger
on:
  workflow_dispatch:
```

## 5.4 Key Components

### Jobs
- A workflow contains multiple jobs
- Jobs run **in parallel** by default
```yaml
jobs:
  build:
    runs-on: ubuntu-latest
  test:
    runs-on: ubuntu-latest
```

### Steps
- Each job has sequential steps
```yaml
steps:
  - name: Step 1
    run: echo "Hello"
  - name: Step 2
    run: echo "World"
```

### Actions (Reusable Components)
- Reusable units of code
```yaml
- uses: actions/checkout@v3           # Checkout code
- uses: actions/setup-java@v3         # Set up Java
- uses: actions/setup-node@v3         # Set up Node.js
```

### Runners
- **GitHub-hosted:** Ubuntu, Windows, macOS
- **Self-hosted:** Your own servers

## 5.5 Matrix Strategies

Run the same job with multiple configurations in parallel:
```yaml
jobs:
  test:
    runs-on: ubuntu-latest
    strategy:
      matrix:
        node-version: [14, 16, 18]
    steps:
      - uses: actions/setup-node@v3
        with:
          node-version: ${{ matrix.node-version }}
      - run: npm test
```

## 5.6 Complete CI Workflow Examples

### Java CI Pipeline
```yaml
name: Java CI Pipeline
on:
  push:
    branches: [main]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - name: Set up Java
        uses: actions/setup-java@v3
        with:
          java-version: '17'
      - name: Build with Maven
        run: mvn clean install
```

### Python Docker CI/CD Pipeline
```yaml
name: CI-CD Pipeline
on:
  push:
    branches:
      - main
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout Code
        uses: actions/checkout@v4
      - name: Build Docker Image
        run: docker build -t my-docker-app .
      - name: List Docker Images
        run: docker images
```

### Node.js CI
```yaml
name: Node CI
on:
  push:
    branches:
      - main
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Install dependencies
        run: npm install
      - name: Run tests
        run: npm test
```

## 5.7 Workflow Directory Structure
```
repository/
├── .github/
│   └── workflows/
│       ├── build.yml
│       ├── deploy.yml
├── src/
├── tests/
└── README.md
```

---

# UNIT 6: CI/CD WITH JENKINS

## 6.1 What is Jenkins?

**Jenkins** is an open-source automation server that helps automate building, testing, and deploying software, facilitating **Continuous Integration (CI)** and **Continuous Delivery (CD)**.

### Key Features
- CI and CD — automatic building, testing, deployment
- 1800+ plugins for customization
- Pipelines as Code (Declarative & Scripted)
- Works across different OS platforms
- Integrates with Git, Docker, Maven, Kubernetes, etc.

## 6.2 Jenkins Architecture (Master/Agent Model)

| Term | Description |
|------|-------------|
| **Job/Project** | A task to execute (e.g., build a project) |
| **Build** | A single run of a job |
| **Node** | A machine where Jenkins runs jobs (Master or Agent/Slave) |
| **Pipeline** | A series of steps defining CI/CD workflow |
| **Plugin** | Add-on for extra functionality |

## 6.3 Jenkins Setup Basics

```bash
# Download and run Jenkins
java -jar jenkins.war

# Or run via Docker
docker run -p 8080:8080 -p 50000:50000 jenkins/jenkins:lts
```

### Setup Steps
1. Download from jenkins.io
2. Run with Java (`java -jar jenkins.war`) or Docker
3. Access Dashboard at `http://localhost:8080`
4. Enter admin password (found in Jenkins home folder)
5. Install suggested plugins
6. Create first admin user

## 6.4 Creating Your First Job

1. Click **"New Item"**
2. Enter a name, choose **"Freestyle project"**
3. Configure:
   - **Source Code Management:** Git
   - **Build Trigger:** Poll SCM or on Push
   - **Build:** Execute Shell or Invoke Maven
4. Click **"Save"** → **"Build Now"**

## 6.5 Jenkins Pipelines

**Pipeline** is a set of automated steps that Jenkins follows to build, test, and deploy.

### Why Use Pipelines?
- Automate entire CI/CD process
- Make builds repeatable and version-controlled
- Run complex workflows (parallel stages, conditional logic)
- **"Pipeline as Code"** — define builds in code

### Two Types of Pipelines
| Type | Description |
|------|-------------|
| **Declarative** | Easier to read/write. Structured. Recommended for beginners |
| **Scripted** | More flexible, uses Groovy scripting. For advanced users |

### Declarative Pipeline Syntax
```groovy
pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/user/repo.git'
            }
        }
        stage('Build') {
            steps {
                sh 'mvn clean package'
            }
        }
        stage('Test') {
            steps {
                sh 'mvn test'
            }
        }
        stage('Deploy') {
            steps {
                sh 'docker build -t myapp .'
            }
        }
    }
}
```

### Jenkinsfile Structure
```groovy
pipeline {
    agent any
    tools {
        maven 'Maven'
    }
    stages {
        stage('Build') {
            steps {
                bat 'mvn clean package'  // Windows
                // sh 'mvn clean package'  // Linux/Mac
            }
        }
    }
}
```

### Full CI/CD Pipeline Example
```groovy
pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git 'https://github.com/user/neww.git'
            }
        }
        stage('Build') {
            steps {
                sh 'mvn clean package'
            }
        }
        stage('Test') {
            steps {
                sh 'mvn test'
            }
        }
        stage('Docker Build') {
            steps {
                sh 'docker build -t myapp .'
            }
        }
    }
}
```

## 6.6 Plugins in Jenkins

**Plugins** are add-ons that extend Jenkins' core functionality.

**Important Plugins:**
- Git, GitHub Integration
- Docker Pipeline, Docker Commons
- Maven Integration
- Slack Notification
- HTML Publisher
- Pipeline: REST API
- SSH Agent
- Role-based Authorization Strategy

**How to Install:**
1. Jenkins Dashboard → Manage Jenkins
2. Manage Plugins
3. Search in Available tab
4. Install without restart / Download now and install after restart

## 6.7 Jenkins & Maven Integration
- Maven installation in Jenkins (Global Tool Configuration)
- Running Maven builds in pipelines
- Code coverage & test reports (Surefire plugin)

## 6.8 Jenkins & Docker Integration
- Building Docker images using Jenkins
- Docker inside Jenkins agents
- Using Docker plugins
- Publishing images to Docker Hub/GHCR

## 6.9 Jenkins & GitHub Integration
- Triggering builds: Poll SCM, Webhook
- Multi-branch pipelines
- Pipeline libraries

---

# PRACTICAL TASKS REFERENCE (FOR VIVA & EXAM)

## Basic Docker Commands

```bash
docker --version              # Check Docker version
docker info                   # Detailed system info
docker images                 # List all images
docker pull <image>           # Download image from registry
docker ps                     # List running containers
docker ps -a                  # List ALL containers (running + stopped)
docker logs <container>       # View container logs
docker logs -f <container>    # Follow logs in real time
```

## docker run Options

| Option | Description | Example |
|--------|-------------|---------|
| `-it` | Interactive terminal mode | `docker run -it ubuntu bash` |
| `-d` | Detached (background) mode | `docker run -d nginx` |
| `--name` | Name the container | `--name my_app` |
| `--rm` | Auto-remove when exits | `--rm` |
| `-p` | Port mapping (host:container) | `-p 8080:80` |
| `-e / --env` | Environment variable | `-e APP_ENV=production` |
| `-v` | Mount volume/bind mount | `-v /data:/app/data` |

## Task 1: Ubuntu Container with Environment Variable

```bash
# Run Ubuntu with env variable
docker run -it --name college_env -e COLLEGE=CSE ubuntu bash

# Inside container, check variable
echo $COLLEGE           # Output: CSE

# Exit and check
exit
docker ps -a            # Shows Exited status

# Cleanup
docker stop college_env
docker rm college_env
```

## Task 2: MongoDB with Port Mapping

```bash
docker run -d --name DB-app -p 80:8082 mongo
docker ps                # Verify running
docker stop DB-app
docker rm DB-app
```

## Task 3: Deploy Web Page with httpd

```bash
# Start Apache HTTP server
docker run -d --name simple_web -p 8080:80 httpd

# Add custom HTML page
docker exec simple_web sh -c \
  "echo '<h1>Welcome to Docker Web Deployment</h1>' > /usr/local/apache2/htdocs/index.html"

# Verify
curl http://localhost:8080    # Shows: <h1>Welcome to Docker Web Deployment</h1>

# Cleanup
docker stop simple_web
docker rm simple_web
```

## Task 4: docker run with Multiple Flags

```bash
docker run -it --name my_app -e APP_ENV=production -v /app/data:/data ubuntu bash
# -it → interactive terminal
# --name my_app → name the container
# -e APP_ENV=production → set environment variable
# -v /app/data:/data → bind mount host /app/data to container /data
```

## Task 5: Container Interaction (File & Directory Management)

```bash
# Start container in background
docker run -dit --name interaction_container ubuntu bash

# Create directory and files
docker exec interaction_container mkdir /project
docker exec interaction_container sh -c \
  "echo 'This is our container interaction with our host machine.' > /project/report.txt"

# Verify content
docker exec interaction_container cat /project/report.txt

# Copy file from container to host
docker cp interaction_container:/project/report.txt ~/Desktop/report.txt

# Create another file
docker exec interaction_container sh -c \
  "echo 'These are project notes.' > /project/notes.txt"

# List files
docker exec interaction_container ls -l /project

# Cleanup
docker stop interaction_container
docker rm interaction_container
```

## Task 6: Docker Volume Data Persistence

```bash
# Create volume
docker volume create projectdata
docker volume ls
docker volume inspect projectdata

# Use volume with container
docker run -dit --name project_container -v projectdata:/app/data ubuntu bash

# Write data
docker exec project_container sh -c \
  "echo 'This is my first volume.' > /app/data/report.txt"

# Stop and remove container (data persists in volume)
docker stop project_container
docker rm project_container

# Create new container with same volume
docker run -dit --name project_container_new -v projectdata:/app/data ubuntu bash

# Verify data persists!
docker exec project_container_new cat /app/data/report.txt
# Output: This is my first volume.

# Cleanup
docker stop project_container_new
docker rm project_container_new
docker volume rm projectdata
```

## Task 7: University Portal Deployment

```bash
# Create volume and run container with env variable
docker volume create portaldata
docker run -d --name college_portal -p 8080:80 -e ENV=production \
  -v portaldata:/usr/local/apache2/htdocs httpd

# Deploy portal page
docker exec college_portal sh -c \
  "echo '<h1>College Portal</h1><p>Environment: production</p>' > /usr/local/apache2/htdocs/index.html"

# Verify
curl http://localhost:8080
# Output: <h1>College Portal</h1><p>Environment: production</p>

# Check logs
docker logs college_portal

# Cleanup
docker stop college_portal
docker rm college_portal
docker volume rm portaldata
```

## Task 8: MySQL Container Debugging

```bash
# Run MySQL with all required env variables
docker run -d --name mysql_debug \
  -e MYSQL_ROOT_PASSWORD=rootpass \
  -e MYSQL_DATABASE=college_db \
  -e MYSQL_USER=college_user \
  -e MYSQL_PASSWORD=college_pass \
  -p 3307:3306 \
  mysql:8

# Debug: Check logs
docker logs mysql_debug

# Debug: Execute MySQL commands inside container
docker exec -it mysql_debug mysql -u root -prootpass -e "SHOW DATABASES;"

# Cleanup
docker stop mysql_debug
docker rm mysql_debug
```

## Task 9: Start/Stop Containers & Logs

```bash
# Start nginx with env variable
docker run -d --name nginx_env -e ENV_MODE=production nginx

# View logs
docker logs nginx_env
docker logs -f nginx_env   # Follow in real time

# Start and stop containers
docker start web_server
docker stop web_server

# Practice Questions:
# Q1: Run nginx with ENV_MODE=production
docker run -d --name nginx_env -e ENV_MODE=production nginx

# Q2: View logs with follow mode
docker logs -f my_app

# Q3: Start and stop web_server
docker start web_server
docker stop web_server
```

## Task 10: Building Custom Images

```bash
# Build Apache image
docker build -t my-apache2 .
docker run -dit --name my-running-app2 -p 8082:80 my-apache2

# Build Nginx image
docker build -t some-image-nginx .
docker run --name some-nginx -p 8080:80 -d some-image-nginx

# Build Python Flask app
docker build -t my-docker-app .
docker run -p 5000:5000 my-docker-app

# Build Java Maven app
docker build -t docker-maven-demo .
docker run docker-maven-demo
```

## Task 11: Maven + Docker Integration

```bash
# Pull Maven image
docker pull maven:3.9.10-eclipse-temurin-17

# Create Maven project using Docker
docker run --rm -it -v ${PWD}:/app -w /app maven:3.9.10-eclipse-temurin-17 \
  mvn archetype:generate \
  -DgroupId=com.example \
  -DartifactId=demo-app \
  -DarchetypeArtifactId=maven-archetype-quickstart \
  -DinteractiveMode=false

# Build Maven project using Docker
cd demo-app
docker run --rm -it -v ${PWD}:/app -w /app maven:3.9.10-eclipse-temurin-17 \
  mvn clean install

# Build Docker image from Maven (using plugin)
mvn dockerfile:build
mvn dockerfile:push
```

## Task 12: Environment Variables (Passing to Containers)

```bash
# Single env variable
docker run -it -e MY_NAME=Harpreet ubuntu bash
# Inside: echo $MY_NAME → Harpreet

# Multiple env variables
docker run -e APP_ENV=production -e APP_VERSION=1.0 nginx

# MySQL container (many env vars)
docker run -d \
  -e MYSQL_ROOT_PASSWORD=root123 \
  -e MYSQL_DATABASE=college \
  -e MYSQL_USER=admin \
  -e MYSQL_PASSWORD=admin123 \
  mysql:8

# Pass from host system
export APP_PORT=8080
docker run -e APP_PORT=$APP_PORT nginx env

# Using env-file
# Create .env file:
echo "DB_HOST=localhost" > .env
echo "DB_USER=root" >> .env
echo "DB_PASS=secret" >> .env
docker run --env-file .env myapp
```

### Key Viva Questions Expected

1. **What is the difference between CMD and ENTRYPOINT?**
   - CMD can be overridden, ENTRYPOINT cannot. ENTRYPOINT is the main executable, CMD provides default args.

2. **What happens when you omit -e flags for MySQL?**
   - MySQL container will fail to start. It requires MYSQL_ROOT_PASSWORD at minimum.

3. **Why does data persist after container removal when using volumes?**
   - Volumes are managed by Docker, stored separately from container writable layer.

4. **How do containers communicate?**
   - Through Docker networks (bridge, host, overlay) or port mapping.

5. **What is Copy-on-Write?**
   - When container modifies a file, it copies it to writable layer. Original image layer unchanged.

6. **Why use -p flag?**
   - Containers run in isolated network. -p exposes container port to host so external users can access.

7. **Jenkins Pipeline vs Freestyle job?**
   - Pipeline is code-defined (Pipeline as Code), version-controlled, more complex workflows.

8. **Declarative vs Scripted Pipeline?**
   - Declarative: structured, easier, for beginners. Scripted: Groovy-based, flexible, advanced.

9. **What are GitHub Actions components?**
   - Events, Jobs, Steps, Actions, Runners.

10. **Maven default lifecycle phases?**
    - validate → compile → test → package → verify → install → deploy

---

# TOPIC-WISE MCQs

## UNIT 1: Docker Basics & Infrastructure

**Q1. Which Linux kernel feature provides process isolation in containers?**
- A) cgroups
- B) Namespaces ✅
- C) Hypervisor
- D) Init system

**Q2. What is the primary function of cgroups in Docker?**
- A) Isolate process visibility
- B) Limit and monitor resource usage ✅
- C) Manage network ports
- D) Create virtual machines

**Q3. Which namespace allows each container to have its own hostname?**
- A) PID namespace
- B) Network namespace
- C) UTS namespace ✅
- D) Mount namespace

**Q4. What is a container runtime?**
- A) A tool for writing Dockerfiles
- B) Software that creates and manages containers ✅
- C) A registry for storing images
- D) A programming language

**Q5. Which of the following is a LOW-LEVEL container runtime?**
- A) Docker Engine
- B) containerd
- C) runc ✅
- D) CRI-O

**Q6. What does PID namespace isolate?**
- A) Network interfaces
- B) Process tree (PID 1 inside container) ✅
- C) Filesystem mounts
- D) User IDs

**Q7. Which component of Docker architecture is the background service that manages containers?**
- A) Docker CLI
- B) Docker Daemon (dockerd) ✅
- C) Docker Registry
- D) Docker Compose

**Q8. What is the default Docker network driver?**
- A) Host
- B) Bridge ✅
- C) Overlay
- D) None

**Q9. Which Docker object type is used to persist data?**
- A) Container
- B) Image
- C) Volume ✅
- D) Network

**Q10. What is the Copy-on-Write mechanism used for in Docker?**
- A) Copying files between containers
- B) Efficient storage by sharing image layers ✅
- C) Writing logs
- D) Network communication

## UNIT 2: Dockerfile & Container Management

**Q11. Which Dockerfile instruction sets the base image?**
- A) BASE
- B) FROM ✅
- C) START
- D) IMAGE

**Q12. What is the difference between CMD and ENTRYPOINT?**
- A) No difference
- B) CMD can be overridden, ENTRYPOINT cannot ✅
- C) ENTRYPOINT runs first
- D) CMD runs in background

**Q13. Which Dockerfile instruction is used to set an environment variable?**
- A) SET
- B) ENV ✅
- C) EXPORT
- D) VAR

**Q14. What does the EXPOSE instruction do?**
- A) Publishes the port to the host
- B) Documents the port (metadata only) ✅
- C) Maps host port to container port
- D) Opens a network connection

**Q15. What is the purpose of .dockerignore?**
- A) Ignore errors during build
- B) Exclude files from build context ✅
- C) Skip Dockerfile instructions
- D) Ignore container logs

**Q16. Which command shows the layers of a Docker image?**
- A) docker inspect
- B) docker history ✅
- C) docker layers
- D) docker info

**Q17. What does `docker run -p 8080:80` do?**
- A) Maps host port 8080 to container port 80 ✅
- B) Maps container port 8080 to host port 80
- C) Sets environment variable
- D) Runs container in background

**Q18. Which storage type is managed by Docker?**
- A) Bind mounts
- B) Volumes ✅
- C) tmpfs
- D) All of the above (Docker manages all, but volumes are the recommended way)

**Q19. What does `docker ps -a` show?**
- A) Only running containers
- B) All containers (running + stopped) ✅
- C) Only stopped containers
- D) Container images

**Q20. Which flag removes a container automatically when it exits?**
- A) --delete
- B) --rm ✅
- C) --auto-remove
- D) --clean

## UNIT 3: Docker Compose & Microservices

**Q21. In Docker Compose, what does `depends_on` do?**
- A) Installs dependencies
- B) Controls service startup order ✅
- C) Sets environment variables
- D) Defines network dependencies

**Q22. Which file format is used by Docker Compose?**
- A) JSON
- B) YAML ✅
- C) XML
- D) TOML

**Q23. What is the main advantage of microservices over monolithic architecture?**
- A) Simpler codebase
- B) Independent scaling of services ✅
- C) Single database
- D) Easier deployment

**Q24. Which Docker Compose command starts all services in detached mode?**
- A) docker-compose start
- B) docker-compose up -d ✅
- C) docker-compose run
- D) docker-compose launch

**Q25. What is an API Gateway in microservices?**
- A) A database connection
- B) Single entry point for all services ✅
- C) A type of container
- D) A monitoring tool

## UNIT 4: Maven Build Automation

**Q26. What does POM stand for in Maven?**
- A) Project Object Model ✅
- B) Package Object Manager
- C) Project Output Module
- D) Program Object Metadata

**Q27. Which Maven lifecycle phase compiles source code?**
- A) validate
- B) compile ✅
- C) package
- D) install

**Q28. What is the default dependency scope in Maven?**
- A) test
- B) provided
- C) compile ✅
- D) runtime

**Q29. How does Maven resolve version conflicts in transitive dependencies?**
- A) Latest version wins
- B) Nearest wins (shortest path) ✅
- C) First declared wins
- D) Random selection

**Q30. What is an Uber JAR?**
- A) A JAR with source code only
- B) A JAR containing all dependencies merged ✅
- C) A JAR without a manifest
- D) A compressed JAR

**Q31. Which Maven plugin runs unit tests?**
- A) Compiler plugin
- B) Surefire plugin ✅
- C) Shade plugin
- D) JAR plugin

**Q32. What does `mvn clean install` do?**
- A) Cleans and installs without compiling
- B) Cleans target, runs all phases through install ✅
- C) Only installs to local repo
- D) Cleans and packages

**Q33. What is the purpose of Maven Wrapper (mvnw)?**
- A) Wraps Maven in a Docker container
- B) Ensures consistent Maven version across environments ✅
- C) Speeds up Maven builds
- D) Wraps JAR files

**Q34. Which scope is suitable for JUnit dependency?**
- A) compile
- B) provided
- C) test ✅
- D) runtime

**Q35. What does the Shade plugin do?**
- A) Compiles source code
- B) Creates an Uber JAR ✅
- C) Runs unit tests
- D) Deploys to registry

## UNIT 5: GitHub Actions

**Q36. Where are GitHub Actions workflow files stored?**
- A) /src/workflows/
- B) /.github/workflows/ ✅
- C) /actions/
- D) /ci-cd/

**Q37. What format are GitHub Actions workflow files written in?**
- A) JSON
- B) YAML ✅
- C) XML
- D) Properties file

**Q38. What component in GitHub Actions defines WHEN a workflow runs?**
- A) Jobs
- B) Steps
- C) Events ✅
- D) Actions

**Q39. How do jobs in a workflow run by default?**
- A) Sequentially
- B) In parallel ✅
- C) Manually
- D) Randomly

**Q40. What is a runner in GitHub Actions?**
- A) A person who reviews code
- B) A server that executes workflows ✅
- C) A type of event
- D) A testing framework

**Q41. What does `cron: '0 0 * * *'` mean?**
- A) Every hour
- B) Every day at midnight ✅
- C) Every minute
- D) Every Monday

**Q42. Which feature runs the same job with multiple configurations?**
- A) Steps
- B) Matrix strategy ✅
- C) Parallel jobs
- D) Reusable actions

**Q43. What is a GitHub Action?**
- A) A step in a workflow
- B) A reusable unit of code ✅
- C) A type of runner
- D) An event trigger

**Q44. Which GitHub-hosted runner OS types are available?**
- A) Only Linux
- B) Linux and Windows only
- C) Linux, Windows, macOS ✅
- D) Only Ubuntu

**Q45. What is the correct order of execution in a workflow?**
- A) Steps → Jobs → Workflow
- B) Workflow → Jobs → Steps ✅
- C) Jobs → Workflow → Steps
- D) Steps → Workflow → Jobs

## UNIT 6: Jenkins CI/CD

**Q46. What is Jenkins?**
- A) A cloud hosting platform
- B) An open-source automation server ✅
- C) A programming language
- D) A database management system

**Q47. What is the default port for Jenkins?**
- A) 80
- B) 8080 ✅
- C) 3000
- D) 443

**Q48. Which of the following is NOT a Jenkins pipeline type?**
- A) Declarative
- B) Scripted
- C) Functional ✅
- D) Both A and B are valid

**Q49. What is a Jenkins plugin?**
- A) A standalone application
- B) An add-on that extends Jenkins functionality ✅
- C) A Docker container
- D) A build tool

**Q50. What does "Pipeline as Code" mean in Jenkins?**
- A) Writing pipelines in a compiled language
- B) Defining build/deploy process as code in a Jenkinsfile ✅
- C) Using a visual pipeline editor
- D) Running pipelines in containers

**Q51. In Jenkins, what is a "Node"?**
- A) A folder in Jenkins
- B) A machine that runs Jenkins jobs ✅
- C) A type of job
- D) A pipeline stage

**Q52. Which Jenkins pipeline syntax is recommended for beginners?**
- A) Scripted
- B) Declarative ✅
- C) Groovy
- D) YAML

**Q53. How do you skip tests in a Maven build within Jenkins?**
- A) mvn package --skip-tests
- B) mvn package -DskipTests ✅
- C) mvn package -notest
- D) mvn package -excludeTests

**Q54. What is a Jenkinsfile?**
- A) A configuration file for Jenkins server
- B) A file defining pipeline as code ✅
- C) A log file for builds
- D) A plugin configuration

**Q55. Which command starts Jenkins?**
- A) jenkins start
- B) java -jar jenkins.war ✅
- C) run jenkins
- D) docker start jenkins

---

# RANDOM MCQs (Mixed from All Units)

**Q56. Which Docker command downloads an image from a registry?**
- A) docker download
- B) docker pull ✅
- C) docker get
- D) docker fetch

**Q57. What happens if a MySQL container is started without MYSQL_ROOT_PASSWORD?**
- A) It runs with default password
- B) It fails to start ✅
- C) It prompts for password
- D) It uses a random password

**Q58. In GitHub Actions, what does `workflow_dispatch` do?**
- A) Runs on code push
- B) Allows manual trigger from GitHub UI ✅
- C) Runs on schedule
- D) Triggers on pull request

**Q59. Which Maven phase comes after `test`?**
- A) compile
- B) package ✅
- C) install
- D) deploy

**Q60. What is the purpose of `docker exec`?**
- A) To execute a new container
- B) To run commands inside a running container ✅
- C) To execute Docker commands
- D) To stop a container

**Q61. Which of the following is a high-level container runtime?**
- A) runc
- B) containerd ✅
- C) Linux kernel
- D) Namespace

**Q62. What is the purpose of a Parent POM in Maven?**
- A) To run parent project
- B) To centralize configuration across modules ✅
- C) To create child projects
- D) To deploy parent artifact

**Q63. In Docker Compose, what does `docker-compose down` do?**
- A) Stops and removes containers ✅
- B) Only stops containers
- C) Deletes images
- D) Pauses services

**Q64. Which command shows running containers?**
- A) docker list
- B) docker ps ✅
- C) docker status
- D) docker show

**Q65. What is the default network type when no network is specified for a container?**
- A) Host
- B) Bridge ✅
- C) Overlay
- D) None

**Q66. What does the `-it` flag in docker run do?**
- A) Runs in background
- B) Interactive terminal mode ✅
- C) Sets image tag
- D) Mounts volume

**Q67. How are Docker image layers shared between containers?**
- A) Each container copies all layers
- B) Layers are shared via Copy-on-Write ✅
- C) Layers are merged
- D) Layers are compressed

**Q68. What does Jenkins use to connect to GitHub for automatic builds?**
- A) Email notifications
- B) Webhooks or Poll SCM ✅
- C) Direct database connection
- D) FTP

**Q69. In Maven, what does `<scope>provided</scope>` mean?**
- A) Dependency is bundled with the app
- B) Dependency is provided by the runtime environment ✅
- C) Dependency is only for tests
- D) Dependency is optional

**Q70. Which GitHub Actions trigger runs a workflow at scheduled intervals?**
- A) push
- B) pull_request
- C) schedule ✅
- D) workflow_dispatch

**Q71. What is Docker Hub?**
- A) A Docker training platform
- B) A public registry for Docker images ✅
- C) A Docker networking tool
- D) A Docker monitoring service

**Q72. Which plugin in Jenkins is used to run Maven builds?**
- A) Git plugin
- B) Maven Integration plugin ✅
- C) Docker plugin
- D) Pipeline plugin

**Q73. What is the correct syntax for a Declarative Pipeline in Jenkins?**
- A) pipeline { agent any stages { stage('Build') { steps { ... } } } } ✅
- B) job { build { ... } }
- C) workflow { run { ... } }
- D) ci_cd { pipeline { ... } }

**Q74. In GitHub Actions, what does `${{ matrix.node-version }}` do?**
- A) Sets a fixed version
- B) References the current matrix configuration value ✅
- C) Defines a new matrix
- D) Creates a variable

**Q75. What is the purpose of `docker volume inspect`?**
- A) To view volume contents
- B) To get detailed metadata about a volume ✅
- C) To create a new volume
- D) To delete a volume

**Q76. Which Maven dependency scope is appropriate for a JDBC driver?**
- A) compile
- B) provided
- C) runtime ✅
- D) test

**Q77. What does a Dockerfile ENTRYPOINT instruction define?**
- A) Default command (overridable)
- B) Main executable for the container ✅
- C) Working directory
- D) Port to expose

**Q78. In Docker Compose, what is the difference between `build` and `image` fields?**
- A) No difference
- B) `build` uses a Dockerfile, `image` uses a pre-built image ✅
- C) `image` is for build only
- D) `build` pulls from registry

**Q79. What happens if a workflow step fails in GitHub Actions?**
- A) The next step still runs
- B) The job stops execution ✅
- C) The workflow restarts
- D) An email is sent

**Q80. Which of the following is NOT a Docker networking driver?**
- A) bridge
- B) host
- C) tunnel ✅
- D) overlay

---

# QUICK REFERENCE CARDS (For Exam Day)

## Docker Commands Cheat Sheet
```
docker --version           # Version info
docker info                # System info
docker images              # List images
docker pull <image>        # Download image
docker push <image>        # Upload image
docker run <image>         # Create & start container
docker ps                  # Running containers
docker ps -a               # All containers
docker stop <container>    # Stop container
docker start <container>   # Start stopped container
docker rm <container>      # Remove container
docker rmi <image>         # Remove image
docker exec -it <id> bash  # Execute in container
docker logs <container>    # View logs
docker cp <id>:<path> .    # Copy from container
docker build -t <tag> .    # Build image
docker history <image>     # Image layers
docker volume create <name># Create volume
docker network ls          # List networks
```

## Docker Run Flags
```
-it    Interactive terminal
-d     Detached (background)
--name Name the container
-p     Port mapping host:container
-e     Environment variable
-v     Mount volume
--rm   Auto-remove on exit
--env-file  Load env from file
```

## Maven Commands
```
mvn compile            # Compile source
mvn test               # Run tests
mvn package            # Create JAR/WAR
mvn install            # Install to local repo
mvn deploy             # Deploy to remote repo
mvn clean              # Clean target dir
mvn clean install      # Full rebuild
mvn package -DskipTests  # Skip tests
mvn dependency:tree    # Show dependency tree
```

## GitHub Actions Quick Reference
```yaml
# Minimal workflow
name: CI
on: push
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - run: echo "Hello"
```

## Jenkins Pipeline Quick Reference
```groovy
pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'mvn clean package'
            }
        }
    }
}
```

## Docker Compose Quick Reference
```yaml
version: '3.8'
services:
  app:
    build: .
    ports:
      - "3000:3000"
```

---
*Created for INT332 End Term Exam Preparation*
*Subjects: Docker, Maven, GitHub Actions, Jenkins, DevOps*
