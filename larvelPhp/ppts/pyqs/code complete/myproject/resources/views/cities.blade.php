<!DOCTYPE html>
<html>
<head>
    <title>Cities</title>
</head>
<body>

<h2>City List</h2>

<ul>
@foreach($cities as $id => $city)
    <li>
        <a href="/city/{{ $id }}">
            {{ $city['name'] }}
        </a>
    </li>
@endforeach
</ul>

</body>
</html>