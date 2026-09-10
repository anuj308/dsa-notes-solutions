
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

<!-- 2 : 59 -->