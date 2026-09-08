
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

<!-- 57 min -->