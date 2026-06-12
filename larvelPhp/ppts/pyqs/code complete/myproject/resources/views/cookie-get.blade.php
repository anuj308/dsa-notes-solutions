<!DOCTYPE html>
<html>
<head>
    <title>Get Cookie</title>
</head>
<body>

<h2>Stored Cookie Value</h2>

@if($name)
    <p>Welcome, {{ $name }}</p>
@else
    <p>No cookie found!</p>
@endif

<a href="/">Go Back</a>

</body>
</html>