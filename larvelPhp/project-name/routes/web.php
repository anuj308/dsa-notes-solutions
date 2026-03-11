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

Route::get('/user', function () {
    return "welcome";
});

// Route::get('/user', function () {
//     return view('User');
// });

Route::get('/user/{name}', function ($name) {
    // return 'welcome ' . $name;
    return view('User',['n'=>$name]);
})->where(['name'=>'[A-Za-z]+']);

// Route::get('/user/{id}', function ($id) {
//     return view('User',['n'=>$id]);
// })->where(['id'=>'[0-9]+']);
// [0-9]+ - for more than one single number
// [0-9]* - null and above also
// [0-9] - 0 to 9 single number

Route::get('/user/{name}/{id}', function ($name,$id) {
    return view('User',['n'=>$name,'i'=>$id]);
})->where(['id'=>'[0-9]+','name'=>'[A-Z][a-z]+']);   
 
Route::get('/user/{id}', function ($id) {
    if(!ctype_digit($id)){
        return "only digits are accepted";
    }
    else{
        return view('User',['n'=>$name,'i'=>$id]);
    }
});    

Route::get('student1', function () {
// [$name="Anuj",$roll=6,$section='23SF'];
[$name="Anuj",$roll=6];
   return view('student1',['name'=>$name, 'roll'=>$roll]);
});   

Route::get('student2', function () {
    // [$name="Anuj",$roll=6,$section='23SF'];
    [$name="Anuj",$roll=6];
    // return view('student2')->with('name',$name)->with('roll',$roll)->with('section',$section);
    return view('student2')->with('name',$name)->with('roll',$roll);
    });    
    
Route::get('student3', function () {
    // [$name="Anuj",$roll=6,$section='23SF'];
    [$name="Anuj",$roll=6]; // as in boot function i have section
//    return view('student3',compact('name','roll','section'));
   return view('student3',compact('name','roll'));
});    