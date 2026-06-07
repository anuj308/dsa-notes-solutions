<h1>Current URL</h1>

{{ URL::current() }}
{{ url()->current() }}


<h1>Previous URL</h1>

{{ URL::previous() }}
{{ url()->previous() }}


<h1>Generate URL</h1>

{{ url('/about') }}
{{ URL::to('/about') }}

{{ url('/about', ['anuj']) }}
{{ URL::to('/about', ['anuj']) }}


<h1>Home URL</h1>

{{ url('/') }}
{{ URL::to('/') }}


<h1>Named Route URL</h1>

<!-- Route::get('/profile/{id}', ...)->name('profile'); -->

{{ route('profile', 1) }}
{{ route('profile', ['id' => 1]) }}


<h1>Asset URL</h1>

{{ asset('css/style.css') }}
{{ asset('images/logo.png') }}

<link rel="stylesheet" href="{{ asset('css/style.css') }}">


<h1>Secure Asset URL (HTTPS)</h1>

{{ secure_asset('css/style.css') }}


<h1>Secure URL (HTTPS)</h1>

{{ secure_url('/about') }}


<h1>Full Current URL</h1>

<!-- Includes query string -->

{{ url()->full() }}

<!-- Example:
http://localhost/users?page=2
-->


<h1>Path</h1>

{{ request()->path() }}

<!-- users/profile -->

<h1>Check Current Route</h1>

@if(request()->is('about'))
    About Page
@endif

@if(request()->is('admin/*'))
    Admin Section
@endif


<h1>Check Route Name</h1>

@if(request()->routeIs('profile'))
    Profile Route
@endif


<h1>Query Parameters</h1>

{{ request('name') }}

{{ request()->query('page') }}

{{ request()->query('search') }}


<h1>Get Full Request URL</h1>

{{ request()->url() }}
{{ request()->fullUrl() }}