<!DOCTYPE html>
<html>
<head>
    <title>Course List</title>
</head>
<body>

<h1>Course List</h1>

<ul>
@foreach($courses as $id => $course)
    <li>
        <a href="/course/{{ $id }}">
            {{ $course['name'] }}
        </a>
    </li>
@endforeach
</ul>

</body>
</html>