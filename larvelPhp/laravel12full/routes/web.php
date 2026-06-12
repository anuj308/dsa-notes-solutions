<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\HomeController;
use App\Http\Controllers\prefixhomeController;

// Route::get('/', function () {
//     return view('welcome');
// });
// Route::redirect('/a','/b');

// // Route::get('/home', function () {
// //     return view('Home');
// // });
// Route::view('home','Home');

// Route::get("/user/{name}",function($name){
//     return "hi ". $name;
// });

// Route::view('admin/login','admin.login');
// Route::view('admin/home/{id}','admin.home');

// Route::get("/about/{name}",function($name){
//     return view('about',['name'=>$name]);
// });

// Route::get('userId/{id}',[HomeController::class,'getId']);
// Route::get('test/{id}',[HomeController::class,'test']);

// Route::view('userform','user-form')->name('profile');
// use App\Http\Controllers\userController;

// Route::post('addUser',[userController::class,'addUser']);

// Route::view('urls','urls');

// // route group  prefix

// Route::prefix('student')->group(function(){
//     Route::get('/home',[prefixhomeController::class,'home']);
//     Route::get('/about',[prefixhomeController::class,'about']);
// });
// Route::prefix('student/v1/')->group(function(){
//     Route::get('/home',[prefixhomeController::class,'home']);
//     Route::get('/about',[prefixhomeController::class,'about']);
// });

// // route group with controller

// Route::controller(prefixhomeController::class)->group(function(){
//     Route::get('pc/home','home');
//     Route::get('pc/about','about');
//     Route::get('pc/{name}','name');
// });


// middlware

// Route::view('homem','homem')->middleware('check1');

// Route::middlware('check1')->group(function(){
//     Route::view('homem','homem');
//     Route::view('aboutm','homem');
// });

// use App\Http\middlware\AgeCheck;
// use App\Http\middlware\CountryCheck;

// Route::view('homem','homem')->middleware(AgeCheck::class);
// Route::view('homem','homem')->middleware([AgeCheck::class,CountryCheck::class]);



Route::view('home','Home');

use App\Http\Controllers\userController;
// use App\Http\Controllers\studentController;

// Route::get('users',[userController::class,'users']);
// Route::get('data',[userController::class,'getData']);

// // http api request 
// Route::get('students',[studentController::class,'students']);

// database query builder

Route::get('getUserData',[userController::class,'getUserData']);
Route::get('getData',[userController::class,'getStudentData']);