# Laravel Viva + BYOD Practical Notes

Goal: Quick revision for MVC, Routing, Request/Response, Controllers, Blade, and Advanced Routing.

---

## Unit I: Getting Started with MVC Laravel Framework

## 1) What is MVC Framework?

MVC = Model + View + Controller

- Model:
  - Handles data and business logic.
  - Usually interacts with database using Eloquent ORM.
- View:
  - UI layer shown to user.
  - In Laravel, views are mostly Blade files (`.blade.php`) inside `resources/views`.
- Controller:
  - Middle layer between model and view.
  - Receives request, processes logic, returns response.

### Why MVC?

- Separation of concerns (clean code).
- Easier testing and maintenance.
- Better team collaboration (frontend/backend split).

### Simple MVC Flow

1. User requests URL (`/users`).
2. Route maps URL to controller action.
3. Controller fetches data from model.
4. Controller returns view with data.
5. Browser displays HTML.

---

## 2) Overview of Laravel Framework and Features

Laravel is a modern PHP framework for web application development.

### Core Features

- Elegant routing system.
- MVC architecture.
- Eloquent ORM for DB operations.
- Blade templating engine.
- Middleware support.
- Authentication and authorization.
- Validation and session handling.
- Artisan CLI for automation.
- Migration and seeding support.
- Built-in testing (PHPUnit/Pest).

### Why Laravel is popular in viva answers

- Developer friendly syntax.
- Large ecosystem and community.
- Fast development for CRUD apps and APIs.

---

## 3) Introduction to Composer

Composer is PHP dependency manager.

### What Composer does

- Installs external PHP packages/libraries.
- Manages versions through `composer.json`.
- Creates autoload files in `vendor/`.

### Common Composer Commands

```bash
composer --version
composer install
composer update
composer require package/name
```

- `install`: installs packages from `composer.lock`.
- `update`: updates package versions and lock file.
- `require`: adds new package.

---

## 4) Latest Composer Installation (Linux)

```bash
php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');"
php composer-setup.php
php -r "unlink('composer-setup.php');"
sudo mv composer.phar /usr/local/bin/composer
composer --version
```

If PHP is missing:

```bash
sudo apt update
sudo apt install php-cli unzip curl -y
```

---

## 5) Latest Laravel Installation

### Method A: Using Composer Create Project

```bash
composer create-project laravel/laravel myApp
```

### Method B: Using Laravel Installer

```bash
composer global require laravel/installer
laravel new myApp
```

Run app:

```bash
cd myApp
php artisan serve
```

Default local URL: `http://127.0.0.1:8000`

---

## 6) Directory/Application Structure (Important for viva)

- `app/`:
  - Application core code (models, controllers, providers).
- `bootstrap/`:
  - Framework bootstrapping files.
- `config/`:
  - Configuration files (`app.php`, `database.php`, etc).
- `database/`:
  - Migrations, factories, seeders.
- `public/`:
  - Entry point (`index.php`), public assets.
- `resources/`:
  - Views, CSS, JS source files.
- `routes/`:
  - Route definitions (`web.php`, `api.php`, etc).
- `storage/`:
  - Logs, cache, compiled files, uploads.
- `tests/`:
  - Unit and feature tests.
- `vendor/`:
  - Composer dependencies.

### Most asked file

- `routes/web.php`: define web routes.

---

## 7) Artisan (Laravel CLI)

Artisan is Laravel command-line interface for common tasks.

### Useful Artisan Commands

```bash
php artisan list
php artisan serve
php artisan route:list
php artisan make:controller UserController
php artisan make:model Product -m
php artisan make:migration create_posts_table
php artisan migrate
php artisan cache:clear
php artisan config:clear
```

---

## Unit II: Request, Routing and Responses

## 1) Laravel Request Lifecycle

High-level lifecycle:

1. Request enters through `public/index.php`.
2. Application bootstraps via service container.
3. Middleware pipeline processes request.
4. Router matches route.
5. Controller/closure executed.
6. Response returned to browser.

Viva line: "Laravel handles requests through middleware and routing, then returns a response object."

---

## 2) Basic Routing

In `routes/web.php`:

```php
use Illuminate\Support\Facades\Route;

Route::get('/', function () {
    return 'Home Page';
});

Route::post('/submit', function () {
    return 'Form Submitted';
});
```

Common HTTP verbs: `get`, `post`, `put`, `patch`, `delete`.

---

## 3) Routing Parameters

```php
Route::get('/user/{id}', function ($id) {
    return "User ID: $id";
});

Route::get('/post/{id?}', function ($id = null) {
    return $id ? "Post $id" : 'No Post ID';
});
```

- Required parameter: `{id}`
- Optional parameter: `{id?}` with default value

---

## 4) Understanding Views in Laravel

Views are presentation templates.

Create view file: `resources/views/welcome.blade.php`

```html
<h1>Welcome to Laravel</h1>
```

Route returning view:

```php
Route::get('/welcome', function () {
    return view('welcome');
});
```

---

## 5) Passing Data to Views

```php
Route::get('/profile', function () {
    $name = 'Anuj';
    return view('profile', ['name' => $name]);
});
```

In `profile.blade.php`:

```blade
<h2>Hello, {{ $name }}</h2>
```

---

## 6) Sharing Data with All Views

Usually done in a service provider (`AppServiceProvider`).

```php
use Illuminate\Support\Facades\View;

public function boot(): void
{
    View::share('appName', 'Learn Laravel App');
}
```

In any Blade file:

```blade
<footer>{{ $appName }}</footer>
```

---

## 7) Laravel Responses

### A) Attaching Headers

```php
return response('Hello')->header('X-My-Header', 'LaravelHeader');
```

### B) Attaching Cookies

```php
return response('Cookie Set')->cookie('theme', 'dark', 60);
```

### C) JSON Response

```php
return response()->json([
    'status' => true,
    'message' => 'Success'
]);
```

---

## 8) Laravel Redirections

### Basic Redirect

```php
return redirect('/welcome');
```

### Redirecting to Named Routes

```php
Route::get('/dashboard', function () {
    return 'Dashboard';
})->name('dashboard');

return redirect()->route('dashboard');
```

### Redirecting to Controller Actions

```php
use App\Http\Controllers\UserController;

return redirect()->action([UserController::class, 'index']);
```

---

## Unit III: Controllers, Blade and Advanced Routing

## 1) Basic Controllers - Creating Controllers

Create controller:

```bash
php artisan make:controller UserController
```

Example controller (`app/Http/Controllers/UserController.php`):

```php
namespace App\Http\Controllers;

class UserController extends Controller
{
    public function index()
    {
        return 'User List';
    }
}
```

---

## 2) Controller Routing

In `routes/web.php`:

```php
use App\Http\Controllers\UserController;

Route::get('/users', [UserController::class, 'index']);
```

---

## 3) Controller Middleware

Apply middleware to routes:

```php
Route::get('/admin', [AdminController::class, 'index'])->middleware('auth');
```

Or in controller constructor:

```php
public function __construct()
{
    $this->middleware('auth');
}
```

Purpose: auth check, role check, logging, request filtering.

---

## 4) Restful Resource Controllers

Create resource controller:

```bash
php artisan make:controller ProductController --resource
```

Register resource route:

```php
Route::resource('products', ProductController::class);
```

Generated methods:

- `index()`
- `create()`
- `store()`
- `show($id)`
- `edit($id)`
- `update($id)`
- `destroy($id)`

---

## 5) Blade - Creating Templates

Blade file example (`resources/views/home.blade.php`):

```blade
<h1>{{ $title }}</h1>
@if($isLoggedIn)
    <p>Welcome back!</p>
@else
    <p>Please log in.</p>
@endif
```

---

## 6) Blade PHP Output

- Escaped output: `{{ $var }}`
- Unescaped output: `{!! $html !!}` (use carefully)

Loops:

```blade
@foreach($users as $user)
    <li>{{ $user->name }}</li>
@endforeach
```

---

## 7) Controller Structures (Good viva points)

- Keep controllers thin.
- Move heavy business logic to services/models.
- Validate requests using Form Requests.
- Return proper response types (view/json/redirect).

---

## 8) Template Inheritance (Blade)

`resources/views/layouts/app.blade.php`

```blade
<!DOCTYPE html>
<html>
<head>
    <title>@yield('title')</title>
</head>
<body>
    @yield('content')
</body>
</html>
```

`resources/views/about.blade.php`

```blade
@extends('layouts.app')

@section('title', 'About')

@section('content')
    <h2>About Page</h2>
@endsection
```

---

## 9) Advanced Routing

### A) Named Routes

```php
Route::get('/profile', [UserController::class, 'profile'])->name('profile.show');
```

Use:

```php
return redirect()->route('profile.show');
```

### B) Secure Routes

Using middleware:

```php
Route::get('/settings', function () {
    return 'Settings';
})->middleware('auth');
```

### C) Parameter Constraints

```php
Route::get('/user/{id}', function ($id) {
    return $id;
})->where('id', '[0-9]+');
```

### D) Route Groups

```php
Route::middleware(['auth'])->group(function () {
    Route::get('/dashboard', fn () => 'Dashboard');
    Route::get('/account', fn () => 'Account');
});
```

### E) Route Prefixing

```php
Route::prefix('admin')->group(function () {
    Route::get('/users', fn () => 'Admin Users');
});
```

URL becomes `/admin/users`

### F) Domain Routing

```php
Route::domain('{account}.example.com')->group(function () {
    Route::get('/dashboard', function ($account) {
        return "Dashboard for $account";
    });
});
```

---

## Viva Quick Definitions (1-2 line answers)

- Laravel: Open-source PHP MVC framework for web development.
- Composer: Dependency manager for PHP.
- Artisan: Laravel CLI tool.
- Route: URL mapping to closure/controller action.
- Middleware: Filters HTTP requests before/after app logic.
- Blade: Laravel templating engine.
- Eloquent: ORM for interacting with DB tables as models.
- Migration: Version control system for database schema.
- Resource controller: Controller following RESTful actions.

---

## Practical Checklist (Before Viva)

1. Create project and run server.
2. Create route in `routes/web.php`.
3. Create controller using Artisan.
4. Connect route to controller method.
5. Create Blade view and return from controller.
6. Pass data to view.
7. Create named route and redirect to it.
8. Show JSON response.
9. Run `php artisan route:list` and explain output.

---

## High-Probability Viva Questions

1. Explain MVC with one Laravel example.
2. Difference between `composer install` and `composer update`.
3. What is Artisan and why useful?
4. What is middleware? Give auth middleware example.
5. Difference between `view()` and `redirect()`.
6. Why use named routes?
7. What is route model binding? (bonus)
8. What is template inheritance in Blade?
9. Why use resource controllers?
10. How do you return JSON from Laravel?

---

## 10-Minute Last Revision Strategy

1. Revise MVC definitions.
2. Revise top 10 Artisan commands.
3. Practice one mini flow:
   - Route -> Controller -> View -> Redirect -> JSON.
4. Revise advanced routing examples (group/prefix/constraints).
5. Memorize 5 one-line definitions from this file.

All the best for viva and practical.