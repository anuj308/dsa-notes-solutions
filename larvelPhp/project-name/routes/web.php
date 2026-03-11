<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return "hello";
});

Route::get('/', function () {
    return view('welcome');
});

Route::get('/about', function () {
    return response()->JSON(["message"=>"how are you?"]);
});

Route::get('/student', function () {
    return view("Student");
});
