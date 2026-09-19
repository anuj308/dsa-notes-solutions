# System Design: From Fundamentals to Production

## Preface

System design is the discipline of turning product requirements, workloads, and operational constraints into an architecture that can evolve predictably. The objective is not to collect fashionable components. It is to understand why each component exists, what pressure it removes, what guarantees it provides, and what new costs or failure modes it introduces.

This book develops that reasoning from first principles. It begins with requirements, workloads, quality attributes, and estimation; follows a request across the network; develops API and data-modeling choices; then moves through scaling, caching, asynchronous processing, architecture boundaries, and production readiness. A small online-store domain is used repeatedly so that the ideas remain connected across chapters.

The recurring design loop is:

```text
requirements → workload → simplest design → measurement → bottleneck → justified change → new trade-off
```

## Contents

1. [System Design Fundamentals and Mindset](#chapter-1-system-design-fundamentals-and-mindset)
2. [A Repeatable Design Workflow and Back-of-the-Envelope Estimation](#chapter-2-a-repeatable-design-workflow-and-back-of-the-envelope-estimation)
3. [Networking and the Request Journey](#chapter-3-networking-and-the-request-journey)
4. [APIs and Communication Patterns](#chapter-4-apis-and-communication-patterns)
5. [Data Modeling and Storage Choices](#chapter-5-data-modeling-and-storage-choices)
6. [Scaling Applications, Traffic, and Data](#chapter-6-scaling-applications-traffic-and-data)
7. [Caching and High-Read Systems](#chapter-7-caching-and-high-read-systems)
8. [Queues, Events, and Asynchronous Systems](#chapter-8-queues-events-and-asynchronous-systems)
9. [Architecture and Reusable Design Patterns](#chapter-9-architecture-and-reusable-design-patterns)
10. [Production-Ready Systems](#chapter-10-production-ready-systems)

---

## Chapter 1: System Design Fundamentals and Mindset

### What System Design Is

System design is the process of deciding how the parts of a software system should work together to satisfy a set of requirements.

A backend system usually contains several kinds of decisions:

- **Components:** the major parts of the system, such as an application server, database, cache, queue, or external service.
- **Data boundaries:** where information is stored, which component owns it, and which data is treated as the source of truth.
- **Interfaces:** how clients and components communicate, such as an HTTP API or an internal service call.
- **Operating behavior:** how the system behaves under normal traffic, heavy traffic, dependency failures, deployments, and recovery.

A diagram containing many boxes is not automatically a good system design. Every box should exist for a reason. The important questions are what problem the component solves, which requirement it supports, and what new cost or failure mode it introduces.

System design also operates at a different level from application implementation. Implementation focuses on details such as classes, functions, framework configuration, and source code. System design focuses on larger boundaries and interactions. It explains where requests travel, where state lives, how work is divided, and how the system responds when its workload or environment changes.

There is rarely one universally correct architecture. Two teams can design the same product differently because they have different traffic, correctness requirements, budgets, deadlines, skills, or existing infrastructure. A useful design is therefore not the most complicated design. It is the design whose decisions can be justified from the actual problem.

### Requirements Define the Problem

Architecture begins with requirements. Without requirements, there is no reliable way to decide whether a design is appropriate.

Consider a small online store. A vague request such as “design an e-commerce backend” leaves many unanswered questions. The system might serve fifty employees ordering office supplies, or millions of customers during a major sale. Both systems support online shopping, but their architectures do not need to be the same.

#### Functional Requirements

Functional requirements describe what users or other systems must be able to do.

For the online store, the first version might support the following actions:

- browse a list of products
- view the details of one product
- place an order
- view the status of an existing order

These requirements define the system’s visible behavior. They also establish an initial scope. Features such as recommendations, reviews, seller management, refunds, and live delivery tracking may be valuable, but they do not belong in the first design unless they are required.

Scope is important because every additional feature creates more data, interfaces, dependencies, and failure cases. A design that tries to solve every possible future problem becomes difficult to explain and expensive to build.

#### Non-Functional Requirements

Non-functional requirements describe how well the system must operate and under which conditions.

Examples for the online store include:

- product pages should normally load quickly
- customers should be able to browse even during a promotion
- a confirmed order must not disappear
- two retries of the same request should not accidentally create two orders
- the system should support the expected number of customers without unreasonable cost

The phrase “non-functional” does not mean unimportant. These requirements often determine the architecture more strongly than the list of features. “Place an order” is a functional requirement. “Never lose an accepted order” adds a durability requirement. “Do not create duplicate orders during retries” adds a correctness requirement. Each statement changes the design problem.

Requirements should become concrete enough to guide a decision. “The system must be fast” is vague. “Most product pages should load within an acceptable user-facing response time during normal traffic” is more useful. A precise numerical target can be added when measurements and business expectations are available.

#### Constraints

A constraint is a limit within which the system must operate. It may come from technology, cost, time, regulation, or the surrounding organization.

Common constraints include:

- a small engineering team
- a limited infrastructure budget
- a fixed launch date
- an existing database that cannot immediately be replaced
- a legal requirement about where data may be stored
- a dependency with a fixed request limit

Constraints are not automatically design flaws. They are part of the problem. A technically impressive architecture that exceeds the available budget or cannot be operated by the team is not a suitable solution.

#### Known Facts and Assumptions

A known fact is supported by evidence. An assumption is accepted temporarily so that design work can continue.

For example:

| Statement | Classification |
|---|---|
| The current store receives about 20,000 product views per day. | Known fact, if measured from production data |
| Promotion traffic may be ten times normal traffic. | Assumption, until validated |
| The first release must run within the existing monthly budget. | Constraint |
| Product browsing can tolerate slightly old inventory counts. | Requirement or assumption that must be confirmed |

Assumptions are necessary when information is incomplete, but they should be visible. A hidden assumption can make an architecture appear correct even though it solves the wrong problem.

### Workloads and Access Patterns

A workload describes the work placed on a system. An access pattern describes how the system’s data is created, read, updated, and deleted.

These are inputs to architecture decisions. The same amount of stored data can require very different designs depending on how it is accessed.

#### Reads and Writes

A read retrieves existing information. A write creates or changes information.

The online store has several read paths:

- listing products
- opening a product page
- checking an order’s status

It also has write paths:

- creating an order
- updating inventory
- changing the state of an order

The number of reads and writes matters, but their meaning matters too. Product browsing may generate many reads that can tolerate a small amount of staleness. Order creation may generate fewer writes, but every accepted order must be handled correctly. A less frequent operation can therefore deserve more careful design than a high-volume operation.

#### Read/Write Balance

Some systems are read-heavy. Product catalogs, public articles, and video metadata may be read far more often than they are changed.

Other systems are write-heavy. Telemetry collection, click tracking, and event ingestion can receive continuous streams of new data.

The ratio influences which part of the system is likely to experience pressure first. A read-heavy system may need to reduce repeated work for popular data. A write-heavy system may need to absorb bursts, organize concurrent updates, or process work asynchronously. The architectural mechanisms differ, but the workload should be identified before any mechanism is selected.

#### Data Size

Data size has several dimensions:

- the size of one object or record
- the number of objects
- the rate at which new data is created
- how long the data must be retained

A product name and price are small. A collection of high-resolution product images is much larger. Treating both as identical data because they belong to the same product hides an important design difference.

Current size alone can also be misleading. A database containing 50 gigabytes may be comfortable today, but growth matters if it receives another 10 gigabytes every week. Retention rules affect whether that growth continues forever or old data can be removed or archived.

Detailed storage estimation belongs later. At this stage, the purpose of these questions is to reveal which data is large, fast-growing, or long-lived.

#### Traffic Shape

Average traffic does not describe when requests arrive.

Traffic may be:

- **steady:** demand remains relatively stable
- **bursty:** requests arrive in short, intense groups
- **seasonal:** demand follows predictable hours, days, or events
- **unpredictable:** an external event suddenly changes demand

An online store may be quiet for most of the day and receive a large burst when a limited promotion begins. A design based only on the daily average can fail during the period that matters most.

Traffic shape also applies to individual operations. Product browsing may rise sharply during a sale, while order creation rises only after customers decide to buy. Different paths can reach their limits at different times.

#### Correctness-Sensitive Operations

Not every request has the same consequence when something goes wrong.

If a product recommendation is temporarily missing, the page may still be useful. If the system confirms an order but fails to preserve it, the result is much more serious. Correctness-sensitive paths include operations involving money, inventory, identity, permissions, and irreversible state changes.

Identifying these paths early helps allocate complexity where it is justified. The entire system does not always need the strongest possible guarantees. The guarantees should match the consequence of failure.

#### “Scalable” Needs a Workload Dimension

Scalability is not a single unlimited property. A system may scale well for reads but poorly for writes. It may handle more requests but not larger objects. It may serve one region efficiently but become slow when users are distributed around the world.

Instead of saying “the system must be scalable,” identify what must grow:

- request volume
- stored data
- write rate
- concurrent connections
- object size
- geographic reach
- number of teams changing the system

Only then can scalability be evaluated meaningfully.

### Core Quality Attributes

Quality attributes describe important properties of a system. They provide a vocabulary for expressing non-functional requirements and comparing design choices.

#### Scalability

Scalability is the ability to handle growth while maintaining acceptable behavior.

Growth might mean more requests, users, data, writes, connections, regions, or development teams. A design is scalable only relative to a particular workload dimension and an acceptable cost.

Adding resources without receiving useful additional capacity is not effective scaling. A scalable design should allow the constrained part of the system to grow in a reasonably controlled way.

#### Availability

Availability asks whether the system can serve a request when it is needed.

An unavailable product service may return an error or fail to respond. Availability is often described over a period of time, but the foundational question is simpler: when a user arrives, can the service provide a usable response?

Availability does not prove that the response is correct or current. A service can respond successfully while returning stale or incorrect information.

#### Reliability

Reliability is the ability to continue performing the expected function correctly over time.

A checkout service that remains online but occasionally creates the wrong order is available at those moments, but it is not reliable. Reliability includes more than uptime. It is tied to the outcome that users expect.

Failures cannot always be prevented, so reliability also depends on predictable handling and recovery. Later chapters develop concrete failure-handling mechanisms such as retries, redundancy, health checks, and recovery.

#### Performance

Performance describes how efficiently and quickly a system completes work under stated conditions.

Useful performance questions include:

- How long does one request take?
- How many requests can be completed in a second?
- What happens to response time as traffic grows?
- Which resource becomes saturated first?

A system that is fast for one user may still perform badly under load. Performance should therefore be connected to workload rather than measured in isolation.

#### Consistency

Consistency describes what data a user or component can observe after data changes.

Suppose an administrator changes a product price. Must every following read immediately return the new price, or is a short delay acceptable? The correct answer depends on the business operation.

Consistency is not simply “the data is valid.” It concerns the visibility and ordering of changes across reads, writes, and copies of data. Distributed systems make this question more complex because multiple copies of data may not observe changes at exactly the same time.

#### Durability

Durability asks whether acknowledged data survives failures.

After the store confirms an order, the order should remain stored even if an application process restarts. Durability is concerned with preserving accepted state, not with whether that state can be accessed at every moment.

A system can be durable but temporarily unavailable. The order still exists, even though the service cannot currently retrieve it. Conversely, a service can be available while relying on temporary data that may be lost after a failure.

#### Quality Attributes Can Conflict

Quality attributes do not improve independently without cost.

Examples include:

- keeping more redundant capacity can improve availability but increases cost
- waiting for additional confirmation before accepting a write can improve confidence but increase latency
- returning older data can keep some read paths available but weaken freshness
- supporting more flexibility can increase implementation and operational complexity

System design is therefore an exercise in priorities. The goal is not to maximize every attribute. The goal is to reach the required balance for the system being designed.

### Latency, Throughput, and Bandwidth

These terms describe different aspects of performance and should not be used interchangeably.

#### Latency

Latency is the time required to complete one operation.

If a product request begins at 10:00:00.000 and the response completes at 10:00:00.120, the observed latency is 120 milliseconds. That time may include network travel, waiting in a queue, application processing, database work, and response transfer.

Latency is experienced per operation. A system can process many requests every second while some individual requests remain slow.

#### Throughput

Throughput is the amount of completed work per unit of time.

For a web service, throughput may be measured in requests per second. For a database, it may be transactions per second. For a data pipeline, it may be events processed per minute.

A restaurant provides a useful analogy. The time one customer waits for a meal resembles latency. The number of meals the kitchen completes per hour resembles throughput. These measurements are related, but they are not the same.

#### Bandwidth

Bandwidth is the capacity to transfer data during a period of time, commonly measured in bits or bytes per second.

A network link may have enough bandwidth to transfer a large amount of data, but a request can still have noticeable latency because it must travel through several network and processing steps. More bandwidth helps when transfer volume is the constraint; it does not remove every source of delay.

The road analogy is useful:

- latency resembles the time one vehicle needs to reach its destination
- throughput resembles the number of vehicles that arrive per minute
- bandwidth resembles the road’s capacity

A wider road can carry more vehicles, but it does not automatically shorten the physical journey for one vehicle.

#### Averages and Tail Latency

An average can hide slow requests.

Suppose nine product requests finish in 100 milliseconds and one finishes in 2 seconds. The average is affected by the slow request, but it still does not show clearly how bad the slowest user experience was.

Percentiles describe the distribution more usefully. A p95 latency indicates that 95 percent of measured requests completed at or below that value. A p99 value focuses further into the slow tail. The mathematics is not required here; the important idea is that users experience individual requests, not the average request.

### Bottlenecks

A bottleneck is the resource or dependency that reaches its useful limit first for the current workload.

If the application server can process 1,000 requests per second but the database can support only 300 of those requests, adding more application servers may not increase the system’s useful capacity. The database is the current bottleneck for that request path.

Possible bottlenecks include:

- CPU time
- memory
- disk space or disk operations
- network capacity
- database connections
- lock contention
- a slow downstream service
- an external API quota
- infrastructure cost
- the team’s ability to operate the system safely

The last two are easy to ignore. A technically scalable design can still be unsuitable if its cost grows too quickly or if the team cannot understand and operate it.

Bottlenecks depend on the workload. A service may be CPU-bound while calculating reports, database-bound while retrieving records, and network-bound while transferring large files. There is no component that is always the bottleneck.

#### Measurement and Testable Hypotheses

A statement such as “the database will be slow” is not enough. A stronger statement connects the workload, evidence, and suspected limit:

> During promotion traffic, product requests are expected to increase sharply. If application CPU utilization approaches its safe capacity while downstream latency remains stable, the application tier is likely to be the first bottleneck.

This statement can be tested with measurements or a load test. If the evidence points elsewhere, the design should change accordingly.

### Trade-Offs

A trade-off is an exchange in which a decision improves one concern while weakening another concern or adding a new cost.

Every meaningful architecture addition should be described using four questions:

1. What benefit is gained?
2. What cost or complexity is introduced?
3. Which requirement improves?
4. What new failure mode or limitation appears?

For example, adding another application instance can increase request-processing capacity and reduce dependence on one application process. It also requires a way to distribute requests, determine which instances are healthy, deploy compatible versions, and avoid relying on memory that exists on only one instance.

The decision is not good merely because the system now contains more servers. It is useful when the workload requires the added capacity and the team accepts the new operational burden.

Trade-offs should be specific. “SQL versus NoSQL” is not itself a trade-off. A useful comparison states which access pattern, correctness need, scaling limit, operational constraint, or cost makes one choice more appropriate for the current problem.

### Start Simple and Evolve

The first design should be the smallest credible design that satisfies current requirements.

For the small online store, an initial system might contain:

- a client application
- one backend application
- one durable database that acts as the source of truth

This is simple, but it is not merely a toy. The client has a defined interface to the backend. The backend owns the business behavior. Durable product and order data have an authoritative home. Known limitations are visible.

The design should not immediately add multiple services, queues, caches, database replicas, and cross-region infrastructure because those components are common in large technology companies. Each component creates work and failure cases. Complexity is justified when a requirement or observed pressure makes it necessary.

#### Workload Pressure

Suppose the store launches a promotion. Measurements show the following behavior:

- incoming product requests increase significantly
- application CPU reaches its safe operating limit
- requests wait longer before being processed
- user-facing latency rises
- the database still has usable capacity

The first measured bottleneck is the application process. This evidence gives the design a specific reason to evolve.

#### One Justified Change

The application tier can be expanded to multiple instances, with incoming requests distributed between them.

The benefit is additional request-processing capacity. The change supports the requirement that browsing should remain usable during promotion traffic.

The change also introduces new concerns:

- unhealthy instances must stop receiving requests
- application instances should not depend on private in-memory session state
- deployments must keep multiple instances compatible
- request distribution becomes another part of the operating system
- the database may become the next bottleneck as application capacity grows

The evolved design is not “finished.” It is simply more appropriate for the newly observed workload. Future changes should follow the same reasoning process.

#### The Reusable Reasoning Loop

A dependable system-design habit follows this loop:

1. Establish functional and non-functional requirements.
2. Identify access patterns, workload shape, constraints, and assumptions.
3. Build the smallest credible design.
4. Find the first credible bottleneck or failure mode.
5. Introduce one mechanism that addresses it.
6. State the benefit, cost, and new failure behavior.
7. Repeat only when another requirement or measured limit justifies it.

This process keeps architecture connected to evidence. It also makes the design explainable because every important component has a visible reason to exist.

### Reason from the Problem

Memorized architectures are tempting because they provide familiar boxes. A designer may see a popular system diagram and reproduce its load balancers, caches, queues, replicas, and services before understanding the current problem.

This reverses the correct direction of reasoning. Components should follow requirements; requirements should not be invented to justify components.

Two systems with similar user interfaces may need different backends. A private store with predictable internal traffic may work well with one application and one database. A global marketplace with flash sales, millions of products, and strict financial workflows faces different pressures. Neither architecture is automatically better outside its context.

Strong system design reasoning therefore sounds like this:

- “This path is read-heavy, so repeated reads are the likely pressure.”
- “This operation changes money or inventory, so correctness matters more than minimal latency.”
- “Traffic is bursty rather than steady, so peak behavior matters.”
- “The current application tier is saturated, so additional application capacity is justified.”
- “This mechanism improves availability, but it increases cost and operating complexity.”

The objective is not to predict every future event. It is to make present assumptions explicit, choose a design that fits them, and preserve a reasonable path for change.

### Chapter Summary

- System design connects requirements to components, data boundaries, interfaces, and operating behavior.
- Functional requirements define what the system does; non-functional requirements define how well it must operate.
- Constraints and assumptions must be visible because they shape which designs are practical.
- Reads, writes, data size, traffic shape, and correctness-sensitive paths reveal the actual workload.
- Scalability, availability, reliability, performance, consistency, and durability describe different system qualities.
- Latency measures time per operation, throughput measures completed work over time, and bandwidth measures transfer capacity.
- A bottleneck is the resource or dependency that reaches its useful limit first for a stated workload.
- Every architectural improvement introduces a cost, limitation, or new failure mode.
- The safest default is to start with the smallest credible design and evolve it using requirements and evidence.
- Architectures should be reasoned from the problem rather than recalled as fixed templates.

---

## Chapter 2: A Repeatable Design Workflow and Back-of-the-Envelope Estimation

### A Repeatable System Design Workflow

System design problems are intentionally open-ended. A prompt such as “design an online store” or “design a messaging system” does not contain enough information to determine one correct architecture. The problem must first be shaped into something concrete enough to design.

A repeatable workflow prevents the discussion from becoming a random tour of databases, caches, queues, and other technologies. It also keeps attention on the highest-risk parts of the system.

The workflow has six stages:

1. Clarify requirements and define scope.
2. Identify core entities and access patterns.
3. Sketch APIs and major data flows.
4. Build the simplest high-level design.
5. Find bottlenecks and choose focused deep dives.
6. Discuss failures, trade-offs, and future evolution.

These stages are ordered, but they are not irreversible. A storage estimate may reveal that the retention requirement is too expensive. A data flow may reveal an unstated correctness requirement. New information can justify returning to an earlier stage and revising the design.

The goal is not to follow a script mechanically. The goal is to maintain a clear reasoning path from problem to decision.

### Clarify Requirements and Define Scope

The first task is to determine which system is actually being designed.

Useful requirement questions cover several areas:

- **Actors:** Who uses the system? Are there customers, administrators, sellers, internal services, or external partners?
- **Core use cases:** Which user actions must the design support?
- **Exclusions:** Which features are explicitly outside the current scope?
- **Scale:** How many users, requests, writes, stored objects, or connections are expected?
- **Performance:** Which operations are latency-sensitive?
- **Availability:** Which operations must remain usable during failures?
- **Correctness:** Which operations cannot tolerate stale, duplicated, lost, or conflicting state?
- **Durability:** Which accepted data must survive failures?
- **Geography:** Are users concentrated in one region or distributed globally?
- **Constraints:** What limits exist around cost, team size, deadlines, regulation, or existing infrastructure?

The result should be a small set of prioritized requirements, not a complete product specification.

For an online store, a focused scope might be:

#### Functional Requirements

- browse products
- view product details
- place an order
- view order status

#### Non-Functional Requirements

- product browsing should remain responsive during promotions
- confirmed orders must not be lost
- retries must not create duplicate orders
- the first release serves users in one geographic region

#### Out of Scope

- recommendations
- product reviews
- seller onboarding
- refunds
- live delivery tracking

Exclusions are useful because they protect the design from expanding indefinitely. They also reveal where a system boundary currently ends.

A vague quality such as “highly available” or “low latency” should become more specific when the value affects a decision. Not every requirement needs an exact number immediately. Precision is useful only when it distinguishes acceptable behavior from unacceptable behavior.

### Identify Core Entities and Access Patterns

An entity is an important thing about which the system stores or exchanges information.

The online store may have these core entities:

- **Product:** title, price, description, image references, and availability information
- **Customer:** identity and account information
- **Order:** customer, selected products, totals, and order state
- **Inventory:** the available quantity of a product

This is not yet a database schema. It is a vocabulary for discussing the system. Naming entities makes APIs and flows easier to describe and exposes important relationships.

The next step is to identify how those entities are accessed.

Important access patterns include:

- list products using filters or categories
- retrieve one product by identifier
- create an order for a customer
- reduce inventory when an order is accepted
- retrieve recent orders for one customer
- update and read order status

Access patterns matter because storage is used through queries and mutations, not as an abstract container. A design that stores data efficiently but cannot support its important access patterns is incomplete.

The high-value access patterns deserve the most attention. It is unnecessary to enumerate every possible administrative query. The design needs enough information to expose the main read paths, write paths, and correctness-sensitive operations.

### Sketch APIs and Major Data Flows

An API defines how an external actor or another component interacts with the system.

A small external API for the online store could include:

```text
GET  /products
GET  /products/{productId}
POST /orders
GET  /orders/{orderId}
```

The objective is not to perfect every URL, field, status code, or validation rule. The API establishes the system boundary and identifies the major operations.

The `POST /orders` operation immediately raises useful questions:

- Which customer is creating the order?
- Which products and quantities are requested?
- When is inventory checked?
- When is the order considered accepted?
- What happens if the client retries after a timeout?
- Which response tells the client that the order already exists?

These questions reveal design concerns that a component diagram alone may hide.

A data flow traces the important steps from input to result. A simplified order flow might be:

1. The client submits an order request.
2. The backend authenticates and validates the request.
3. The backend checks or reserves inventory.
4. The order is stored in the authoritative database.
5. The backend returns the accepted order identifier.

This flow is intentionally incomplete. Payment, fulfillment, and notification may be added only if the scope requires them. The purpose of the flow is to expose boundaries, state changes, dependencies, and failure points.

APIs and data flows are reasoning tools. They should reveal the architecture, not consume the entire design discussion.

### Build the Simplest High-Level Design

Once requirements, entities, interfaces, and flows are understood, the smallest credible architecture can be proposed.

For the initial online store, that design may contain:

- clients
- one backend application
- one relational database acting as the source of truth
- separate storage for large product images when necessary

The initial design should demonstrate that every core use case has a complete path. A request must enter the system, reach the appropriate logic, read or modify authoritative state, and return a result.

The design does not need to include every mechanism that might be useful at a much larger scale. Additional services, caches, queues, replicas, and partitions are not signs of completeness by themselves. They become useful when a requirement, bottleneck, or failure mode justifies them.

A strong baseline is simple enough to understand but clear about its limitations. For example, one backend instance is a single point of failure and has limited processing capacity. Those limitations can be discussed without immediately replacing the baseline with a large final architecture.

### Find Bottlenecks and Choose Focused Deep Dives

A deep dive is a detailed investigation of a part of the design that materially affects correctness, scalability, performance, or reliability.

Deep dives should follow risk rather than a fixed checklist.

Examples include:

- a ticket-booking system needs a deeper discussion of concurrent attempts to claim the same seat
- a social feed needs a deeper discussion of distributing posts to many followers
- a media service needs a deeper discussion of storing and transferring large objects
- a chat system needs a deeper discussion of long-lived connections and message delivery
- an online store may need deeper discussion of promotion traffic and safe order creation

The requirements and estimates determine which risk deserves attention. Spending ten minutes on cache eviction is not valuable if the main problem is preventing duplicate financial operations.

For every proposed deep dive, the connection should be explicit:

```text
Requirement or workload
→ likely bottleneck or failure mode
→ mechanism worth investigating
→ resulting trade-off
```

### Discuss Failures, Trade-Offs, and Evolution

A high-level design explains the normal path. A complete design discussion also considers what happens when the path breaks.

Useful failure questions include:

- What if the backend process stops during a request?
- What if the database becomes temporarily unavailable?
- What if a downstream dependency is slow?
- What if the client times out even though the write succeeded?
- What if promotion traffic exceeds the planned peak?
- Which functions can degrade, and which must reject work safely?

Every reliability mechanism introduces another trade-off. More copies can improve tolerance to failure but increase cost and consistency work. More retries can improve recovery from transient errors but also amplify overload or duplicate side effects. Specific mechanisms vary, but the workflow requires that both benefits and consequences remain visible.

The design should finish with an evolution path rather than pretending that the current architecture is permanent. Useful evolution statements are conditional:

- If product reads begin to saturate the source of truth, reduce repeated work on the read path.
- If application processing reaches its limit, add application capacity and distribute requests.
- If stored data outgrows the current database strategy, revisit partitioning and retention.
- If users expand into distant regions, reconsider data placement and latency.

Conditional evolution is different from speculative complexity. It identifies what evidence would justify the next change.

### Back-of-the-Envelope Estimation

Back-of-the-envelope estimation uses simple arithmetic and rounded inputs to understand the approximate size of a workload.

The objective is not to predict production traffic exactly. It is to determine whether a design assumption is plausible and whether an architectural decision needs to change.

An estimate is valuable when it answers a question such as:

- Is average traffic enough, or will peak traffic dominate the design?
- Are reads far more common than writes?
- Will storage remain moderate or grow rapidly?
- Do large payloads dominate network transfer?
- Are thousands or millions of simultaneous connections expected?
- Is a proposed single component a credible starting point?

If the result is merely “the number is large,” the calculation has not yet contributed to the design.

#### Turning Vague Requirements into Targets

Vague statements can often be converted into measurable quantities.

| Vague statement | More useful target |
|---|---|
| The store has many visitors. | Expected average and peak requests per second |
| The catalog is read-heavy. | Approximate read/write ratio by important operation |
| Orders must be retained. | Order writes per day × record size × retention period |
| Product pages contain large media. | Peak requests per second × average transferred bytes |
| The system has many active users. | Arrival rate × average session or operation duration |

These targets remain estimates. Their usefulness comes from making assumptions visible and comparable.

#### Label Every Input

Every input should be labelled as one of the following:

- **Requirement:** a value the system is expected to satisfy
- **Measured value:** evidence collected from an existing system or prototype
- **Assumption:** a temporary value used because evidence is unavailable
- **Design input:** a choice being evaluated, such as the number of stored copies

This distinction prevents invented numbers from appearing authoritative. Assumptions should later be validated through production measurements, payload sampling, load tests, or business forecasts.

#### Round Aggressively

Estimation is easier when numbers are rounded.

Useful approximations include:

- one day is roughly 100,000 seconds rather than exactly 86,400
- one million divided by 100,000 is roughly ten
- powers of ten are often sufficient to compare architectural directions

Exact arithmetic can create false confidence because the inputs themselves are uncertain. A result of approximately 1,000 requests per second is usually more honest than 1,157.4 requests per second.

The appropriate precision depends on the decision. A rough order of magnitude is enough to distinguish 1,000 connections from 10 million connections.

### Average and Peak QPS

QPS means queries or requests per second. The term is commonly used even when the operations are not literal database queries.

Average QPS can be estimated from daily traffic:

```text
average QPS = requests per day ÷ seconds per day
```

If a service receives 10 million product views per day:

```text
10,000,000 ÷ 86,400 ≈ 116 requests/second
```

For quick mental arithmetic:

```text
10,000,000 ÷ 100,000 ≈ 100 requests/second
```

The rounded result is sufficient to establish the order of magnitude.

Average QPS does not describe bursts. If promotion traffic is assumed to reach ten times the average:

```text
peak QPS ≈ 116 × 10 ≈ 1,160
rounded peak QPS ≈ 1,200 requests/second
```

The peak multiplier must be labelled as an assumption unless measured traffic establishes it. Synchronized events, hot products, and limited promotions may create much larger spikes than ordinary daily variation.

### Read/Write Ratio

Reads and writes should be estimated separately because they stress systems differently.

Suppose the simplified store has:

- 10 million product views per day
- 100,000 new orders per day

Using product views as reads and order creation as writes:

```text
read/write ratio = 10,000,000 ÷ 100,000 = 100:1
```

This does not include every operation. Inventory updates, order-status reads, and administrative changes have been excluded to keep the example compact. The ratio still reveals that product browsing is much more frequent than order creation.

Volume is not the only priority. The lower-volume order path carries stronger correctness and durability requirements. The estimate therefore suggests two different areas of attention: read capacity for browsing and correctness for ordering.

### Storage Growth

Raw storage growth can be approximated using the number of writes, the average item size, and the retention period.

```text
raw storage = writes per period × item size × retention periods
```

For 100,000 orders per day, a 2 KB average order record, and one year of retention:

```text
100,000 × 2 KB = 200 MB/day
200 MB × 365 ≈ 73 GB/year
```

Raw business data is not the complete storage requirement. Additional space may be needed for:

- indexes
- metadata
- transaction logs
- temporary files
- backups
- replicas
- growth headroom

Suppose indexes and metadata add approximately 50 percent in this simplified estimate:

```text
73 GB × 1.5 ≈ 110 GB/year
```

If three stored copies are planned:

```text
110 GB × 3 ≈ 330 GB/year
```

Replication is applied after estimating one complete logical copy. It should not be silently hidden inside the raw record size.

The result does not automatically require sharding or a distributed database. Approximately 330 GB per year may support a comparatively simple starting strategy, depending on query patterns, growth, and operational constraints. The important conclusion is that the estimate does not justify immediate complexity by itself.

### Bandwidth and Data Transfer

Bandwidth can be approximated by multiplying request rate by the average payload size.

```text
bandwidth = requests per second × bytes per request
```

If the peak product API receives 1,200 requests per second and returns 20 KB of JSON per request:

```text
1,200 × 20 KB = 24,000 KB/second
≈ 24 MB/second
≈ 192 megabits/second
```

If each product view also transfers one 300 KB image:

```text
1,200 × 300 KB = 360 MB/second
≈ 2.9 gigabits/second
```

The media transfer is approximately fifteen times the API response transfer. This difference is large enough to influence the design: product media should not be treated like small relational records or repeatedly moved through the same application path.

The estimate is deliberately simplified. Real pages may contain several images, browser caches may reduce transfers, compression changes sizes, and not every request returns the same payload. These factors should be refined when they can change the conclusion.

Ingress and egress should also be distinguished. Upload-heavy systems may have significant inbound traffic, while streaming and media-delivery systems are usually dominated by outbound transfer.

### Concurrent Users and Connections

Request rate and concurrency are different quantities.

Concurrency estimates how many operations, sessions, or connections are active at the same time. A useful approximation is:

```text
concurrency ≈ arrival rate × average duration
```

At a peak of 1,200 requests per second with an average request duration of 200 milliseconds:

```text
1,200 × 0.2 seconds ≈ 240 in-flight requests
```

This value describes simultaneous in-flight requests, not logged-in users.

Connection-oriented systems can produce very different results. If clients keep a connection open for several minutes or hours, concurrency can remain high even when each client sends few messages. Chat, collaborative editing, live dashboards, and streaming systems therefore require explicit connection estimates.

Concurrency should be calculated when connection lifetime or simultaneous work affects the architecture. It should not be added mechanically to every design.

### Compact Worked Example

The online-store example uses the following inputs:

| Input | Value | Classification |
|---|---:|---|
| Product views per day | 10 million | Measured baseline for the example |
| Orders per day | 100,000 | Measured baseline for the example |
| Peak multiplier | 10× | Assumption |
| Product API payload | 20 KB | Measured sample |
| Average product image | 300 KB | Measured sample |
| Average order record | 2 KB | Measured sample |
| Order retention | 1 year | Requirement |
| Stored copies | 3 | Design input |

The calculations produce these approximate results:

- average product-read traffic: 116 requests per second
- peak product-read traffic: 1,200 requests per second
- simplified read/write ratio: 100:1
- raw order growth: 73 GB per year
- estimated order storage with overhead and three copies: 330 GB per year
- peak API response transfer: 24 MB per second
- peak image transfer: 360 MB per second
- estimated in-flight requests at 200 ms: 240

### Using Estimates to Influence Decisions

Numbers are useful only when connected to implications.

#### Read Traffic

The 100:1 read/write ratio makes the product-read path a natural scalability deep dive. It does not automatically require a cache. A credible baseline can be load-tested first, and repeated read work can be reduced when measurements justify it.

#### Order Storage

Approximately 330 GB of annual order storage does not by itself prove that the database must be sharded. A single well-chosen database strategy may remain a reasonable starting point. Query patterns, indexes, retention, growth over several years, and operational limits still matter.

#### Media Transfer

The estimated image bandwidth is much larger than the API bandwidth. This supports separating large media delivery from ordinary application JSON and relational data. This difference supports separating large-media delivery from ordinary API responses and relational data.

#### Concurrency

Approximately 240 in-flight HTTP requests is different from hundreds of thousands of persistent connections. The store should not adopt a persistent-connection architecture merely because it has many daily visitors.

#### Peak Traffic

The gap between average and peak traffic shows why daily averages are insufficient. Capacity must consider the promotion peak, and the scaling mechanism must account for how quickly capacity can become available. A sudden burst may arrive faster than reactive scaling can respond.

### Common Mistakes

#### Premature Complexity

Premature complexity appears when components are added for imagined future scale without evidence that the current design needs them.

Examples include:

- sharding a moderate dataset before understanding its query patterns
- introducing several services before stable domain boundaries exist
- adding asynchronous processing to an operation that requires an immediate result
- planning global deployment when the confirmed scope is one region

A simple design should preserve an evolution path, but it does not need to implement every future mechanism today.

#### Unjustified Technology Choices

Naming a product is not the same as making a design decision.

“Use Redis,” “use Kafka,” or “use Cassandra” is incomplete without the workload, access pattern, failure mode, or guarantee that makes the technology relevant.

A stronger explanation begins with the need:

```text
The product-read path repeats the same popular queries at high volume.
If database reads become the measured bottleneck, a cache may reduce repeated work.
```

The specific technology can be selected after its required behavior is known.

#### Missing Trade-Offs

A design that lists only benefits hides its real cost.

Every important choice should identify:

- the requirement it supports
- the expected benefit
- the operational or financial cost
- the new failure behavior
- the evidence that would confirm the decision

#### False Precision

An answer such as 1,157.407 QPS is not more accurate when daily traffic and peak multipliers are rough assumptions. Round to an appropriate order of magnitude and preserve the uncertainty.

#### Using Only Averages

Average traffic can hide promotions, synchronized jobs, hot keys, seasonal events, and sudden external attention. Estimate the peak separately and state how it was derived.

#### Arithmetic Without a Decision

A page of calculations has little value if every result leads to the same architecture that was already planned. Calculate quantities that can confirm, reject, or prioritize a design choice.

### Reusable Design Checklist

1. Define actors, core use cases, and exclusions.
2. Clarify the important quality requirements and constraints.
3. Name the core entities and high-value access patterns.
4. Sketch only the essential APIs and data flows.
5. Build the smallest credible high-level design.
6. Estimate traffic, storage, bandwidth, or concurrency when a number can influence a decision.
7. Label each input as a requirement, measurement, assumption, or design input.
8. Separate averages from peaks and reads from writes.
9. Choose deep dives according to risk rather than habit.
10. Discuss failures and explicit trade-offs.
11. Describe what evidence would justify the next architectural change.

The workflow creates a traceable chain from requirements to architecture. Estimation strengthens that chain when it reveals the scale of a real problem. The combination produces designs that are easier to explain, test, and evolve.

---

## Chapter 3: Networking and the Request Journey

A user may perform one simple action, such as opening a product page, but the request can travel through several network components before the response appears.

The useful abstraction is to understand **what happens between the client and the backend**, which component is responsible for what, and where latency or failures can appear, without getting lost in every networking detail.

---

### The Complete Request Journey

Consider a browser opening:

```text
https://shop.example.com/products/42
```

A common request path looks like this:

```text
Client → DNS → CDN/Edge → Reverse Proxy or Load Balancer → Application → Database
```

The response then travels back toward the client.

Each component has a simple responsibility:

- **Client** — creates the request and displays the response.
- **DNS** — converts the domain name into an IP address.
- **CDN / Edge** — may serve content closer to the user or forward the request.
- **Reverse proxy / Load balancer** — accepts public traffic and sends it to backend servers.
- **Application server** — executes business logic.
- **Database** — stores and retrieves persistent data.

Not every system needs every component. A small application may simply be:

```text
Client → Application Server → Database
```

More components are introduced only when the system needs them.

---

### The Client Creates an HTTP Request

A client can be a browser, mobile application, command-line program, or another backend service.

From this URL:

```text
https://shop.example.com/products/42
```

we can identify:

- `https` — the protocol scheme.
- `shop.example.com` — the hostname.
- `/products/42` — the resource path.

The browser converts the user's action into an HTTP request.

```http
GET /products/42 HTTP/1.1
Host: shop.example.com
```

Before sending the request, the client normally needs to discover where `shop.example.com` is located on the network.

---

### DNS: Domain Name to IP Address

Humans prefer names such as:

```text
shop.example.com
```

Networks communicate using IP addresses.

**DNS (Domain Name System)** translates the hostname into the IP address of the destination.

A simplified DNS lookup is:

1. The client asks a **DNS resolver** for `shop.example.com`.
2. The resolver finds the domain's **authoritative DNS server**.
3. The authoritative server returns the DNS record.
4. The resolver returns the IP address to the client.

Two DNS roles are especially important:

- **Recursive resolver** — finds the answer for the client.
- **Authoritative DNS server** — stores the official DNS records for the domain.

Common DNS records:

- **A** — hostname → IPv4 address.
- **AAAA** — hostname → IPv6 address.
- **CNAME** — hostname → another hostname.

For example:

```text
shop.example.com → 203.0.113.10
```

DNS responses can be cached for a period controlled by **TTL (Time To Live)**. The broader mechanics of caching, expiration, and invalidation are developed in Chapter 7.

---

### IP Addresses and Ports

An **IP address** identifies the network destination.

A **port** identifies the service running at that destination.

Example:

```text
203.0.113.10:443
```

Here:

- `203.0.113.10` is the IP address.
- `443` is the port commonly used for HTTPS.

A single machine can run multiple services because each service can listen on a different port.

For example:

```text
Web Server  → 443
PostgreSQL  → 5432
Redis       → 6379
```

In real systems, databases and internal services are normally not exposed directly to public clients. Public traffic enters through controlled entry points such as a load balancer or reverse proxy.

---

### TCP and UDP

Once the destination is known, data must travel between the client and server.

Two important transport protocols are **TCP** and **UDP**.

#### TCP

TCP provides reliable and ordered communication.

It handles things such as:

- establishing a connection
- detecting lost data
- retransmitting missing data
- delivering data in order

Most traditional web and database communication uses TCP.

#### UDP

UDP sends independent messages without providing TCP's built-in delivery and ordering guarantees.

It is useful when low overhead is important or when the application can handle loss itself.

Examples include:

- real-time communication
- gaming
- DNS
- protocols built on top of UDP

#### TCP vs UDP

| TCP | UDP |
|---|---|
| Reliable delivery | No built-in delivery guarantee |
| Ordered data | Ordering not guaranteed |
| Connection-oriented | No TCP-style connection setup |
| Common for web/database traffic | Common for real-time and specialized traffic |

The key idea is simple: **TCP provides more delivery guarantees; UDP provides a smaller transport contract.**

---

### TLS and HTTPS

HTTP by itself does not encrypt the data travelling across the network.

**HTTPS = HTTP protected by TLS.**

TLS provides three important protections:

- **Confidentiality** — attackers on the network should not be able to read the data.
- **Integrity** — changes to protected data can be detected.
- **Authentication** — the client can verify the server using its certificate.

Before secure application data is exchanged, the client and server perform a **TLS handshake** to establish the secure connection.

After that, HTTP messages can travel through the encrypted connection.

TLS protects data while it is moving across the network. It does not replace application-level authentication, authorization, or input validation.

---

### HTTP Requests and Responses

HTTP defines how clients and servers structure application-level requests and responses.

#### HTTP Request

A request normally contains:

- **method** — what operation the client wants
- **path** — which resource is targeted
- **headers** — metadata
- **body** — optional data sent to the server

Example:

```http
POST /orders HTTP/1.1
Host: shop.example.com
Content-Type: application/json

{"productId": 42, "quantity": 1}
```

Common methods include:

- `GET` — retrieve data
- `POST` — create or submit data
- `PUT` / `PATCH` — update data
- `DELETE` — remove data

#### HTTP Response

A response normally contains:

- **status code**
- **headers**
- optional **body**

Example:

```http
HTTP/1.1 200 OK
Content-Type: application/json

{"id": 42, "name": "Notebook", "price": 12}
```

Status-code groups:

- **2xx** — success
- **3xx** — redirection
- **4xx** — client-side problem
- **5xx** — server-side problem

Useful examples:

- `200 OK` — request succeeded
- `201 Created` — resource created
- `400 Bad Request` — invalid request
- `401 Unauthorized` — authentication required or failed
- `403 Forbidden` — authenticated but not allowed
- `404 Not Found` — resource not found
- `500 Internal Server Error` — unexpected server failure
- `503 Service Unavailable` — service temporarily unavailable

For system design, the important point is that HTTP defines the **application message**, while lower network layers carry that message between machines.

---

### Reverse Proxy, Load Balancer, and CDN

#### Reverse Proxy

A reverse proxy accepts requests on behalf of backend servers.

```text
Client → Reverse Proxy → Backend Server
```

The client does not need to know which internal server handles the request.

A reverse proxy may provide:

- TLS termination
- request routing
- authentication checks
- compression
- protection of backend server addresses

A reverse proxy can also perform load-balancing behavior. Load-balancing strategies are examined in Chapter 6.

#### CDN

A **Content Delivery Network (CDN)** runs servers at locations closer to users.

It is commonly used for content such as:

- images
- JavaScript and CSS files
- videos
- other static content

If the CDN can serve the content, the request may not need to reach the main application at all. Otherwise, the request continues toward the origin system.

Cache strategies, cache keys, expiration, and invalidation are examined in Chapter 7.

---

### The Application Performs the Work

After the request reaches the application server, the actual business logic begins.

For:

```text
GET /products/42
```

an application might:

1. validate the request
2. check authentication or permissions if required
3. query the database for product `42`
4. create the HTTP response

Example:

```text
Application → Database: Find product 42
Database → Application: Product data
Application → Client: 200 OK + product data
```

The application may also call caches, queues, search engines, object stores, or other services, depending on the system.

Every additional network call introduces extra latency and another place where failures can happen.

---

### Latency Adds Up

The user experiences the total time taken by the entire request journey, not only the time spent inside the application code.

A simplified latency model is:

```text
DNS
+ connection setup
+ TLS handshake
+ network travel
+ application processing
+ database or service calls
+ response travel
```

For example, the application itself may take only `20 ms`, but slow network communication or a slow database query can make the complete request take much longer.

This is why system design discussions focus on the **entire request path**, not only application code.

---

### Network Calls Can Fail

A remote call is less predictable than a local function call.

Failures can happen because:

- DNS resolution fails
- the connection cannot be established
- TLS negotiation fails
- the server is unavailable
- a dependency is slow
- the request times out
- the response is lost

One important case is a timeout.

Suppose a client sends:

```text
POST /payments
```

The server may successfully process the payment, but the response may be lost before reaching the client.

The client sees a timeout, but it does not know whether the operation happened.

This is why distributed systems need concepts such as:

- timeouts
- retries
- idempotency
- observability

These failure-handling mechanisms are developed throughout later chapters. The core rule is:

> A network timeout does not always mean the server did nothing.

---

### Final Mental Model

When reading a backend architecture, follow the request from left to right:

1. **Who creates the request?** — Client
2. **How is the destination found?** — DNS
3. **Where is the request sent?** — IP address + port
4. **How does data travel?** — TCP or UDP
5. **How is the connection protected?** — TLS / HTTPS
6. **What does the application message contain?** — HTTP
7. **Which public infrastructure receives it?** — CDN, reverse proxy, or load balancer
8. **Where is the business logic executed?** — Application server
9. **Where does persistent data come from?** — Database or another data service
10. **Where can latency or failure occur?** — At every network boundary

The central mental model is:

```text
A request is not one jump from the browser to the database.
It is a journey through multiple responsibilities and network boundaries.
```

Understanding that journey makes later topics such as load balancing, caching, databases, queues, microservices, retries, and distributed systems much easier to understand.

---

## Chapter 4: APIs and Communication Patterns

Backend components need clear ways to communicate.

An **API** defines that contract:

- what operations are available
- what input is required
- what output is returned
- how errors are represented

The best communication style depends on the interaction:

- who starts the communication
- whether an immediate result is required
- whether communication is one-way or two-way
- how frequently updates happen
- what happens if a request is delayed, duplicated, or fails

This chapter starts with REST APIs and then compares other common communication patterns.

---

### Start API design from use cases

Do not begin by inventing endpoints.

Start with what users and systems actually need to do.

For a small online store:

- browse products
- view a product
- place an order
- view orders
- cancel an order

These use cases reveal the main **resources**:

```text
Product
Order
Customer
Order Item
```

They also reveal the required operations.

| Use case | API operation |
|---|---|
| Browse products | List products |
| View one product | Get product |
| Place an order | Create order |
| View orders | List orders |
| Cancel order | Change order state |

The important idea is:

```text
use case → resource → operation → API contract
```

---

### REST fundamentals

REST is a common style for building HTTP APIs around resources.

Examples:

```text
GET  /products
GET  /products/42
POST /orders
GET  /orders/ord_901
```

URLs usually represent **resources**, so nouns are generally clearer than action-style URLs.

Prefer:

```text
GET /products/42
```

instead of:

```text
GET /getProduct?id=42
```

Not every action fits simple CRUD perfectly. An order cancellation may still be represented clearly as part of the API contract.

The goal is consistency, not forcing every business operation into an artificial pattern.

---

### HTTP methods

The common HTTP methods are distinguished primarily by intent.

##### GET

Read data.

```http
GET /products/42
```

##### POST

Create something or start an operation.

```http
POST /orders
Content-Type: application/json

{
  "productId": "42",
  "quantity": 1
}
```

##### PUT

Replace a resource at a known location.

```http
PUT /users/42/address
```

##### PATCH

Partially update a resource.

```http
PATCH /products/42

{
  "price": 14.50
}
```

##### DELETE

Remove a resource.

```http
DELETE /saved-products/42
```

A useful high-level distinction:

- `GET` is normally read-only
- `POST` commonly creates or triggers work
- `PUT` replaces
- `PATCH` partially updates
- `DELETE` removes

---

### Idempotency

An operation is **idempotent** when repeating the same logical request produces the same intended business effect.

This matters because network failures can make the client unsure whether an operation completed.

Consider:

```text
Client → Create Order → Server
```

The server creates the order, but the response is lost.

The client retries.

If the server blindly creates another order, the customer may get two orders.

For important create operations, the client can send an **idempotency key**:

```http
POST /orders
Idempotency-Key: order-attempt-781
```

The server can recognize that the retry belongs to the same logical operation and return the previous result.

This is especially important for operations such as:

- payments
- order creation
- booking
- money transfers

The key lesson is:

> A network retry should not accidentally repeat a business operation.

---

### Request and response contract

An API is more than a URL.

A useful API contract defines:

- request parameters
- request body
- required headers
- validation rules
- successful response
- error response
- authorization rules

Example:

```http
POST /orders

{
  "items": [
    {
      "productId": "42",
      "quantity": 1
    }
  ]
}
```

Possible response:

```http
HTTP/1.1 201 Created

{
  "id": "ord_901",
  "status": "pending"
}
```

The client and server should agree on the structure and meaning of this contract.

---

### Authentication and authorization

These two concepts are different.

**Authentication** answers: *Who is the caller?*

**Authorization** answers: *Is that caller allowed to perform this action?*

For example, a user may be authenticated successfully but still not be allowed to access another user's order.

Sensitive identity should normally come from trusted authentication information rather than client-controlled request fields.

Bad idea:

```json
{
  "customerId": "another-user"
}
```

Better approach:

```text
authenticate request
        ↓
identify customer
        ↓
check permission
        ↓
perform operation
```

---

### HTTP status codes

Status codes are part of the API contract.

A small set of status codes covers most API design discussions.

Important ones include:

| Status | Meaning |
|---|---|
| `200` | Success |
| `201` | Resource created |
| `202` | Accepted for later processing |
| `204` | Success with no response body |
| `400` | Invalid request |
| `401` | Authentication required or invalid |
| `403` | Authenticated but not allowed |
| `404` | Resource not found |
| `409` | Conflict with current state |
| `429` | Too many requests |
| `500` | Unexpected server error |
| `503` | Service temporarily unavailable |

A structured error response is better than returning only an English message:

```json
{
  "code": "ORDER_ALREADY_SHIPPED",
  "message": "A shipped order cannot be cancelled."
}
```

Clients can use the stable error code while the human-readable message can change.

---

### Pagination

Large collections should not return every record in one response.

For example, returning one million orders at once would waste:

- database work
- memory
- network bandwidth
- client processing

Two common approaches are enough to understand.

#### Offset pagination

```text
GET /products?limit=20&offset=40
```

Simple and easy to understand.

Useful when datasets are relatively small or page numbers are important.

#### Cursor pagination

```text
GET /orders?limit=20&cursor=abc123
```

The server returns a pointer for the next page.

Example response:

```json
{
  "items": [],
  "nextCursor": "abc123"
}
```

Cursor pagination generally works better for large or frequently changing datasets.

Practical rule:

```text
small/simple collection → offset
large/changing feed → cursor
```

---

### API versioning

Once clients depend on an API, changing it can break them.

Usually safe changes include:

- adding a new endpoint
- adding an optional field
- adding an optional query parameter

Potentially breaking changes include:

- removing a field
- renaming a field
- changing a field type
- changing the meaning of an existing field

When breaking changes cannot be avoided, a new version may be introduced:

```text
/v1/orders
/v2/orders
```

Versioning should be used when necessary, not for every small change.

---

### REST vs gRPC vs GraphQL

REST is not the only way services communicate.

#### REST

Strong fit for:

- public APIs
- browser-facing APIs
- resource-oriented systems

Example:

```text
GET /products/42
```

REST is widely understood and easy to inspect.

---

#### gRPC

gRPC is commonly used for service-to-service communication.

Instead of designing around URLs, services define typed operations and message schemas.

Conceptually:

```text
Order Service → Payment Service
```

Strong fit for:

- internal service calls
- typed contracts
- generated clients
- streaming scenarios

Trade-off:

It requires more tooling and is less human-readable than a typical JSON REST API.

---

#### GraphQL

GraphQL lets the client ask for the fields it needs.

Example:

```graphql
query {
  product(id: "42") {
    name
    price
    reviews {
      rating
    }
  }
}
```

Strong fit when clients need flexible combinations of related data.

Trade-off:

The server must control expensive queries, authorization, and backend data loading.

---

#### Quick comparison

| Style | Good fit |
|---|---|
| REST | Public/resource APIs |
| gRPC | Internal service-to-service communication |
| GraphQL | Flexible client-driven data fetching |

There is no universally best choice.

Use the simplest style that fits the consumers and workload.

---

### Synchronous communication

In synchronous communication, the caller waits for the result.

Example:

```text
Checkout Service → Payment Service → Response
```

This is useful when an immediate result is required.

For example:

```text
Can the payment be authorized?
```

The caller cannot continue until it receives the answer.

The drawback is dependency coupling.

If the payment service becomes slow, checkout also becomes slow.

If the payment service is unavailable, checkout may fail.

So synchronous calls need reasonable **timeouts**.

---

### Asynchronous communication

In asynchronous communication, the caller does not wait for all work to finish.

Example:

```text
Client → Create Report
            ↓
         Job Queue
            ↓
          Worker
```

The server may immediately return:

```http
HTTP/1.1 202 Accepted
```

with:

```json
{
  "jobId": "job_123",
  "status": "pending"
}
```

The work continues in the background.

This is useful when:

- processing takes a long time
- the caller does not need the result immediately
- traffic bursts should be absorbed
- downstream work should be decoupled

The key trade-off is that the result becomes **eventual**, not immediate.

---

### Polling

With polling, the client repeatedly asks whether something changed.

```text
Client → Ready?
Client → Ready?
Client → Ready?
```

Example:

```text
GET /jobs/job_123
```

Polling is often the simplest choice when:

- updates are infrequent
- a few seconds of delay is acceptable
- the number of clients is manageable

The downside is repeated requests even when nothing changed.

---

### Server-Sent Events

**Server-Sent Events (SSE)** allow the server to continuously send updates to the browser over one connection.

```text
Browser ← Server
```

Communication is primarily **server → client**.

Useful for:

- notifications
- job progress
- live dashboards
- status updates

Use SSE when the client mostly needs to receive updates and does not require continuous two-way communication.

---

### WebSockets

WebSockets create a persistent **bidirectional** connection.

```text
Client ⇄ Server
```

Both sides can send messages at any time.

Useful for:

- chat
- multiplayer games
- collaborative editing
- realtime control
- highly interactive live applications

WebSockets are more complex than normal request-response APIs because connections remain open and clients may disconnect and reconnect.

Use them when frequent low-latency communication is genuinely required.

Do not use WebSockets simply because an application has some realtime data.

---

### Webhooks

A webhook is an HTTP callback from one system to another.

Example:

```text
Payment Provider
      ↓
POST /webhooks/payment
      ↓
Online Store
```

Instead of the store repeatedly asking:

```text
Has the payment finished?
```

the payment provider sends an event when it happens.

Webhooks are common for:

- payment events
- GitHub events
- delivery updates
- third-party integrations

A webhook endpoint should:

1. verify that the request is genuine
2. avoid processing the same event twice
3. acknowledge the request quickly
4. process slower work separately when needed

The important reliability idea is:

> Webhook delivery can be retried, so receivers should expect duplicates.

---

### Choosing a communication pattern

The easiest way to choose is to ask a few questions.

#### Do I need an immediate response?

Yes:

```text
REST / gRPC / GraphQL request-response
```

No, work takes time:

```text
Asynchronous job
```

#### How do updates travel?

Client asks occasionally:

```text
Polling
```

Server sends frequent updates:

```text
SSE
```

Both sides send frequent messages:

```text
WebSocket
```

Another backend needs to notify us:

```text
Webhook
```

---

### Practical selection guide

| Requirement | Good starting choice |
|---|---|
| Public resource API | REST |
| Internal typed service call | gRPC |
| Flexible client-selected data | GraphQL |
| Immediate operation result | Synchronous request-response |
| Long-running operation | Async job + status endpoint |
| Infrequent status updates | Polling |
| Frequent server → browser updates | SSE |
| Frequent two-way realtime messages | WebSocket |
| Third-party event notification | Webhook |

Do not choose communication technology because it is fashionable.

Choose the simplest pattern that satisfies:

```text
direction
+ latency
+ frequency
+ reliability
+ scale
```

That is the important system-design decision.

---

## Chapter 5: Data Modeling and Storage Choices

A database should be chosen based on what the system needs to store, read, update, and keep correct.

A useful modeling process is:

```text
Use cases → Entities → Relationships → Access patterns → Storage choice
```

Do not begin with:

```text
SQL or NoSQL?
```

Begin with the data and the operations the system needs.

---

### Identify the main entities

For a small online store, important entities might be:

- Customer
- Product
- Order
- Order Item
- Payment

An **entity** is a domain concept with its own identity.

For example:

- a product can change price but remain the same product
- an order can move from `pending` to `shipped` but remain the same order

The goal at this stage is simply to understand **what data exists**.

---

### Understand relationships

Entities are connected.

#### One-to-one

```text
User ↔ Profile
```

One user has one profile.

#### One-to-many

```text
Customer → Orders
Order → Order Items
```

One customer can have many orders.

#### Many-to-many

```text
Orders ↔ Products
```

One order can contain many products, and one product can appear in many orders.

A relational design commonly resolves this through another entity:

```text
Order → Order Items ← Product
```

`Order Item` can store information such as:

- quantity
- price at the time of purchase

The important lesson is that relationships influence how data should be modeled.

---

### Start from access patterns

Before designing tables or choosing a database, ask:

> How will the application actually use the data?

Examples:

- find a product by ID
- list products in a category
- create an order
- list a customer's latest orders
- read an order with its items
- update order status

These are **access patterns**.

A vague requirement such as:

```text
Store orders
```

is not very useful.

A better requirement is:

```text
Fetch the latest 20 orders for one customer
```

Now the system designer can reason about:

- keys
- indexes
- pagination
- database choice

Storage design should support the important reads and writes of the system.

---

### A simple relational model

For the store, a basic relational model could be:

```text
Customers
- customer_id
- email

Products
- product_id
- name
- current_price

Orders
- order_id
- customer_id
- status
- total_amount
- created_at

Order_Items
- order_id
- product_id
- quantity
- unit_price
```

Relationships:

```text
Customer → Orders
Order → Order Items
Product → Order Items
```

Notice that `unit_price` is stored in the order item.

If a product costs ₹500 today and ₹600 next month, an old order should still show the price the customer actually paid.

This is an example of storing historical data intentionally.

---

### Keys and constraints

Three foundational concepts matter here.

#### Primary key

Uniquely identifies a record.

```text
product_id
order_id
customer_id
```

#### Foreign key

Connects related records.

For example:

```text
orders.customer_id → customers.customer_id
```

#### Constraints

Databases can enforce important rules such as:

```text
quantity > 0
price >= 0
email must be unique
```

Application validation is useful, but critical data rules should also be protected close to the authoritative data when possible.

---

### Normalization vs denormalization

#### Normalization

Normalization reduces unnecessary duplication.

Instead of storing:

```text
Order 901
product_1
product_2
product_3
```

use separate order-item records:

```text
Order 901
   ↓
Order Item 1
Order Item 2
Order Item 3
```

This makes the model easier to extend and keeps important facts in clear locations.

The practical goal is more important than memorizing formal normalization labels such as 1NF, 2NF, and 3NF.

The practical idea is:

> Avoid unnecessary duplication of authoritative data.

#### Denormalization

Sometimes data is duplicated intentionally to make reads faster or preserve historical information.

Examples:

- store `order.total_amount`
- store the product price at purchase time
- maintain a precomputed count

The trade-off is:

```text
faster reads ↔ more complicated writes
```

Normalize by default, then denormalize when a real access pattern justifies it.

---

### Relational vs NoSQL databases

There is no universally best database.

Choose based on the data model and access patterns.

#### Relational database

Examples include PostgreSQL and MySQL.

Strong fit when you need:

- relationships
- joins
- transactions
- constraints
- flexible querying

For an online store with customers, orders, products, and payments, a relational database is usually a strong starting point.

---

#### Key-value store

Model:

```text
key → value
```

Example:

```text
session:abc → user 42
```

Useful for:

- sessions
- caching
- counters
- fast lookup by known key

---

#### Document database

Stores nested documents.

Example:

```json
{
  "orderId": "901",
  "customerId": "42",
  "items": [
    {"productId": "7", "quantity": 2}
  ]
}
```

Useful when related data is commonly read and written together as one document.

---

#### Wide-column database

Useful for very large distributed workloads with predictable access patterns.

Common examples include:

- large event datasets
- high write volume
- time-series-like workloads

The partition key and access pattern matter heavily.

---

#### Graph database

Useful when relationship traversal is the main problem.

Examples:

- social networks
- fraud connections
- recommendation graphs

Do not choose a graph database simply because your data has relationships. Relational databases also handle relationships well.

---

### Quick storage comparison

| Storage type | Good starting use |
|---|---|
| Relational | Business data, relationships, transactions |
| Key-value | Sessions, cache, simple lookup |
| Document | Aggregate-shaped nested data |
| Wide-column | Massive predictable distributed workloads |
| Graph | Relationship traversal |

A common design mistake is using several databases merely because each one is specialized.

Every additional data store adds:

- deployment complexity
- monitoring
- backups
- synchronization
- more failure modes

Start with the simplest storage system that satisfies the requirements.

---

### Indexes

An **index** helps a database locate data without scanning every row.

Suppose the system frequently runs:

```sql
SELECT *
FROM orders
WHERE customer_id = ?
ORDER BY created_at DESC
LIMIT 20;
```

An index involving:

```text
customer_id + created_at
```

can make this access pattern much faster.

But indexes are not free.

They require:

- additional storage
- extra work during inserts and updates

The core trade-off is:

```text
faster reads ↔ slower writes + more storage
```

Do not index every column.

Indexes should follow important queries.

---

### Transactions and ACID

A **transaction** groups related database changes so they succeed or fail together.

Imagine placing an order requires:

1. reduce inventory
2. create the order
3. create order items

If inventory is reduced but order creation fails, the data becomes inconsistent.

A transaction allows these changes to commit together or roll back.

#### ACID

The essential idea is:

- **Atomicity** — all changes succeed or none do
- **Consistency** — rules remain valid
- **Isolation** — concurrent operations should not corrupt each other
- **Durability** — committed data survives expected failures

Detailed isolation levels refine this model, but the architectural point is the correctness boundary provided by a transaction.

The key lesson is:

> Transactions protect correctness when multiple related data changes must agree.

Transactions inside one database do not automatically make calls to external services—such as payment providers—part of the same transaction.

Distributed workflows are handled separately later.

---

### Object storage for large files

Images, videos, documents, and archives are usually better stored in **object storage** rather than ordinary database rows.

Example:

```text
Database
- product_id
- image_url
- metadata

Object Storage
- actual image bytes
```

Why?

Object storage is designed for large files, while the database is better used for searchable metadata and relationships.

Typical examples:

- Amazon S3
- Google Cloud Storage
- Azure Blob Storage

A common architecture is:

```text
Application → Database
           → Object Storage
```

The database stores metadata; object storage stores the large file.

---

### Choosing the database

Ask these questions:

#### What are the access patterns?

```text
exact lookup?
range query?
joins?
full-text search?
relationship traversal?
```

#### What correctness guarantees matter?

```text
transactions?
uniqueness?
relationships?
stale reads acceptable?
```

#### What is the workload?

```text
read-heavy?
write-heavy?
very large?
predictable partition key?
```

#### What operational complexity can we afford?

A more specialized database is useful only when its benefit justifies the extra complexity.

---

### Practical starting point

For the small online store:

```text
Relational Database
        ↓
Customers
Products
Orders
Order Items
Payments
```

Use:

- relationships for connected business data
- constraints for important rules
- indexes for important access patterns
- transactions for related writes
- object storage for large files

Add specialized systems later only when a real requirement appears.

For example:

```text
Redis → sessions / cache
Search engine → product search
Object storage → images
```

The main system-design principle is:

> Choose storage from the data model and access patterns, not from database popularity.

---

## Chapter 6: Scaling Applications, Traffic, and Data

A backend usually starts simple. As traffic grows, we do not add components randomly. We measure what is under pressure, identify the bottleneck, and make the smallest useful change.

A useful scaling mindset is:

```text
simple system → bottleneck → scaling change → new bottleneck
```

This chapter follows a small online store as it grows.

---

### Start with one server

A very small backend can begin with one server handling:

- HTTP requests
- business logic
- application data

This is often a good starting point because it is simple to build, deploy, and debug.

But one server has limits:

- CPU and memory are limited
- application and database work compete for the same resources
- if the server fails, the whole system becomes unavailable
- every responsibility must scale together

The first scaling question should be:

> What is actually under pressure?

Do not distribute a system before there is a reason.

---

### Separate the application and database

As traffic grows, the application and database are usually separated.

```text
Clients → Application Server → Database
```

Now each layer has a clearer responsibility:

- the **application server** handles requests and business logic
- the **database** stores durable data

This lets the application and database use independent CPU, memory, storage, and scaling strategies.

The trade-off is that database calls now cross a network boundary, so failures and latency become possible between the two components.

Separation gives flexibility, but the application server and database may still each be a single point of failure.

---

### Vertical scaling

**Vertical scaling** means making one machine more powerful.

Examples:

- more CPU
- more RAM
- faster storage
- a larger cloud instance

This is often the easiest first scaling step.

Advantages:

- simple
- little or no architecture change
- easy to operate

Limitations:

- machines have a maximum size
- large machines can become expensive
- one machine is still one failure unit

Vertical scaling is useful, but eventually a busy application may need more than one instance.

---

### Horizontal scaling

**Horizontal scaling** means adding more application instances.

Instead of:

```text
Client → Application Server
```

we move toward:

```text
                    → App 1
Client → Router     → App 2
                    → App 3
```

Benefits:

- more requests can be processed at the same time
- one application instance can fail without stopping the whole application tier
- instances can be added or removed as traffic changes

But adding instances creates a new problem:

> Which application instance should receive each request?

That is where a load balancer is introduced.

---

### Stateful vs stateless application servers

Horizontal scaling becomes easier when application instances are **stateless**.

#### Stateful example

Suppose App 1 stores a logged-in user's session only in local memory.

```text
session abc → user 42
```

The next request might reach App 2.

App 2 does not know about that session.

Now the user depends on one specific server.

This is called a **stateful application instance**.

Common examples of problematic local state include:

- login sessions
- shopping-cart data
- uploaded files stored only on local disk

#### Stateless application servers

A stateless application server does not require the next request to return to the same instance.

Shared state is stored outside the application instance.

For example:

- business data → database
- session data → shared session store
- uploaded files → object storage

Now any healthy application instance can serve the next request.

```text
Load Balancer → Any App Instance → Shared State
```

This is one of the most important ideas in horizontal scaling.

**Stateless does not mean the system has no state.**

It means important state is not trapped inside one application instance.

---

### Sticky sessions

One way to work around stateful servers is **sticky sessions**.

The load balancer tries to send the same user back to the same application instance.

This can work, but it has drawbacks:

- if that instance fails, the local session may disappear
- traffic can become uneven
- deployments and scaling become harder

Sticky sessions can be useful temporarily, but stateless application servers are usually easier to scale.

---

### Load balancer

A **load balancer** sits in front of multiple application instances and distributes incoming traffic.

Its basic job is:

1. receive incoming traffic
2. choose a healthy backend instance
3. forward the request
4. avoid instances that are unavailable

Example:

```text
             ┌→ App 1
Client → LB ─┼→ App 2
             └→ App 3
```

If App 2 becomes unavailable, the load balancer can stop sending new traffic to it.

A load balancer improves the application tier only when the application tier is the bottleneck.

It cannot fix an overloaded database.

---

### Load-balancing strategies

Three common routing strategies illustrate the main choices.

#### Round robin

Requests are distributed one after another:

```text
Request 1 → App 1
Request 2 → App 2
Request 3 → App 3
Request 4 → App 1
```

Simple and useful when servers are similar.

#### Least connections

New traffic goes to the server currently handling fewer active connections.

This can help when some requests take longer than others.

#### Weighted routing

A stronger server can receive more traffic than a smaller server.

Example:

```text
App 1 → 50%
App 2 → 30%
App 3 → 20%
```

The important architectural point is that a load balancer chooses a backend using a routing policy.

---

### Health checks

The load balancer must know whether an application instance can receive traffic.

It therefore performs **health checks**.

For example:

```http
GET /health
```

A healthy instance remains in rotation.

An unhealthy instance is temporarily removed.

The core operational idea is simple:

> Multiple servers help only if traffic stops being sent to failed servers.

Readiness checks and deployment draining extend this same principle in production environments.

---

### Reverse proxy, load balancer, and API gateway

These terms often overlap.

#### Reverse proxy

A reverse proxy sits in front of backend servers and forwards client requests to them.

It may also handle TLS termination or hide backend addresses.

#### Load balancer

A load balancer focuses on distributing traffic across multiple backend instances.

#### API gateway

An API gateway is useful when many APIs need shared policies such as:

- authentication
- rate limiting
- routing
- API versioning

A small backend does not automatically need all three as separate components.

One product can perform multiple roles.

The architectural distinction is based on **responsibilities**, not product names.

---

### Scaling does not remove bottlenecks

Suppose we increase the application tier from one server to five servers.

The application can now process more concurrent requests.

But all five servers may still use the same database.

```text
App 1 ─┐
App 2 ─┤
App 3 ─┼→ Database
App 4 ─┤
App 5 ─┘
```

Now the database may become the bottleneck.

This is a fundamental scaling pattern:

```text
scale one layer → pressure moves to another layer
```

Common bottlenecks include:

- application CPU
- database CPU or storage
- database connections
- slow external APIs
- network bandwidth
- shared locks

Scaling should therefore be based on measurements, not assumptions.

---

### Single points of failure

A **single point of failure** is a component whose failure can make the system unavailable.

Examples:

- one application server
- one database
- one load balancer
- one shared session store

Adding three application servers removes the application server as a single point of failure.

But if they all depend on one database, the database may still be a single point of failure.

```text
             ┌→ App 1 ─┐
Client → LB ─┼→ App 2 ─┼→ Database
             └→ App 3 ─┘
```

Scaling and high availability are related, but they are not the same thing.

---

### Autoscaling

**Autoscaling** automatically changes the number of application instances based on demand.

```text
traffic increases → add instances
traffic decreases → remove instances
```

It is useful for variable traffic such as:

- sales
- launches
- seasonal traffic
- unpredictable usage

But autoscaling is not instant. New instances need time to start and become ready.

Autoscaling also does not fix slow queries, inefficient code, or an overloaded shared database. It only adds or removes capacity in the tier being scaled.

---

### When the database becomes the bottleneck

After the application tier scales, the database often becomes the next shared limit.

Common causes include:

- slow queries
- missing or poor indexes
- too many database calls
- returning too much data
- too many open connections
- lock contention
- CPU or memory pressure
- storage limits

Before distributing the database, first improve how the current database is used.

```text
optimize first → distribute later
```

---

### Optimize before scaling the database out

#### Improve important queries

Find the queries that consume the most time or resources.

Typical improvements include:

- add indexes for important access patterns
- avoid scanning unnecessary rows
- fetch only required columns
- paginate large results
- avoid repeated one-query-per-item patterns
- keep transactions focused

Example:

Instead of returning every order for a customer, return only:

```text
latest 20 orders
```

and support that query with an appropriate index.

#### Manage database connections

Applications normally use a **connection pool** instead of opening a new database connection for every request.

But a bigger pool is not always better.

If ten application instances each open too many database connections, the database can become overloaded.

Application scaling and database connection limits must therefore be considered together.

---

### Read replicas

If the system has much more **read traffic than write traffic**, read replicas can help.

A common setup is:

```text
           → Primary Database
Application
           → Read Replica
           → Read Replica
```

The **primary** handles writes.

Replicas copy data from the primary and can serve selected reads.

For an online store:

- creating an order → primary
- updating inventory → primary
- browsing product descriptions → read replica

Read replicas reduce read pressure on the primary.

They do **not** remove the primary write bottleneck.

---

### Replication lag and stale reads

Replication is often not instantaneous.

There may be a delay between:

```text
write accepted by primary
        ↓
change appears on replica
```

This is **replication lag**.

Suppose a user changes their delivery address. The update succeeds on the primary, but the next request reads from a replica that has not received the change yet.

The user may temporarily see the old address. This is a **stale read**.

A simple rule is:

- delay-tolerant reads can use replicas
- correctness-sensitive reads should use the primary

Example:

```text
Product catalog → replica is usually fine
Latest payment state → primary may be safer
```

A read replica is also not the same as a backup. An accidental deletion may quickly replicate to replicas too.

---

### When one database is no longer enough

Eventually one database may become limited by:

- total data size
- write throughput
- CPU
- storage
- one machine's capacity

At that point, the dataset may need to be divided.

#### Partitioning

Split a large dataset into smaller parts.

#### Sharding

Place those parts across multiple independently scaled database nodes.

Conceptually:

```text
Users A–F → Shard 1
Users G–M → Shard 2
Users N–Z → Shard 3
```

Sharding can increase total storage and write capacity.

But it also makes the system much more complicated, so it should be introduced only when one database is a measured limit.

---

### Common sharding approaches

Three common sharding approaches illustrate the main trade-offs.

#### Range-based sharding

Nearby key ranges go to the same shard.

```text
Customer IDs 1–1000    → Shard 1
Customer IDs 1001–2000 → Shard 2
```

Useful for range-based access.

Risk: sequential growth can overload one shard.

#### Hash-based sharding

Hash the shard key and use the result to choose a shard.

```text
hash(customer_id) → shard
```

This often spreads records more evenly.

Trade-off: some range queries may need several shards.

#### Geographic sharding

Place data according to region.

```text
India users → India shard
US users    → US shard
```

This can keep data closer to users or satisfy location requirements.

Risk: traffic may be uneven across regions.

---

### Choosing a shard key

The **shard key** decides where a record is stored.

A good shard key should:

- have many possible values
- distribute traffic reasonably evenly
- be available when routing common requests
- match important access patterns

Example:

```text
customer_id
```

may work well for an order system if common requests are:

```text
show orders for this customer
```

The system can directly determine which shard contains that customer's data.

A bad shard key can create a **hot shard**, where one shard receives much more traffic than others.

Even distribution of rows is not enough. Traffic distribution matters too.

---

### Scatter-gather queries

Sharding works best when a request includes the shard key.

```text
customer_id = 42
        ↓
route directly to one shard
```

But suppose the system asks:

```text
Show the 100 newest orders across every customer
```

The data may exist across all shards.

The system might need to:

1. query every shard
2. collect the results
3. combine and sort them

This is called **scatter-gather**.

Scatter-gather queries are more expensive than requests that can be routed directly to one shard.

---

### Sharding makes some operations harder

Before sharding, one database can handle many operations locally.

After sharding, data may live on different nodes.

This makes operations such as these harder:

- joins across shards
- transactions across shards
- global uniqueness
- global aggregation
- rebalancing data

Example:

```text
Get one customer's orders
```

can be easy if all of that customer's orders are on one shard.

But:

```text
Find the top-selling product across all customers
```

may require data from many shards.

Sharding solves capacity problems by accepting additional complexity.

---

### A practical scaling order

A practical scaling sequence is:

1. **Start simple**
2. **Measure the bottleneck**
3. **Scale vertically when that is enough**
4. **Add multiple stateless application instances when needed**
5. **Optimize database queries, indexes, and connections**
6. **Use read replicas when read traffic becomes the problem**
7. **Shard only when one database is still the real storage or write limit**
8. **Measure again**

Not every system reaches every step.

Some applications can run for years with:

```text
multiple application instances
        +
one strong relational database
```

Others may need replicas but never sharding.

The architecture should follow the workload.

---

### Key Takeaways

- Scaling starts by finding the current bottleneck.
- Vertical scaling makes one machine larger.
- Horizontal scaling adds more instances.
- Stateless application instances are easier to scale horizontally.
- Autoscaling helps with changing traffic but does not fix inefficient work.
- Database scaling usually starts with query, index, and connection improvements.
- Read replicas help read-heavy workloads.
- Replica lag can cause stale reads.
- Sharding distributes data and write load across multiple database nodes.
- The shard key determines how data and traffic are distributed.
- Poor shard keys can create hot shards.
- Queries without the shard key may require scatter-gather.
- Sharding adds complexity, so use it only when simpler approaches are no longer enough.

The overall mindset is:

```text
measure → improve → scale → measure again
```

---

## Chapter 7: Caching and High-Read Systems

Caching means storing a temporary copy of data or a computed result so repeated reads can be served faster.

Suppose a product page is requested thousands of times every minute.

Without caching:

```text
Request → Application → Database
```

With caching:

```text
Request → Cache
             ↓ miss
          Database
```

Caching mainly helps by:

- reducing response latency
- reducing load on databases or expensive services

A cache normally contains **derived data**, not the source of truth. If the cache disappears, the system should still be able to rebuild the data from the database or another authoritative source.

---

### Cache hit and cache miss

A cache lookup has two outcomes.

#### Cache hit

The value exists in the cache and can be returned immediately.

#### Cache miss

The value is missing or expired, so the system reads from the original source and may cache the result.

```text
Request → Cache miss → Database → Cache result → Return
```

A high hit ratio usually means less database work, but cached data must still be fresh enough for the business requirement.

---

### Where caching can happen

Caching can exist at several layers.

##### Browser or client cache

Useful for resources such as images, fonts, JavaScript, CSS, and some API responses.

##### CDN cache

Stores reusable content closer to users.

Good for:

- images and videos
- static files
- public pages
- public API responses

##### Application cache

The application may cache frequently requested values.

Example:

```text
product:42 → product details
```

A shared cache such as Redis can be used by multiple application instances.

The database remains authoritative.

---

### What should be cached?

Caching works best when:

- the same data is read repeatedly
- reads are much more frequent than writes
- the original lookup is expensive
- some staleness is acceptable
- the value can be regenerated

Good examples:

- product descriptions
- popular product lists
- configuration
- expensive computed summaries

Caching is a poor fit when:

- nearly every request asks for unique data
- the value changes constantly
- every read must see the newest value
- stale data can cause an incorrect decision

For example, caching a product description may be fine, while a final payment or bank-balance decision may require authoritative data.

The key question is:

> How stale may this value safely be?

---

### Cache keys

A **cache key** identifies a cached value.

Simple example:

```text
product:42
```

For more complex data, the key must include anything that changes the result.

```text
search:shoes:page=2:sort=price:currency=USD
```

For user-specific data, include the user or tenant identity.

Bad:

```text
dashboard
```

Better:

```text
user:51:dashboard
```

A bad cache key can return the wrong data to the wrong request.

---

### Cache-aside

**Cache-aside** is one of the most common caching patterns.

On a read:

1. Check the cache.
2. Return the value on a hit.
3. On a miss, read from the database.
4. Store the result in the cache.
5. Return the result.

Example:

```text
GET product 42
```

First request:

```text
Cache miss → Database → Cache product
```

Later requests:

```text
Cache hit → Return product
```

This reduces repeated database work.

---

### TTL and invalidation

A **TTL (Time to Live)** controls how long a cache entry remains before it expires.

Example:

```text
product:42
TTL = 5 minutes
```

##### Short TTL

- fresher data
- more cache misses
- more database traffic

##### Long TTL

- more cache hits
- less database traffic
- more possible staleness

Different data can use different TTLs.

```text
Country list → hours or days
Product description → minutes
Inventory hint → seconds
```

There is no universal correct TTL.

Another common strategy is **invalidate on write**:

```text
Update Database
      ↓
Delete Cached Value
      ↓
Next Read Loads Fresh Data
```

Many systems use both:

```text
invalidate on write
+
TTL as a safety net
```

---

### Cache stampede

Suppose one extremely popular cached value expires.

Thousands of requests arrive together, all miss the cache, and all query the database.

```text
Popular key expires
        ↓
Many cache misses
        ↓
Database overloaded
```

This is a **cache stampede** or **thundering herd**.

A common solution is to allow one request to refresh the value while others wait or temporarily use an older safe value.

The main lesson is:

> One hot cache miss can suddenly create large database load.

---

### What if the cache fails?

If a cache becomes unavailable, the application may fall back to the database.

```text
Cache unavailable → Database fallback
```

But if the cache normally handles most reads, suddenly sending everything to the database can overload it.

Basic protection may include:

- short cache timeouts
- controlled fallback
- rate limiting

The important idea is:

> Cache failure can move a large amount of traffic back to the source.

---

### CDN vs application cache vs read replica

These all help read-heavy systems, but they solve different problems.

| Mechanism | Best fit |
|---|---|
| CDN | Public/static content close to users |
| Application cache | Repeated application-level lookups |
| Read replica | Larger sets of database read queries |

Example:

```text
CDN → product images
Application cache → product summaries
Read replica → catalog queries
```

Use each only when it solves a real problem.

---

### What should we measure?

After adding a cache, verify that it actually improves the read path.

Useful operational signals are:

- cache hit ratio
- cache lookup latency
- request latency for hits and misses
- database load caused by misses
- whether important values become stale too often

A high hit ratio alone is not enough. A cache that is fast but returns data that is too stale is still a bad design.

The goal is:

```text
faster reads
+ lower database load
+ acceptable freshness
```

### When caching is the wrong solution

Caching should not be added automatically.

It may be unnecessary when:

- the database is already fast enough
- values are rarely reused
- data changes too frequently
- every read must be fully current
- the real problem is an inefficient query

Example:

If a product query is slow because an index is missing, adding Redis may hide the problem instead of fixing it.

Fix the actual bottleneck first.

---

### Key Takeaways

- A cache stores temporary, reusable data.
- The database or another authoritative source remains the source of truth.
- A cache hit avoids repeated expensive work.
- A cache miss falls back to the original source.
- Browser caches, CDNs, application caches, and read replicas solve different problems.
- Cache keys must include all inputs that change the result.
- Cache-aside is a common and practical caching pattern.
- TTL controls how long data stays cached.
- Invalidation removes stale cached data after writes.
- A hot-key expiration can cause a cache stampede.
- Cache failure can suddenly increase database load.
- Caching should solve a measured read problem, not hide inefficient queries.

The main trade-off is:

```text
faster reads + lower database load
              ↕
staleness + memory + extra complexity
```

---

## Chapter 8: Queues, Events, and Asynchronous Systems

Some backend work finishes quickly and can stay inside the normal request-response flow.

Other work may take seconds or minutes:

- generating reports
- processing uploaded files
- resizing images
- sending emails
- calling slow third-party systems

Keeping the original HTTP request open for all of this can cause timeouts and tie up application resources.

An **asynchronous system** separates:

```text
accepting work
from
completing work
```

The system accepts the request, stores the work somewhere durable, returns quickly, and completes the operation later.

---

### Synchronous vs asynchronous

#### Synchronous

The caller waits for the final result.

```text
Request → Do Work → Return Result
```

Use this when:

- the work is fast
- the result is needed immediately
- failures should be returned immediately

Example:

```text
Get user profile
```

---

#### Asynchronous

The caller does not wait for the full operation.

```text
Request → Accept Job → Return Job ID
                    ↓
                Process Later
```

Good candidates include:

- sending emails
- generating reports
- video processing
- imports
- analytics
- background notifications

Moving work to a queue does **not** remove the work. It only changes when and where it happens.

---

### Core queue components

A queue-based system usually has four important parts.

##### Producer

Creates the work.

Example:

```text
API Server
```

##### Message

Describes what needs to happen.

Example:

```text
Generate report for user 42
```

##### Queue or broker

Stores and delivers messages.

Examples include RabbitMQ, SQS, and similar messaging systems.

##### Consumer or worker

Reads messages and performs the actual work.

Conceptually:

```text
Producer → Queue → Worker
```

The producer does not need to know which worker will process the job.

This creates **decoupling** between the component creating work and the component completing it.

---

### Background job lifecycle

Suppose generating a report takes two minutes.

The API should not keep the client waiting for two minutes.

A better flow is:

1. Client requests a report.
2. API creates a job.
3. Job is added to the queue.
4. API returns `202 Accepted` with a job ID.
5. Worker processes the job.
6. Job becomes `succeeded` or `failed`.
7. Client checks the job status.

Example response:

```json
{
  "jobId": "job_123",
  "status": "pending"
}
```

The job may move through:

```text
pending → running → succeeded
                  ↘ failed
```

Important:

> `202 Accepted` means the work was accepted for processing. It does not mean the work succeeded.

---

### Queues as a traffic buffer

Queues are very useful when work arrives faster than it can be processed for a short period.

Suppose:

```text
50,000 images uploaded quickly
```

but workers can safely process only:

```text
2,000 images per minute
```

Without a queue, the processing service may be overwhelmed.

With a queue:

```text
Uploads → Queue → Workers
```

The queue absorbs the temporary spike and workers process jobs at a controlled rate.

But a queue does not create infinite capacity.

If jobs continuously arrive faster than workers can finish them, the backlog keeps growing.

Useful operational metrics are:

- queue depth
- oldest message age
- arrival rate
- processing rate

---

### Queue vs publish/subscribe vs event stream

These patterns solve different problems.

#### Work queue

One worker handles each job.

```text
Producer → Queue → One Worker
```

Good for:

- image processing
- report generation
- imports
- background jobs

Multiple workers can share the queue to increase throughput.

---

#### Publish/subscribe

One event can be delivered to several independent consumers.

Example:

```text
Order Placed
   ↓
Email Service
Analytics Service
Fulfillment Service
```

Each consumer reacts independently.

This is useful when multiple systems care about the same event.

---

#### Event stream

An event stream keeps a history of events that consumers can read and sometimes replay.

Useful when:

- event history matters
- replay is useful
- consumers process events independently

The simplest distinction is:

```text
Queue → one worker handles the job
Pub/Sub → many subscribers react
Stream → events are retained for later reading/replay
```

---

### Commands vs events

A **command** asks for something to happen.

Examples:

```text
GenerateReport
SendEmail
ReserveInventory
```

An **event** says that something already happened.

Examples:

```text
OrderPlaced
PaymentReceived
ProductPriceChanged
```

The difference is useful:

```text
Command → please do this
Event   → this happened
```

Events help services stay loosely coupled because the producer does not need to know every consumer that may react.

---

### Retries and backoff

Background work can fail.

Some failures are temporary:

- network timeout
- temporary database issue
- third-party service unavailable

Retrying later may succeed.

Other failures are permanent:

- invalid input
- unsupported file
- malformed email address

Retrying the exact same bad message forever does not help.

Retries should therefore be limited.

A common approach is **exponential backoff**:

```text
Retry after 1s
Retry after 2s
Retry after 4s
Retry after 8s
Stop after a limit
```

This gives the failed dependency time to recover instead of repeatedly hammering it.

---

### Dead-letter queue

After a message fails too many times, it may be moved to a **dead-letter queue (DLQ)**.

```text
Normal Queue
    ↓ repeated failure
Dead-Letter Queue
```

The DLQ holds messages that require investigation.

Typical reasons include:

- invalid data
- permanent dependency failure
- too many retry attempts

A DLQ should not be treated as a trash bin.

Someone should be able to inspect failed messages, fix the cause, and retry them safely when appropriate.

---

### Duplicate delivery

A worker may successfully perform the business operation but crash before telling the queue that the message completed.

Example:

1. Worker receives payment message.
2. Payment succeeds.
3. Worker crashes.
4. Queue does not know it succeeded.
5. Queue delivers the message again.

Now the same logical operation may run twice.

This is why many messaging systems use **at-least-once delivery**:

```text
message should not be silently lost
but
duplicates may happen
```

The application must be prepared for duplicate delivery.

---

### Idempotent consumers

A consumer is **idempotent** when processing the same logical message more than once does not create extra business effects.

Example:

Bad:

```text
Add ₹500 to balance
```

Running it twice adds ₹1,000.

Safer idea:

```text
Process payment ID payment_9182 once
```

The system can store the message or operation ID and check whether it has already been processed.

Conceptually:

```text
Receive Message
      ↓
Already Processed?
   ↓ yes      ↓ no
 Ignore     Process
```

This is especially important for:

- payments
- orders
- inventory
- account changes

The essential idea is:

> Queues may deliver duplicates, so important consumers should be safe to run more than once.

---

### Ordering

Parallel workers improve throughput because many messages can be processed at the same time.

Strict global ordering reduces that parallelism.

Often, only related messages need ordering.

Example:

```text
Order 42 updates → keep in order
Order 99 updates → can run independently
```

So ordering is usually applied only where the business rule requires it.

Do not require global ordering unless it is truly necessary.

---

### When asynchronous systems are the wrong choice

Queues and events add infrastructure and more failure states.

Do not use them automatically.

Synchronous communication may be better when:

- the operation is already fast
- the caller needs the result immediately
- traffic is small and predictable
- failure must be reported immediately
- adding a queue and worker system creates more complexity than value

Example:

Fetching a user profile does not need a queue.

The simplest design that meets the requirement is usually the better starting point.

---

### Key Takeaways

- Asynchronous processing separates accepting work from completing work.
- `202 Accepted` means accepted for processing, not completed.
- Producers create messages, queues store them, and workers process them.
- Queues can absorb temporary traffic spikes.
- A work queue sends each job to one worker.
- Pub/sub allows multiple subscribers to react to one event.
- Streams retain events for later reading or replay.
- Commands ask for an action; events describe something that happened.
- Temporary failures can be retried with backoff.
- Repeated failures may move to a dead-letter queue.
- Messaging systems may deliver duplicates.
- Idempotent consumers make duplicate processing safe.
- Strict ordering reduces parallelism, so require it only where necessary.
- Use asynchronous architecture only when its decoupling, buffering, or background-processing benefit justifies the extra complexity.

The core mental model is:

```text
Producer → Queue → Worker
```

and the core reliability rule is:

```text
messages may be retried
→ consumers must handle repetition safely
```

---

## Chapter 9: Architecture and Reusable Design Patterns

System architecture describes how a system is divided into parts, how those parts communicate, and who owns each responsibility.

There is no universally best architecture.

The goal is:

```text
understand the problem
        ↓
choose the simplest useful structure
```

---

### Architecture is about boundaries

A **boundary** defines what belongs together.

For an online store, possible business areas are:

- catalog
- orders
- payments
- users
- fulfillment

A useful boundary should make it clear:

- who owns the business logic
- who owns the data
- how other parts interact with it
- whether it can change independently

Good boundaries reduce unnecessary coupling.

---

### Monolith

A **monolith** is mainly built and deployed as one application.

Example:

```text
Application
├── Catalog
├── Orders
├── Payments
└── Users
```

Advantages:

- simple deployment
- easy local development
- fast in-process calls
- easier debugging
- fewer network failures

Possible problems as it grows:

- code can become tangled
- the whole application deploys together
- one heavy feature can affect the whole process
- the whole application usually scales together

A monolith is not automatically bad.

It can still be well structured and horizontally scaled.

---

### Modular monolith

A **modular monolith** keeps one deployment but organizes the code into clear business modules.

Example:

```text
One Application

Catalog Module
Order Module
Payment Module
User Module
```

Each module should own a clear responsibility and expose a small interface.

This gives clearer ownership without introducing network calls between every part of the system.

For many applications, this is an excellent starting point.

The main requirement is discipline.

If every module directly accesses every other module's internals or tables, the boundaries are not real.

---

### Microservices

A **microservices architecture** splits the system into independently deployed services.

Example:

```text
Catalog Service
Order Service
Payment Service
User Service
```

Potential benefits:

- independent deployment
- independent scaling
- clearer team ownership
- stronger separation

But the cost is much higher:

- network latency
- partial failures
- timeouts and retries
- harder debugging
- more deployments
- harder data consistency
- more monitoring and operations

Microservices are useful when that independence solves a real problem.

They should not be introduced just because a system has grown.

---

### Comparing the three

| Architecture | Deployment | Communication | Complexity |
|---|---|---|---|
| Monolith | One unit | In-process | Lowest |
| Modular monolith | One unit | Module interfaces | Low |
| Microservices | Many units | Network / events | Highest |

A common sensible approach is:

```text
start simple
   ↓
create clear modules
   ↓
extract a service only when there is a real need
```

A modular monolith may remain the correct architecture permanently.

---

### Choosing service boundaries

Services should usually follow **business capabilities**, not technical layers.

Bad example:

```text
Controller Service
Business Logic Service
Database Service
```

These parts usually change together.

Better:

```text
Order Service
Payment Service
Catalog Service
```

A good service boundary usually has:

- one clear business responsibility
- clear data ownership
- a small interface
- mostly independent changes
- a real reason for separate deployment or scaling

If two services always deploy together and share the same tables, the split is probably not useful.

---

### Distributed monolith

A **distributed monolith** is a system with many services that are still tightly coupled.

Common signs:

- one request passes through many services
- services share the same database tables
- many services must deploy together
- one small service failure breaks the entire flow

This creates the complexity of microservices without gaining real independence.

The lesson is:

> More services do not automatically mean better architecture.

---

### Synchronous vs asynchronous communication

Use **synchronous communication** when the caller needs an immediate answer.

Example:

```text
Checkout → Payment Authorization
```

Use **asynchronous communication** when work can happen later or several consumers can react independently.

Example:

```text
Order Placed
   ↓
Email
Analytics
Fulfillment
```

Simple rule:

```text
Need result now → synchronous
Can happen later → asynchronous
```

---

### Reuse patterns only when they solve a problem

Patterns from earlier sections should be selected from the workload.

Examples:

```text
Repeated slow reads → indexes, then cache if needed

Bursty background work → queue + workers

Large file transfer → object storage

Realtime updates → polling first, then SSE/WebSocket if needed
```

Do not add several patterns at once just because they are common in large systems.

---

### Avoid overengineering

Overengineering means paying for complexity before the need exists.

Examples:

- adding Redis before measuring read pressure
- creating many microservices without independent ownership
- using events for a simple immediate operation
- adding several databases without clear access patterns
- using WebSockets when polling is enough

Every new component adds:

- another failure mode
- another deployment
- another thing to monitor
- another thing the team must understand

The simplest architecture that meets the current requirement is usually the best starting point.

---

### Key Takeaways

- Architecture is mainly about boundaries, ownership, and communication.
- A monolith can still be clean and scalable.
- A modular monolith gives clear boundaries without distributed-system complexity.
- Microservices add independence but also much more operational complexity.
- Service boundaries should follow business capabilities.
- Avoid the distributed-monolith trap.
- Use synchronous communication for immediate decisions.
- Use asynchronous communication for delayed or independent work.
- Reuse caching, queues, object storage, and realtime patterns only when they solve a measured problem.
- Start simple and evolve only when there is a clear reason.

The core principle is:

```text
start simple
   ↓
create clear boundaries
   ↓
add complexity only when justified
```

---

## Chapter 10: Production-Ready Systems

A system is not production-ready just because the normal request flow works.

It should also be:

- observable
- secure
- recoverable
- safe to deploy
- able to handle failures

The goal is:

```text
detect problems
   ↓
limit impact
   ↓
recover safely
```

---

### Observability

Observability means understanding what the system is doing.

The three main signals are:

#### Logs

Logs record individual events.

Examples:

```text
payment failed
order created
authentication rejected
```

Useful logs should include context such as:

- timestamp
- service
- request or correlation ID
- error code

Do not log passwords, access tokens, or sensitive payment data.

#### Metrics

Metrics show numeric behavior over time.

Examples:

- request rate
- error rate
- latency
- CPU and memory
- database connections
- queue depth
- cache hit ratio

#### Traces

A trace follows one request across components.

```text
Client → Order Service → Payment Service → Database
```

Simple mental model:

```text
Logs → what happened?
Metrics → is something wrong?
Traces → where did it go wrong?
```

---

### Health checks

A process can be running but still not be ready to serve traffic.

#### Liveness

Checks whether the process is alive.

If not, it may need to restart.

#### Readiness

Checks whether the instance can safely receive traffic.

If not, the load balancer should temporarily stop sending requests to it.

Health checks should be fast and meaningful.

---

### Basic security

#### Authentication

Answers:

> Who is calling?

#### Authorization

Answers:

> What is this identity allowed to do?

A logged-in user should not automatically be allowed to access every order or account.

Authorization must be enforced on the server.

Also follow basic rules:

- validate external input
- limit payload and file sizes
- give services only the permissions they need
- do not hardcode passwords or API keys
- use TLS for data in transit

---

### Backups and recovery

A backup is a separate copy used to recover data after:

- deletion
- corruption
- security incidents
- major failure

A backup is useful only if it can actually be restored.

Restore testing matters.

Two useful terms are:

#### RPO

**Recovery Point Objective** = how much data loss is acceptable.

Example:

```text
RPO = 15 minutes
```

#### RTO

**Recovery Time Objective** = how long recovery may take.

Example:

```text
RTO = 1 hour
```

Smaller RPO and RTO usually cost more.

---

### Safe deployments

New code can break a working system.

Production deployments should reduce how many users are exposed before confidence grows.

Common approaches:

##### Rolling

Replace old instances gradually.

##### Canary

Send a small amount of traffic to the new version first.

```text
95% → old version
5%  → new version
```

If errors or latency increase, stop or roll back.

##### Blue-green

Keep old and new environments separately, then switch traffic when the new version is ready.

The operational lesson is:

> Do not expose every user to a new release at once.

---

### Backward compatibility

During deployment, old and new versions may run together.

APIs and database schemas should not immediately break the older version.

Safer changes include:

- adding optional API fields
- supporting old and new formats temporarily
- adding a new database column before removing the old one

Example:

```text
add new structure
      ↓
deploy compatible code
      ↓
move data
      ↓
remove old structure later
```

---

### Redundancy and failover

Running several application instances reduces the risk of one process stopping the whole service.

```text
Load Balancer
   ↓
App 1
App 2
App 3
```

If one instance fails, traffic can continue to healthy instances.

For higher availability, instances may also run in different availability zones.

Multi-region systems are much more complex and should be introduced only for a real requirement.

---

### Key Takeaways

- Production readiness means being able to observe, protect, deploy, and recover a system safely.
- Logs explain events.
- Metrics show system behavior over time.
- Traces follow requests across components.
- Liveness checks whether a process is alive.
- Readiness decides whether it should receive traffic.
- Authentication identifies the caller.
- Authorization controls permitted actions.
- Validate untrusted input and protect secrets.
- Backups should be tested through restore.
- RPO defines acceptable data loss.
- RTO defines acceptable recovery time.
- Rolling, canary, and blue-green deployments reduce release risk.
- API and database changes should remain compatible while versions coexist.
- Redundancy helps the system survive selected failures.

The core production mindset is:

```text
observe
protect
deploy safely
recover
```

---

## Closing Perspective

Good system design is an evidence-driven process rather than a fixed architecture template. Requirements define what must be true. Workloads reveal where pressure appears. Estimates establish rough scale. Measurements identify bottlenecks. Each architectural change should solve a specific problem while making its new trade-offs explicit.

A design is therefore never “scalable” or “reliable” in the abstract. It is scalable for a particular workload dimension, reliable against particular failure modes, and consistent enough for particular business operations. The most durable skill is the ability to connect those requirements to concrete architectural decisions and to evolve the system only when the evidence justifies the next step.
