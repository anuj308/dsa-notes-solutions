
# system design fundamental & mindset
- system design is a process of deciding how the parts of your software systems should work together to satisfy a set of requirements.

![alt text](image.png)

- there is no single universal correct architecture

- each architecture starts with a requirement

- functional requirement:
    - like:
    - browser list of product
    - view the details of the product
    - place an order and view status of my orders

    - describe what user and other system must be able to do
    - it tells your initial scope of your system

- non functional requirement:
    - like: 
    - my product page should normally load quickly
    - if an order is confirmed that order must not disappear
    - 2 retries of same order should not create two orders

    - describe how well the system must operate and under which conditions

- constraints
    - limit within which system must operate
    - small engineering team
    - limited infra budgets
    - launch date
    - legal requirement
![alt text](image-1.png)


# workload and access patterns

- workload - describe the work placing on system
- access patterns - how the system data is created, read, updated, deleted


- read operations
    - list product
    - open a product page

- write operations
    - create an order
    - update the inventory/stock

- read / write balance
- read heavy like an news website, catolog website
- write heavy like tracking user activity on site



# core quality attributes

![alt text](image-2.png)

- consistency 
    - like admin change product price so how much delay is accepted 2s, 5s, or immediate etc to reflect in user pages

# latency, throughput, and bandwidth

![alt text](image-3.png) 

- latency reason

![alt text](image-4.png)

# bottlenecks
- resource or dependency that reaches its usefull limit first for that current worload
- like apllication server - 1000 request/s and db has 300 request/s do here db is bottlenecks

![alt text](image-5.png)

![alt text](image-6.png)

![alt text](image-7.png)

# system design interview framework & estimation

![alt text](image-8.png)
![alt text](image-9.png)

![alt text](image-10.png)
![alt text](image-11.png)

![alt text](image-12.png)

![alt text](image-13.png)

![alt text](image-14.png)

![alt text](image-15.png)

![alt text](image-16.png)

![alt text](image-17.png)

- rounded input to find the approx size of the workload

# average  & peak QPS & read/write ratio
- qps - queries/request per second
- avg Qps - daliy traffic
- avg Qps = request per day / seconds per day

- 10m product views/day
- avg qps = 10000000 / 86400 = 116 Req/sec
- approx qps = 10000000 / 100000 = 100 Req/sec
- peak qps = 116*10 = 1160 Req/sec
- approx peak qps = 1200 Req/sec

- read and write ratio
- read req = 10M /day
- write req = 100000/day
- ratio = 100 : 1


- storage 
- raw storage = write per sec * items size * retention
-             =  100000 * 2kb = 200Mb/day = 78 Gb/year


# bandwidth and data transfer & concurrent users and connections

- bandwidth = request per second * bytes per request
- a proudct receive 1200 req/s and return 20kb json data
- bandwidth = 1200 * 20 kb = 24000 kb/sec = 24 MB/sec = 192 megabit/sec

- concurrency - how many operations sesion, connections are active at same time
- concurrency = arrival rate * avg duration
-             = 1200 * 0.2 sec = 240 infligt request


# revise
1. define actors,core use cases, exclusions
2. clarify the quality requirements and the constraints
3. identify core entities and access patterns
4. design high level api and very imp dataflows
5. start with very simple high level design HLD
6. estimate traffic, storage, bandwidth, concurrency -> help on making decison
7. find the bottleneck and try to implement the solution from it and discuss the trade off
8. calculate avg qps, peak qps, read vs write ratio, stroage growth -> if applicable to that question
9. bandwidth, data transfer etc


# 
![alt text](image-18.png)

- client ->   
- not every system need all the above components
- https://         shop.com  /product/43
- protocol scheme  hostname  resource path

 ![alt text](image-19.png)


 - ip address - identity the network destination
 - port - identity the service runing at that destination
 - redis(6379), postgress(5932), web server(443)

 ![alt text](image-20.png)
![alt text](image-21.png)
![alt text](image-22.png)

# tls and https
- https = http protected by tls

# http request and responses
- a normal http request contains:
    - method : what operation the client wants
    - path : which resource is targeted
    - headers : metadata
    - body : optional data sent to the server

- example:
    - post /orders http 1.1
    - host : shop.example.com
    - content type : application/json
    - {productid :42, quantity:1}
- Get - retrive data
- post - create or submit the data
- put/patch - update the data
- delete - remove the data

- http response contains:
    - status code
    - headers
    - optional body
     
- example:
    - http 1.1 200 ok
    - content type : application/json
    - {body}

- status code groups:
    - 2xx - success
    - 3xx - redirection
    - 4xx - client side problem
    - 5xx - server side problem

- usefull example:
    - 200 ok - request succeeded
    - 201 Created - request created
    - 400 Bad request - invalid request
    - 401 unauthorized - authentication required or failed
    - 403 forbidden - authentication but not allowed
    - 404 not found - resource not found
    - 500 Intenal server Error - unexpected server failure
    - 503 service  unavailable - service temporarily unavialable

#  Reverse Proxy and cdn
- client -> Reverse Proxy -> backend server
- The client does not need to know which internal server handles the request

- Cdn - a content delivery Network runs servers at locations closer to users.
- it is commonly used for content such as:
    - images
    - Javascript and css files
    - videos
    - other static content

- the application performs the work
    - get /product/42
    1. validate the request
    2. check authentication or permissions if required
    3. query the database for product 42
    4. create the http response

- application -> database : find product 42
- database -> application : product data
- application -> client : 200 ok + product data

# latency add up
- dns + connection setup + tls handshake  + network travel + application processing + database or service calls + response travel

# network calls can fail
- dns resolution fail
- the connection cannot be established
- tls negotiation fails
- the server is unavailable
- a dependency is slow
- the request times out
- the response is lost

# Final mental model
- who creates the request? Client
- how is the destination found? DNS
- where is the request sent? Ip address + port
- how data travel? tcp or udp
- how is connection protected? tls/https
- what does the application message contains? http
- which public infrastruture receives it? CDN, reverse proxy, or load balancer
- where is the business logic executed? application server
- where does persistent data comes from? Database or another data service
- where can latency or failure occur? at every network boundary

# api and communications patterns
- an api defines that contract:
    - what operations are available
    - what input is required
    - what output is returned
    - how error are represented


![alt text](image-23.png)
![alt text](image-24.png)
![alt text](image-25.png)

# idempotency
- an operation is idempotent when repeating the same logical request produces the same intented business effect
![alt text](image-26.png)

# request and response contract
![alt text](image-27.png)

# Authentication and authorization
- authentication - who are you?
- authorization - are you allowed to do this?

![alt text](image-28.png)

- m1 m2 are middlware
- p is product 
- last one is admin
![alt text](image-29.png)

![alt text](image-30.png)

# pagination
- database work
- without it: a lot of
    - memory
    - network bandwith
    - client processing

- types:
    - offset pagination : GET /product?limit=20&offset=40
    - cursor pagination : GET /product?limit=20&cursor=abc123

    - beginer rule:
        - small/simple collection -> offset
        - large/changing feed -> cursor

# REST vs gRPC vs GraphQl
![alt text](image-32.png)
- graphQl
    - strong fit for when clients need flexiable combinations of related data

![alt text](image-31.png)

![alt text](image-33.png)
![alt text](image-34.png)
![alt text](image-35.png)

# polling
![alt text](image-36.png)
![alt text](image-37.png)

# webSockets
![alt text](image-38.png)

# webhooks
![alt text](image-39.png)
![alt text](image-40.png)

![alt text](image-41.png)

# what communication do we need?
![alt text](image-42.png)
![alt text](image-43.png)

# 

![alt text](image-44.png)
![alt text](image-45.png)
![alt text](image-46.png)
![alt text](image-47.png)


![alt text](image-48.png)
![alt text](image-49.png)
![alt text](image-50.png)
![alt text](image-51.png)
![alt text](image-52.png)
![alt text](image-53.png)
![alt text](image-54.png)
![alt text](image-55.png)
![alt text](image-56.png)


# choose a database
![alt text](image-57.png)
![alt text](image-58.png)


# scaling mindset
![alt text](image-59.png)
![alt text](image-60.png)
![alt text](image-61.png)
![alt text](image-63.png)
![alt text](image-62.png)

# auto scaling
![alt text](image-64.png)
![alt text](image-65.png)

# database becomes bottleneck
![alt text](image-66.png)
![alt text](image-67.png)

# optimize the database first
![alt text](image-68.png)
![alt text](image-69.png)

# read replica
![alt text](image-71.png)
![alt text](image-70.png)

# replication lag
![alt text](image-72.png)
![alt text](image-73.png)

# partitioning and sharding
![alt text](image-74.png)
![alt text](image-75.png)
![alt text](image-76.png)

# pratical scaling order
![alt text](image-77.png)
- 8. measure again
![alt text](image-78.png)

# what caching does
![alt text](image-79.png)
![alt text](image-80.png)

# cache hit & miss
![alt text](image-81.png)
- cache data must still be fresh enough

# where caching happens
![alt text](image-82.png)
- application layer caching

# what should be cached?
![alt text](image-83.png)
![alt text](image-84.png)

# cache key 
- it identify a cached value
- for complex result, include everything that changes the result
![alt text](image-85.png)

# time to live(ttl) and cache invalidation
![alt text](image-86.png)
![alt text](image-87.png)

![alt text](image-88.png)
![alt text](image-89.png)

# cache failure - all load can go to database and can crash
![alt text](image-90.png)

# cdn & cache & read replica

- cdn - best for public/static content close to users, example - product images
- application cache - best for repeated application-level lookups, example - product summaries
- read replica - best for database read queries, example - catalog queries

# do not cache automatically
![alt text](image-91.png)

# synchronous vs asynchronous
![alt text](image-92.png)
![alt text](image-93.png)


![alt text](image-94.png)
![alt text](image-95.png)

# background lifecycle
![alt text](image-96.png)

# queue vs pub/sub vs stream
![alt text](image-97.png)
![alt text](image-98.png)
![alt text](image-99.png)
- event stream - keeps histroy of events so comsumer can read or replay
![alt text](image-100.png)

![alt text](image-101.png)
![alt text](image-102.png)
![alt text](image-103.png)

# commands vs events
- commands - asks for something to happen - please do this
    - example - generate report,sendEmail,ReserveInventory

- events - says something already happened
    - example - order placed, payment received, product price changed

# retries and backoff
- Background jobs can fail
- Temporary failures:
    - network timeout
    - temporary database issue
    - third-party service unavailable

- retry may work

- permanent failures:
    - invalid input
    - unsupported file
    - malformed data

    - here retrying forver will not work

- common approch: exponential backoff
    - Retry after 1s
    - Retry after 2s
    - Retry after 4s
    - Retry after 8s
    - stop after a limit

    - this is know as exponential backoff

    - goal is to give the failing dependency time to recover


# Dead letter queue
- retry -> retry -> too many failure -> dead letter queue
- DLQ store messages that require investigation
- comman reason: 
    - invalid data
    - permanent failure
    - retry limit exceed

- DLQ is not a trash bin
- failed message should be:
    - inspect
        - fix cause
        - retry safely when appropriate

# Duplicate delivery
![alt text](image-104.png)
![alt text](image-105.png)
![alt text](image-106.png)

- example:
    - worker recives payement message
    - payment succeeds
    - worker crashes before acknowledging
    - queue thinks messages was not completed
    - message delivered again

    - result: same logical operation may run twice
    - many system uses: atleast once delivery
    - meaning - avoid silently losing messages but duplicate may happen
    - therefore :  application must be prepared for dulpicate delivery

# Idempotent Consumers
- Processing the same logical message multiple times does not create extra business effects.

- bad: add 500 to balance -> run twice 1000 will be added
- safer: Process payment id payment_2738 once
- flow: 
    - Receive Message
    -      |
    - already processed?
    - yes       no
    - Ignore   process

- common approch: store message / operation Id and check if it was already processed.
- Especially important for:
    - payments
    - orders
    - inventory
    - account changes

- Core rule:
    - Queue may deliver duplicate 
        - important consumers should be safe to run more than once

# when not to use async systems
- queue and events add:
    - more infrastructure
    - more failure states
    - retries
    - duplicate handling
    - monitoring complexity

- Synchronous communication may be better when:
    - operation is already fast
    - caller needs the result immediately
    - traffic is small and predictable
    - failure must be returned immediately
    - queue + worker adds more complexity than value

- example:
    - fetching a user profile
    - request -> application -> database -> response
    - no queue needed

- core mental model:
    - Producer -> Queue -> Worker

- core reliability rule:
    - messages may be retried
        - consumers must handle repetition safely

# Architecture is about boundaries
- system architecture describe how a system is divided into parts, how those part are going to communicate and who owns each responsibility.

- good boundaries make ownership clear and reduce unnecessary coupling.
- core rule:
    - understand the problem
    - choose the simplest useful structure


# Monolith
- one application, usually deployed as one unit.
- application:
    - catalog
    - orders
    - payments
    - users

- advantages:
    - simple deployment
    - easy local development
    - fast in process calls
    - easier debugging
    - few network failures

- Possiable problems as it grows
    - code can become tangled
    - everything deploys together
    - one heavy feature can affect the whole process
    - whole application often scales together

![alt text](image-107.png)

# modular monolith
- one deployment
- clear business modules

- one application
    - catalog module
    - order module
    - payment module
    - user module

- each module should:
    - own a clear responsibility
    - expose a small interface
    - avoid depending on internal details of others modules

- Benefit:
    - clear boundaries without network calls between every part

- for many application this is an excellent starting point
- but boundaries need discipline

- if every module accesses every other module internal or tables, the modules are not truly separate.

# Microservices
- Split system into independent deployed services.
- example: 
    - catalog module
    - order module
    - payment module
    - user module

- Potential benefits:
    - independent deployment
    - independent scaling
    - clearer team ownership
    - stronger separation

- costs:
    - network latency
    - partial failures
    - timeouts and retries
    - harder debugging
    - more deployments
    - harder data consistency
    - more monitoring and operations

- use microservies when independence solves a real problem

# monolith vs modular monolith vs Microservices
![alt text](image-108.png)
![alt text](image-109.png)
![alt text](image-110.png)

# chossing service boundaries
- bad:
    - controller service
    - business logic service
    - database service

    - these usually change together

- better:
    - order service
    - payment service
    - catalog service

- a better service boundary usually has:
    - one clear busineess responsibility
    - clear data ownership
    - a small interface
    - mostly independent changes
    - a real reason for separate deployment or scaling

- warning:
    - if two services:
        - always deploy together
        - share the same tables
        - cannot change idenpendently

        - then the split is probably not usefull

# distributed monolith
- many services + still tightly coupled
- common signs:
    - one request passes through many services
    - services share database tables
    - many services must deploy together
    - one small service failure breaks the whole flow

- result:
    - microservice complexity with microservice independence

- main lesson:
    - more services does not automatically means better architecture

# Reuse patterns only when needed
- choose patterns from the workload
- example:  
    - repeated slow reads
        - indexes first
        - cache if needed

    - busty background jobs
        - queue + workers
    
    - large file transfer
        - object storage

    - realtime updates
        - polling first
        - SSE / websocket if needed

- do not add patterns just because large system use them
- every patterns should solve a specific problem

# avoid overengineering
![alt text](image-111.png)

- Every new components adds:
    - another failure mode
    - another deployment
    - another thing to mointor
    - another thing the team must understand

- core principle:
    - start simple
    - create clear boundaries
    - add complexity only when justified

# production ready mindset

![alt text](image-112.png)
![alt text](image-113.png)
- observability - what an system is doing
- log - record individual events
- error code , timestamp, reqId etc include in your log

![alt text](image-114.png)
![alt text](image-115.png)

# health checks 
- a process can be runing but still not be ready for traffic.
- liveness : is process alive? No, restart it
- readiness : can this instance safely receive traffic? No, load balance stop sending request

- simple:
    - liveness - should it be runing?
    - readiness - should it receive traffic?

# Security
![alt text](image-116.png)
![alt text](image-117.png)

# backup and recovery 
- backup is separate copy
- it help in:
    - deletion
    - corruption
    - security incidents
    - major failures

- important:
    - backup created != recovery granted
    - restore testing matters.

- RPO:
    - Recovery Point Objective
    - how much data loss is acceptable
    - example:
        - rpo is 15 minutes

- RTO:
    - Recovery time objective
    - how long many recovery take?
    - Example: 
        - RTO is 1 hour

- smaller RPO/RTO
    - usually higher cost

# safe deployments

- New code can break a working system
- Do not expose very user to a new version immediately

- polling
- replace old instances gradually

- canary
- 95% - old version
- 5% - new version

- watch:
    - erros
    - latency

- Problems
    - stop / roll back

- blue- green
    - old Environment
    - new Enviroment

- prepare new version
    - switch when ready

- Main idea:
    - small exposure first
        - confidence grows
        - increase traffic

# final production checklist
![alt text](image-118.png)
![alt text](image-119.png)

