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

## 6) https://leetcode.com/problems/article-views-i/description/
### SELECT DISTINCT author_id AS id from Views where author_id=viewer_id ORDER BY author_id ASC;  

## 7) https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/description/
### select eu.unique_id, e.name from employees e left join EmployeeUNI eu on e.id = eu.id;

## 8) https://leetcode.com/problems/product-sales-analysis-i/description
### select p.product_name,s.year,s.price from product p join sales s on p.product_id = s.product_id;  

## 9) https://leetcode.com/problems/customer-who-visited-but-did-not-make-any-transactions/description
### select v.customer_id, COUNT(*) as count_no_trans from Visits v left join Transactions t on v.visit_id = t.visit_id where t.transaction_id is null group by v.customer_id order by count_no_trans DESC, v.customer_id;

## 10) https://leetcode.com/problems/rising-temperature/description/
### select w1.id from weather w1 cross join weather w2 where w1.recordDate = w2.recordDate+1 and w1.temperature > w2.temperature;

## 11) https://leetcode.com/problems/product-sales-analysis-i/description
### select p.product_name,s.year,s.price from product p join sales s on p.product_id = s.product_id;  



