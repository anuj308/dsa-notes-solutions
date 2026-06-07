<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\HomeController;

Route::get('/', function () {
    return view('welcome');
});
Route::redirect('/a','/b');

// Route::get('/home', function () {
//     return view('Home');
// });
// Route::view('home','Home');

Route::get("/user/{name}",function($name){
    return "hi ". $name;
});

Route::view('admin/login','admin.login');
Route::view('admin/home/{id}','admin.home');

Route::get("/about/{name}",function($name){
    return view('about',['name'=>$name]);
});

Route::get('userId/{id}',[HomeController::class,'getId']);
Route::get('test/{id}',[HomeController::class,'test']);

Route::view('userform','user-form')->name('profile');
use App\Http\Controllers\userController;

Route::post('addUser',[userController::class,'addUser']);

Route::view('urls','urls');