![alt text](image.png)
![alt text](image-1.png)
![alt text](image-2.png)
composer.json - all detail and dependency - imp file
composer.lock - it store all dependency hierarchy like one dependency can has many more dependency
vendor folder - all dependency are store here
app folder - core code it has modal, controller, middleware, service provider
routes folder - web - for web routes, console for cli 
resources folder - it has views folder 
config folder - has all config like database connection info
database folder - has migration, seeders, factories
public folder - first file to execute is index.php is inside it, icon , robot.txt
storage folder - for store pdf etc, logs, cache
test folder - it use for testing unit, modal   testing
vite config - create a local developemnt server

Routing in laravel
routing - it a path to opening a web page
![alt text](image-3.png)

controller 
![alt text](image-4.png)
![alt text](image-5.png)
view
![alt text](image-6.png)
blade template
![alt text](image-7.png)
![alt text](image-8.png)

![alt text](image-9.png)
![alt text](image-10.png)
![alt text](image-11.png)

![alt text](image-12.png)
![alt text](image-13.png)
![alt text](image-14.png)
![alt text](image-15.png)

php artisan puplish lang
can chnage message from validation for whole
lang -> validation.php 

custom rule
![alt text](image-16.png)

php artisan make:rule Uppercase 


![alt text](image-17.png)
![alt text](image-18.png)

middleware
![alt text](image-19.png)
![alt text](image-20.png)
![alt text](image-21.png)
![alt text](image-22.png)

connect to mysql
![alt text](image-23.png)
![alt text](image-24.png)

eloquent model in laravel
![alt text](image-25.png)
![alt text](image-26.png)

if model and table do not match the in model do this
protected $table = "give the table name";

![alt text](image-27.png)

php artisan model:show student(modelname)
give all the info 