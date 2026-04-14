composer create-project laravel/laravel myApp

composer global require laravel/installer
laravel new myApp

php artisan make:view welcome

php artisan make:controller DemoController

<!-- for single function diretly call  -->
php artisan make:controller TestController --invokable

<!-- for crud operation a template for all the functions -->
php artisan make:controller TestController --resource

<!-- below is the syntax create_name_table -->
php artisan make:migration create_employee_table

php artisan migrate

<!-- only remove the last migrated table -->
php artisan migrate:rollback

<!-- this reset or remove all table -->
php artisan migrate:reset 

<!-- it rollback all table and then migrate them -->
php artisan migrate:refresh

php artisan make:model Employee

route for name tag routingn
url for normal routing in <a> tag