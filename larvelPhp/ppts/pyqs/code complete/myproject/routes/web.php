<?php

use Illuminate\Support\Facades\Route;

// Route::get('/', function () {
//     return view('welcome');
// });

// use App\Http\Controllers\CourseController;

// Route::get('/courses', [CourseController::class, 'index']);

// Route::get('/course/{id}', [CourseController::class, 'show'])
//      ->where('id', '[0-9]+');


// //      use App\Http\Controllers\StudentController;

// // Route::get('/student-form', [StudentController::class, 'form']);

// // Route::post('/student-display', [StudentController::class, 'display']);


// use App\Http\Controllers\MarksController;

// Route::get('/marks', [MarksController::class, 'form']);
// Route::post('/marks-total', [MarksController::class, 'total']);



// use App\Http\Controllers\EmployeeController;

// Route::get('/employee-form', [EmployeeController::class, 'form']);

// Route::post('/employee-save', [EmployeeController::class, 'save']);

// Route::get('/employee/{id}', [EmployeeController::class, 'show'])
//         ->name('employee.show');


// use App\Http\Controllers\ContactController;

// Route::get('/contact', [ContactController::class, 'form']);
// Route::post('/contact-submit', [ContactController::class, 'submit']);
// Route::get('/thank-you', [ContactController::class, 'thankyou']);

// use App\Http\Controllers\CityController;

// Route::get('/cities', [CityController::class, 'index']);

// Route::get('/city/{id}', [CityController::class, 'show'])
//         ->where('id','[0-9]+');


// //------Custom Validator-----------
// use App\Http\Controllers\TestController;

// Route::get('/test', [TestController::class, 'form']);
// Route::post('/test', [TestController::class, 'submit']);

// //-----custom validate - age example 
// use App\Http\Controllers\AgeController;

// Route::get('/age', [AgeController::class, 'form']);
// Route::post('/age', [AgeController::class, 'submit']);


// //------repopulating form --------
// use App\Http\Controllers\UserController;

// Route::get('/user', [UserController::class, 'form']);
// Route::post('/user', [UserController::class, 'submit']);

// //------repopulating student form --------
// use App\Http\Controllers\StudentController;

// Route::get('/student-form', [StudentController::class, 'form']);
// Route::post('/student-form', [StudentController::class, 'submit']);


// // // //----cookies---

// // Route::get('/', function () {
// //     return view('cookie-form');
// // });

// // Route::post('/set-cookie', function (\Illuminate\Http\Request $request) {
// //     return response()
// //         ->view('cookie-result', ['name' => $request->name])
// //         ->cookie('username', $request->name, 60); // 60 minutes
// // });

// // Route::get('/get-cookie', function (\Illuminate\Http\Request $request) {
// //     $name = $request->cookie('username');
// //     return view('cookie-get', ['name' => $name]);
// // });

// // Route::get('/delete-cookie', function () {
// //     return response("Cookie Deleted")
// //         ->cookie('username', '', -1); // expire cookie
// // });

// //-------session-------------
// use Illuminate\Http\Request; // ✅ IMPORTANT (correct import)

// // Show form
// Route::get('/', function () {
//     return view('session-form');
// });


// // Store session
// Route::post('/set-session', function (Request $request) {

//     // ✅ Correct way to get input
//     session(['username' => $request->input('username')]);

//     return redirect('/get-session');
// });


// // Get session
// Route::get('/get-session', function () {
//     $name = session('username');
//     return view('session-get', compact('name'));
// });


// // Delete session
// Route::get('/delete-session', function () {
//     session()->forget('username');
//     return redirect('/');
// });


// //------session 2--------------

// // Show form
// Route::get('/', function () {
//     return view('flash-form');
// });

// // Handle form submission
// Route::post('/submit', function (Request $request) {

//     // Store flash message (temporary session)
//     return redirect('/')
//         ->with('success', 'Form submitted successfully!');
// });



// Route::get('/contact', [ContactController::class, 'showForm']);
// Route::post('/contact', [ContactController::class, 'submitForm']);
// Route::get('/thank-you', function () {
// return view('thank-you');
// });


// use App\Http\Controllers\FileController;
// // Show form
// Route::get('/', function () {
//     return view('upload');
// });

// Handle upload
Route::post('/upload', [FileController::class, 'upload'])->name('file.upload');

//It will generate lang forder
//in that lang folder - create 2 folders - en and hi 
//create welcome.php in both the folders, 
//copy code of pagination and paste it inside welcome.php



//----Cookie and session------ 

// use Illuminate\Http\Request;
// Route::get('/', function () {
//     return view('form');
// });

// // Store session & cookie
// Route::post('/store', function (Request $request) {

//     // Store in session
//     session(['username' => $request->name]);

//     // Create cookie (valid for 60 minutes)
//     $cookie = Cookie::make('user_cookie', $request->name, 60);

//     return redirect('/show')->withCookie($cookie);
// });

// // Retrieve session & cookie
// Route::get('/show', function (Request $request) {

//     $sessionData = session('username');
//     $cookieData = $request->cookie('user_cookie');

//     return view('show', compact('sessionData', 'cookieData'));
// });

// use Illuminate\Support\Facades\Mail;
// use App\Mail\TestMail;

// Route::get('/send-mail', function () {
//     Mail::to('ishitamalhotra2075@gmail.com')->send(new TestMail());

//     return "Mail Sent Successfully!";
// });

//------DB---------
//use App\Http\Controllers\StudentController;

//Route::get('/', [StudentController::class, 'index']);

// Route::get('/create', [StudentController::class, 'create']);

// Route::post('/store', [StudentController::class, 'store']);

// Route::get('/edit/{id}', [StudentController::class, 'edit']);

// Route::post('/update/{id}', [StudentController::class, 'update']);

// Route::get('/delete/{id}', [StudentController::class, 'delete']);

use App\Http\Controllers\EmployeeController;

Route::get('/employees', [EmployeeController::class, 'index']);
Route::get('/employees/create', [EmployeeController::class, 'create']);
Route::post('/employees/store', [EmployeeController::class, 'store']);
Route::get('/employees/edit/{id}', [EmployeeController::class, 'edit']);
Route::post('/employees/update/{id}', [EmployeeController::class, 'update']);
Route::get('/employees/delete/{id}', [EmployeeController::class, 'delete']);


//-----CRUD USING ORM(OBJECT RELATIONAL MAPPER)
use App\Http\Controllers\BookController;

Route::get('/', [BookController::class, 'index']);

Route::get('/create', [BookController::class, 'create']);

Route::post('/store', [BookController::class, 'store']);

Route::get('/edit/{id}', [BookController::class, 'edit']);

Route::post('/update/{id}', [BookController::class, 'update']);

Route::get('/delete/{id}', [BookController::class, 'destroy']);


//------middleware------
Route::get('/admin', function () {
    return "Welcome Admin";
})->middleware('checkrole');