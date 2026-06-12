<!DOCTYPE html>
<html>
<head>
    <title>City Detail</title>
</head>
<body>

<h2>City Details</h2>

<p>City Name: {{ $city['name'] }}</p>
<p>State: {{ $city['state'] }}</p>
<p>Population: {{ $city['population'] }}</p>

<a href="/cities">Back</a>

</body>
</html>