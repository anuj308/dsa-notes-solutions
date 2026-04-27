<?php

use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return view('welcome');
});

// Route::get('home',function(){
//     return 'Home Page';
// });

// Route::get('home1',function(){
//     return view('home');
// });

// Route::get('parameter/{id}',function($id){
//     return "id ". $id;
// });

// Route::get('parameter/{name}',function($name){
//     return "name ". $name;
// });

// Route::get('parameter/{name?}',function($name=''){
//     return "name ". $name;
// });
// // same so if parameter is not passed still no error as we passed the value null
// Route::get('parameter/{name?}',function($name=null){
//     return "name ". $name;
// });

// Route::get('parameter/{name?}',function($name=null){
//     return "name ". $name;
// })->whereNumber('name');

// Route::get('parameter/{name?}',function($name=null){
//     return "name ". $name;
// })->whereAlpha('name');

// Route::get('parameter/{name?}',function($name=null){
//     return "name ". $name;
// })->whereAlphaNumeric('name');

// regex
// Route::get('parameter/{name?}',function($name=null){
//     return "name ". $name;
// })->where('name','[a-zA-Z0-9]+');

// Route::get('parameter/{name?}',function($name=null){
//     return "name ". $name;
// })->whereIn('name',['php','laravel']);

// named routes  ------------------------ so that if we need to change the
// url but not to change routes name in multiple files we can use this.

// Route::get('/home/introduction',function(){
//     // return 'Laravel Named Routes';
//     return view('home');
// })->name('home');

// Route::get('/home/about-page',function(){
//     return view('about');
// })->name('about');

// group routes --------------
// Route::prefix('home')->group(function(){
//     Route::get('introduction',function(){
//         return view('home');
//     })->name('home');
//     Route::get('about',function(){
//         return view('about');
//     })->name('about');
// });

// Route::get('/{value?}',function($value=null){
//     // return view('test',['value'=>$value]);
//     return view('test')->with(['value'=>$value]);
// });


use App\Http\Controllers\DemoController;
use App\Http\Controllers\homeController;
use App\Http\Controllers\Test2Controller;

// Route::get('/demo',[DemoController::class,'index']);
// Route::get('/home/{value?}',[homeController::class,'index']);

// Route::get('/show/{value?}',[homeController::class,'show']);
// Route::get('/index/{value?}',[homeController::class,'index']);
// Route::get('/edit/{value?}',[homeController::class,'edit']);

Route::controller(homeController::class)->group(function(){
    Route::get('/show/{value?}','show')->name('s');
    Route::get('/index/{value?}','index')->name('i');
    Route::get('/edit/{value?}','edit')->name('e');
    });
    
    // for single action controller
Route::get('/invokeFunc',Test2Controller::class);

use App\Models\Employee;
Route::get('empModel',function(){
    $emp = Employee::all();
    echo '<pre>';
    print_r($emp->toArray());
});
use App\Http\Controllers\register;

Route::get('/form',[register::class,'index']);
Route::post('/register',[register::class,'register']);
Route::post('/userUpdate/{id}',[register::class,'update']);
Route::get('/userEdit/{id}',[register::class,'edit']);
Route::get('/userDelete/{id}',[register::class,'delete']);
Route::get('/userDataDetails',[register::class,'allData']);
