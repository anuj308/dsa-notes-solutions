<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/monday', function () {
    return view('monday');
});

Route::get('/header', function () {
    return response("Custom Header Example")->header('X-App-Name'.'MyLarvelApp');
});

Route::get('/header', function () {
    return response("Custom Header Example")->header('X-App-Name'.'MyLarvelApp')
    ->header('X-version'.'1.0');
});

Route::domain('hello.com')->group(function(){
    Route::get("/",function(){
        return response("Welcome user");
    });
});
