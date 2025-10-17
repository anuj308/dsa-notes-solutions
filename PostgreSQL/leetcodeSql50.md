# LeetCode SQL 50

## Study Plan Link
🔗 [https://leetcode.com/studyplan/top-sql-50/](https://leetcode.com/studyplan/top-sql-50/)

---

## 1. Recyclable and Low Fat Products
**Problem:** [https://leetcode.com/problems/recyclable-and-low-fat-products/](https://leetcode.com/problems/recyclable-and-low-fat-products/)

```sql
select product_id 
from Products 
where low_fats = 'Y' and recyclable = 'Y';
```

---

## 2. Find Customer Referee
**Problem:** [https://leetcode.com/problems/find-customer-referee/](https://leetcode.com/problems/find-customer-referee/)

```sql
select name 
from Customer 
where referee_id != '2' or referee_id is null;
```

---

## 3. Big Countries
**Problem:** [https://leetcode.com/problems/big-countries/](https://leetcode.com/problems/big-countries/)

```sql
select name, population, area 
from World 
where area >= 3000000 or population >= 25000000;
```

---

## 4. Article Views I
**Problem:** [https://leetcode.com/problems/article-views-i/](https://leetcode.com/problems/article-views-i/)

```sql
SELECT DISTINCT author_id AS id 
from Views 
where author_id = viewer_id 
ORDER BY author_id ASC;
```

---

## 5. Invalid Tweets
**Problem:** [https://leetcode.com/problems/invalid-tweets/](https://leetcode.com/problems/invalid-tweets/)

```sql
SELECT TWEET_ID 
from TWEETS 
WHERE LENGTH(CONTENT) > 15;
```

---

## 6. Replace Employee ID With The Unique Identifier
**Problem:** [https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/](https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/)

```sql
select eu.unique_id, e.name 
from employees e 
left join EmployeeUNI eu on e.id = eu.id;
```

---

## 7. Product Sales Analysis I
**Problem:** [https://leetcode.com/problems/product-sales-analysis-i/](https://leetcode.com/problems/product-sales-analysis-i/)

```sql
select p.product_name, s.year, s.price 
from product p 
join sales s on p.product_id = s.product_id;
```

---

## 8. Customer Who Visited but Did Not Make Any Transactions
**Problem:** [https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/](https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/)

```sql
select v.customer_id, COUNT(*) as count_no_trans 
from Visits v 
left join Transactions t on v.visit_id = t.visit_id 
where t.transaction_id is null 
group by v.customer_id 
order by count_no_trans DESC, v.customer_id;
```

---

## 9. Rising Temperature
**Problem:** [https://leetcode.com/problems/rising-temperature/](https://leetcode.com/problems/rising-temperature/)

```sql
select w1.id 
from weather w1 
cross join weather w2 
where w1.recordDate = w2.recordDate + 1 and w1.temperature > w2.temperature;
```

---

## 10. Average Time of Process Per Machine
**Problem:** [https://leetcode.com/problems/average-time-of-process-per-machine/](https://leetcode.com/problems/average-time-of-process-per-machine/)

```sql
select a1.machine_id, ROUND(AVG(a2.timestamp - a1.timestamp)::NUMERIC, 3) as processing_time 
from Activity a1 
join activity a2 on a1.machine_id = a2.machine_id 
    and a1.process_id = a2.process_id 
    and a2.activity_type = 'end' 
    and a1.activity_type = 'start' 
group by a1.machine_id 
order by a1.machine_id DESC;
```

---

## 11. Employee Bonus
**Problem:** [https://leetcode.com/problems/employee-bonus/](https://leetcode.com/problems/employee-bonus/)

```sql
select e.name, b.bonus 
from employee e 
left join bonus b on e.empId = b.empId 
where b.bonus < 1000 or b.bonus is null 
order by e.name;
```

---

## 12. Students and Examinations
**Problem:** [https://leetcode.com/problems/students-and-examinations/](https://leetcode.com/problems/students-and-examinations/)

```sql
select st.student_id, st.student_name, su.subject_name, COUNT(e.student_id) as attended_exams 
from students st 
cross join subjects su 
left join examinations e on st.student_id = e.student_id and su.subject_name = e.subject_name 
group by st.student_id, st.student_name, su.subject_name 
order by st.student_id, su.subject_name;
```

---

## 13. Managers with at Least 5 Direct Reports
**Problem:** [https://leetcode.com/problems/managers-with-at-least-5-direct-reports/](https://leetcode.com/problems/managers-with-at-least-5-direct-reports/)

```sql
select e1.name 
from employee e1 
join employee e2 on e1.id = e2.managerId 
group by e1.id, e1.name 
having COUNT(e2.managerId) >= 5 
order by e1.id, e1.name;
```

---

## 14. Confirmation Rate
**Problem:** [https://leetcode.com/problems/confirmation-rate/](https://leetcode.com/problems/confirmation-rate/)

```sql
select s.user_id, ROUND(COALESCE(AVG(CASE WHEN c.action = 'confirmed' THEN 1.0 ELSE 0.0 END), 0), 2) as confirmation_rate 
from signups s 
left join confirmations c on s.user_id = c.user_id 
group by s.user_id 
order by s.user_id;
```

---

## 15. Not Boring Movies
**Problem:** [https://leetcode.com/problems/not-boring-movies/](https://leetcode.com/problems/not-boring-movies/)

```sql
select id, movie, description, rating 
from cinema 
where id % 2 != 0 and description != 'boring' 
order by rating desc;
```

---

## 16. Average Selling Price
**Problem:** [https://leetcode.com/problems/average-selling-price/](https://leetcode.com/problems/average-selling-price/)

```sql
select p.product_id, ROUND(COALESCE(SUM(p.price * u.units) / SUM(u.units)::decimal, 0), 2) as average_price 
from prices p 
left join unitssold u on p.product_id = u.product_id 
    and u.purchase_date between p.start_date and p.end_date 
group by p.product_id;
```

---

## 17. Project Employees I
**Problem:** [https://leetcode.com/problems/project-employees-i/](https://leetcode.com/problems/project-employees-i/)

```sql
select p.project_id, ROUND(AVG(e.experience_years), 2) as average_years 
from project p 
left join employee e on p.employee_id = e.employee_id 
group by p.project_id;
```

---

## 18. Percentage of Users Attended a Contest
**Problem:** [https://leetcode.com/problems/percentage-of-users-attended-a-contest/](https://leetcode.com/problems/percentage-of-users-attended-a-contest/)

```sql
select contest_id, ROUND(COUNT(user_id)::decimal / (select COUNT(*) from users) * 100, 2) as percentage 
from register 
group by contest_id 
order by percentage desc, contest_id ASC;
```

---

## 19. Queries Quality and Percentage
**Problem:** [https://leetcode.com/problems/queries-quality-and-percentage/](https://leetcode.com/problems/queries-quality-and-percentage/)

```sql
select query_name, 
       ROUND(AVG(rating / position::decimal), 2) as quality, 
       ROUND(SUM(CASE when rating < 3 then 1.0 else 0.0 end) / COUNT(query_name) * 100, 2) as poor_query_percentage 
from queries 
group by query_name;
```

---

## 20. Monthly Transactions I
**Problem:** [https://leetcode.com/problems/monthly-transactions-i/](https://leetcode.com/problems/monthly-transactions-i/)

```sql
select TO_CHAR(trans_date, 'YYYY-MM') as month, 
       country, 
       COUNT(*) as trans_count, 
       SUM(Case when state = 'approved' then 1 else 0 end) as approved_count,
       SUM(amount) as trans_total_amount, 
       SUM(Case when state = 'approved' then amount else 0 end) as approved_total_amount 
from transactions 
group by TO_CHAR(trans_date, 'YYYY-MM'), country;
```

---

## 21. Immediate Food Delivery II
**Problem:** [https://leetcode.com/problems/immediate-food-delivery-ii/](https://leetcode.com/problems/immediate-food-delivery-ii/)

```sql
select ROUND(SUM(CASE when order_date = customer_pref_delivery_date then 1.0 else 0.0 end) / COUNT(*) * 100.0, 2) as immediate_percentage 
from (
    select *, ROW_NUMBER() over (PARTITION by customer_id order by order_date) as rn 
    from delivery
) t 
where rn = 1;
```

---

## 22. Game Play Analysis IV
**Problem:** [https://leetcode.com/problems/game-play-analysis-iv/](https://leetcode.com/problems/game-play-analysis-iv/)

```sql
select ROUND(COUNT(DISTINCT t.player_id)::decimal / (select COUNT(distinct player_id) from activity), 2) as fraction 
from (
    select *, ROW_NUMBER() over (partition by player_id order by event_date) as rn 
    from activity
) t 
join activity a on t.player_id = a.player_id 
    and t.rn = 1 
    and t.event_date + 1 = a.event_date;
```

---

## 23. Number of Unique Subjects Taught by Each Teacher
**Problem:** [https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/](https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/)

```sql
select teacher_id, COUNT(Distinct subject_id) as cnt 
from teacher 
group by teacher_id;
```

---

## 24. User Activity for the Past 30 Days I
**Problem:** [https://leetcode.com/problems/user-activity-for-the-past-30-days-i/](https://leetcode.com/problems/user-activity-for-the-past-30-days-i/)

```sql
select activity_date as day, COUNT(DISTINCT user_id) as active_users 
from activity 
where activity_date between '2019-06-28'::Date and '2019-07-27'::Date 
group by activity_date;
```

---

## 25. Classes with at Least 5 Students
**Problem:** [https://leetcode.com/problems/classes-with-at-least-5-students](https://leetcode.com/problems/classes-with-at-least-5-students)

```sql
select class 
from courses 
group by class 
having COUNT(distinct student) >= 5;
```

---

## 26. Find Followers Count
**Problem:** [https://leetcode.com/problems/find-followers-count](https://leetcode.com/problems/find-followers-count)

**Solution 1:**
```sql
select user_id, COUNT(distinct follower_id) as followers_count 
from followers 
group by user_id;
```

**Solution 2:**
```sql
select f.user_id, COUNT(distinct f1.follower_id) as followers_count 
from followers f 
join followers f1 on f.user_id = f1.user_id 
group by f.user_id;
```

---

## 27. Biggest Single Number
**Problem:** [https://leetcode.com/problems/biggest-single-number](https://leetcode.com/problems/biggest-single-number)

**Solution 1:**
```sql
select max(num) as num 
from (
    select num 
    from myNumbers 
    group by num 
    having COUNT(num) = 1
);
```

**Solution 2 (More Efficient):**
```sql
select (
    select num 
    from myNumbers 
    group by num 
    having COUNT(*) = 1 
    order by num desc 
    limit 1
) as num;
```

---

## 28. Customers Who Bought All Products
**Problem:** [https://leetcode.com/problems/customers-who-bought-all-products/](https://leetcode.com/problems/customers-who-bought-all-products/)

```sql
select customer_id 
from customer 
group by customer_id 
having COUNT(distinct product_key) = (select COUNT(distinct product_key) from product);
```

---

## 29. The Number of Employees Which Report to Each Employee
**Problem:** [https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee](https://leetcode.com/problems/the-number-of-employees-which-report-to-each-employee)

```sql
select e1.employee_id, 
       e1.name, 
       COUNT(*) as reports_count, 
       ROUND(Avg(e2.age), 0) as average_age 
from employees e1 
join employees e2 on e1.employee_id = e2.reports_to 
group by e1.employee_id, e1.name 
order by e1.employee_id;
```

---

## 30. Primary Department for Each Employee
**Problem:** [https://leetcode.com/problems/primary-department-for-each-employee/](https://leetcode.com/problems/primary-department-for-each-employee/)

```sql
select employee_id, department_id 
from employee 
where primary_flag = 'Y' 
   or (employee_id not in (select employee_id from employee where primary_flag = 'Y') 
       and employee_id in (select employee_id from employee where primary_flag = 'N'));
```

---

## 31. Triangle Judgement
**Problem:** [https://leetcode.com/problems/triangle-judgement/](https://leetcode.com/problems/triangle-judgement/)

```sql
select x, 
       y, 
       z, 
       (case when y + z > x and x + y > z and z + x > y then 'Yes' else 'No' end) as triangle 
from triangle;
```

---

## 32. Consecutive Numbers
**Problem:** [https://leetcode.com/problems/consecutive-numbers](https://leetcode.com/problems/consecutive-numbers)

```sql
select l2.num as consecutiveNums 
from logs l2 
join logs l1 on l1.id = l2.id - 1 
join logs l3 on l3.id = l2.id + 1 
where l1.num = l2.num and l2.num = l3.num 
group by consecutiveNums;
```

---

## 33. Product Price at a Given Date
**Problem:** [https://leetcode.com/problems/product-price-at-a-given-date/](https://leetcode.com/problems/product-price-at-a-given-date/)

```sql
select product_id, 
       coalesce((
           select new_price 
           from products p2 
           where p2.product_id = p1.product_id 
             and change_date <= '2019-08-16'::date 
           order by change_date desc 
           limit 1
       ), 10) price 
from (select distinct product_id from products) p1;
```

---

## 34. Last Person to Fit in the Bus
**Problem:** [https://leetcode.com/problems/last-person-to-fit-in-the-bus](https://leetcode.com/problems/last-person-to-fit-in-the-bus)

```sql
with qu as (
    select person_name, 
           turn, 
           sum(weight) over (order by turn) as wei 
    from queue
)
select person_name 
from qu 
where wei <= 1000 
order by turn desc 
limit 1;
```

## 34. Count Salary Categories
**Problem:** [https://leetcode.com/problems/count-salary-categories](https://leetcode.com/problems/count-salary-categories)

```sql
select 'High Salary' as category, COUNT(*) as accounts_count from accounts where income>50000 
union all
select 'Low Salary' as category, COUNT(*) as accounts_count from accounts where income<20000
union all
select 'Average Salary' as category, COUNT(*) as accounts_count from accounts where income between 20000 and 50000;
```

---