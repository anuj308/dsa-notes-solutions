<?php

use App\Http\Controllers\DbController;
use App\Http\Controllers\EmailController;
use App\Http\Middleware\AgeCheck;
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
})->middleware(AgeCheck::class);

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

Route::view('/emailform', 'EmailForm')->name('email.form');
Route::post('/email', [EmailController::class, 'EmailData'])->name('email.send');

// group function
// Route::prefix('/group/testing')->group(function () {
//     Route::get('/fee',function(){
//         return view('g.fee');
//     });
//     Route::get('/details',function(){
//         return view('g.details');
//     });
//     Route::get('/marks',function(){
//         return view('g.marks');
//     });
// });

Route::prefix('/group/testing')
    // ->middleware(['age', 'country'])
    ->controller(DbController::class)
    ->group(function () {
        Route::get('/fee', 'fee');
        Route::get('/details', 'details');
        Route::get('/marks', 'marks');
    });

Route::view('/lang','Monday');

Route::get('/lang/hn', function () {
    App::setlocale('hn');
    return view('Monday');
})->name('lang.hn');

Route::get('/lang/en', function () {
    App::setlocale('en');
    return view('Monday');
})->name('lang.en');

Route::View('/fileform','FileForm');
use App\Http\Controllers\fileController;
Route::post('/upload', [fileController::class, 'uploadData']);