


## undefined is because the statemnet is not returning any value.

---
    > var q = 1
    undefined
    >

## RPEL CMD
.break    Sometimes you get stuck, this gets you out
.clear    Alias for .break
.editor   Enter editor mode
.exit     Exit the REPL
.help     Print this help message
.load     Load JS from a file into the REPL session
.save     Save all evaluated commands in this REPL session to a file

# modules


<!-- basic form input and submit it to backend -->
<!-- create a file and then add data in the file be it txt or json -->
<!-- url encoded -->
<!-- button to read the data then →

docker 
docker ps
docker exec -it mongo-local mongosh – for monogo shell
docker exec -it mongo-local bash – for bash 
docker run -d --name mongo-local -p 27017:27017 mongo:7 – to run docker local

# Check Docker version
docker --version

# Check Docker status
systemctl status docker

# Start Docker service
sudo systemctl start docker

# Stop Docker service
sudo systemctl stop docker

# Enable Docker at boot
sudo systemctl enable docker

Containers
# List running containers
docker ps

# List all containers (running + stopped)
docker ps -a

# Run a container (example: MongoDB)
docker run -d --name mongo-local -p 27017:27017 mongo:7

# Stop a container
docker stop mongo-local

# Start a stopped container
docker start mongo-local

# Restart a container
docker restart mongo-local

# Remove a stopped container
docker rm mongo-local

# Force stop + remove
docker rm -f mongo-local

Execute Commands Inside Container

# Open bash inside running container
docker exec -it mongo-local bash

# Open mongosh inside running MongoDB container
docker exec -it mongo-local mongosh

Images
# List images
docker images

# Pull an image
docker pull mongo:7

# Remove an image
docker rmi mongo:7

# Remove all unused images
docker image prune

Volume
# List volumes
docker volume ls

# Create volume
docker volume create mongo_data

# Remove volume
docker volume rm mongo_data

# Remove unused volumes
docker volume prune

Network

# List networks
docker network ls

# Inspect network
docker network inspect bridge

Logs & Info
# View container logs
docker logs mongo-local

# Follow logs live
docker logs -f mongo-local

# Detailed container info
docker inspect mongo-local

Cleanup
# Remove stopped containers
docker container prune

# Remove everything unused (containers, images, volumes, networks)
docker system prune

MongoDB-specific (Local)
# Run MongoDB with persistent storage
docker run -d \
  --name mongo-local \
  -p 27017:27017 \
  -v mongo_data:/data/db \
  mongo:7

# Connect to local MongoDB
docker exec -it mongo-local mongosh
