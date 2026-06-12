<!DOCTYPE html>
<html>
<head>
    <title>Get Session</title>
</head>
<body>

<h2>Session Data</h2>

@if($name)
    <p>Welcome, {{ $name }}</p>
@else
    <p>No session found!</p>
@endif

<br>

<a href="/delete-session">Delete Session</a><br>
<a href="/">Back</a>

</body>
</html>