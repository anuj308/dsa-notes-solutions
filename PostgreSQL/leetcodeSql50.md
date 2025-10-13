# leetcode sql 50
## link - https://leetcode.com/studyplan/top-sql-50/


## 1) https://leetcode.com/problems/recyclable-and-low-fat-products/description/
### select product_id from Products where low_fats = 'Y' and recyclable = 'Y';

## 2) https://leetcode.com/problems/find-customer-referee/description
### select name from Customer where  referee_id!='2'or referee_id is null;

## 3) https://leetcode.com/problems/big-countries/description
### select name, population, area from World where area>=3000000 or population>=25000000;

## 4) https://leetcode.com/problems/article-views-i/description/
### SELECT DISTINCT author_id AS id from Views where author_id=viewer_id ORDER BY author_id ASC;  

## 5) https://leetcode.com/problems/invalid-tweets/description
### SELECT TWEET_ID from TWEETS WHERE LENGTH(CONTENT)>15;

## 6) https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/description/
### select eu.unique_id, e.name from employees e left join EmployeeUNI eu on e.id = eu.id;

## 7) https://leetcode.com/problems/product-sales-analysis-i/description
### select p.product_name,s.year,s.price from product p join sales s on p.product_id = s.product_id;  

## 8) https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/description
### select v.customer_id, COUNT(*) as count_no_trans from Visits v left join Transactions t on v.visit_id = t.visit_id where t.transaction_id is null group by v.customer_id order by count_no_trans DESC, v.customer_id;

## 9) https://leetcode.com/problems/rising-temperature/description/
### select w1.id from weather w1 cross join weather w2 where w1.recordDate = w2.recordDate+1 and w1.temperature > w2.temperature;

## 10) https://leetcode.com/problems/average-time-of-process-per-machine/description
### select a1.machine_id, ROUND(AVG(a2.timestamp-a1.timestamp)::NUMERIC,3) as processing_time from Activity a1 join activity a2 on a1.machine_id = a2.machine_id and a1.process_id = a2.process_id and a2.activity_type = 'end' and a1.activity_type = 'start' group by a1.machine_id order by a1.machine_id DESC;

## 11) https://leetcode.com/problems/employee-bonus/description/
### select e.name, b.bonus from employee e left join bonus b on e.empId = b.empId where b.bonus < 1000 or b.bonus is null order by e.name; 

## 12) https://leetcode.com/problems/students-and-examinations/description
### select st.student_id,st.student_name,su.subject_name, COUNT(e.student_id) as attended_exams from students st cross join subjects su left join examinations e on st.student_id = e.student_id and su.subject_name = e.subject_name group by st.student_id,st.student_name,su.subject_name order by st.student_id, su.subject_name;

## 13) https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/
### select e1.name from employee e1 join employee e2 on e1.id = e2.managerId group by e1.id,e1.name having COUNT(e2.managerId) >=  5 order by e1.id , e1.name;

## 14) https://leetcode.com/problems/confirmation-rate/description/
### select s.user_id, ROUND(COALESCE(AVG(CASE WHEN c.action = 'confirmed' THEN 1.0 ELSE 0.0 END),0),2) as confirmation_rate from signups s left join confirmations c on s.user_id = c.user_id group by s.user_id order by s.user_id;

## 15) https://leetcode.com/problems/not-boring-movies/description
### select id, movie, description, rating from cinema where id%2!=0 and description != 'boring' order by rating desc;

## 16) https://leetcode.com/problems/average-selling-price/description/
### select p.product_id, ROUND(COALESCE(SUM(p.price*u.units)/SUM(u.units)::decimal,0),2) as average_price from prices p left join unitssold u on p.product_id = u.product_id and u.purchase_date between p.start_date and p.end_date group by p.product_id;

## 17) https://leetcode.com/problems/project-employees-i/description/
### select p.project_id, ROUND(AVG(e.experience_years),2) as average_years from project p left join employee e on p.employee_id = e.employee_id group by p.project_id;

## 18) https://leetcode.com/problems/percentage-of-users-attended-a-contest/description/
### select contest_id, ROUND(COUNT(user_id)::decimal/(select COUNT(*) from users)* 100,2) as percentage from register group by contest_id order by percentage desc, contest_id ASC;

## 19) https://leetcode.com/problems/queries-quality-and-percentage/description/
### select query_name, ROUND(AVG(rating/position::decimal),2) as quality, ROUND(SUM(CASE when rating < 3 then 1.0 else 0.0 end)/COUNT(query_name)*100,2) as poor_query_percentage from queries group by query_name;

## 20) https://leetcode.com/problems/monthly-transactions-i/description/
### select TO_CHAR(trans_date,'YYYY-MM') as month, country, COUNT(*) as trans_count, SUM(Case when state = 'approved' then 1 else 0 end) as approved_count,SUM(amount) as trans_total_amount, SUM(Case when state = 'approved' then amount else 0 end) as approved_total_amount from transactions group by TO_CHAR(trans_date,'YYYY-MM'), country;

## 21) https://leetcode.com/problems/immediate-food-delivery-ii/description/
### select ROUND(SUM(CASE when order_date = customer_pref_delivery_date then 1.0 else 0.0 end)/COUNT(*) * 100.0,2) as immediate_percentage from (select *, ROW_NUMBER() over (PARTITION by customer_id order by order_date) as rn from delivery) t where rn = 1;

## 22) https://leetcode.com/problems/game-play-analysis-iv/description/
### select ROUND(COUNT(DISTINCT t.player_id)::decimal/(select COUNT(distinct player_id) from activity),2) as fraction from (select *,ROW_NUMBER() over (partition by player_id order by event_date) as rn from activity) t join activity a on t.player_id = a.player_id and t.rn = 1 and t.event_date + 1 = a.event_date;

## 23) https://leetcode.com/problems/number-of-unique-subjects-taught-by-each-teacher/description/
### select teacher_id, COUNT(Distinct subject_id) as cnt from teacher group by teacher_id;

## 24) https://leetcode.com/problems/user-activity-for-the-past-30-days-i/
### select activity_date as day,COUNT(DISTINCT user_id) as active_users from activity where activity_date between '2019-06-28'::Date and '2019-07-27'::Date group by activity_date;

## 25) https://leetcode.com/problems/classes-with-at-least-5-students
### select class from courses group by class having COUNT(distinct student)>=5 ;

## 26) https://leetcode.com/problems/find-followers-count
### select user_id,COUNT(distinct follower_id) as followers_count from followers group by user_id;
### select f.user_id,COUNT(distinct f1.follower_id) as followers_count from followers f join followers f1 on f.user_id = f1.user_id group by f.user_id;

## 27) https://leetcode.com/problems/biggest-single-number
### select max(num) as num from (select num from myNumbers group by num having COUNT(num)=1);
### select (select num from myNumbers group by num having COUNT(*)=1 order by num desc limit 1) as num; // it is more efficient