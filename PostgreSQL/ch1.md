# Postgre SQL

## Chapter 1

#### what is a Database?
- an organised collection of data.
- a method  to manipulate and access the data.

#### database vs DBMS
- database can be excel etc to store values.
- DBMS is database + how to access data like pSQL,mySQl languages.

![alt text](image.png)
#### RDBMS - A type of database system that stores data in structured tables (using rows and columns) and uses SQL for managing and querying Data.
 
#### The Hierarchy: Database → Schema → Table
- Think of it like this:
- Database = A building
- Schema = An apartment in that building
- Table = Furniture in that apartment

#### DATABASE
##### can you uppercase or lowercase

- list down existing database - Select datname FROM pg_database; , cmd - /l
- create database - create database test;
- change database - \c <database_name>;
- delete database - drop database <database_name>;

#### CURD
##### table - it is a collection of related  data held  in a table  format  within a database.

- creating a new table - create  table person(id INT, name varchar(100), city varchar(50));
- adding data into a table -
    -  insert into student(id,name,city) values(101,'aks','Rourkela');
    -  insert into student(id,name,city) values(101,'aks','Rourkela'),(102,'mohit','rourkela'); // for inserting multiple  data
    -  insert into student values(101,'aks','Rourkela'); // for single and inserting all fields(columns).
     
- Reading  data from a table 
    - select * from <table_name>
    - select <column_name> from students;
    - select <column_name>,<column_name> from <table_name>; // for multiple column

- Modify/update data from a table
    - udpate <table_name> set city='Delhi' where id=2;

- Deleting data
    - delete from <table_name> where id=1;