composer create-project laravel/laravel myApp

composer global require laravel/installer
laravel new myApp

php artisan make:view welcome

php artisan make:controller DemoController

<!-- for single function diretly call  -->
php artisan make:controller TestController --invokable

<!-- for crud operation a template for all the functions -->
php artisan make:controller TestController --resource