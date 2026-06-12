<!DOCTYPE html>
<html>
<head>
    <title>Course Detail</title>
</head>
<body>

<h1>Course Detail</h1>

<p><strong>Course Name:</strong> {{ $course['name'] }}</p>
<p><strong>Duration:</strong> {{ $course['duration'] }}</p>
<p><strong>Fees:</strong> {{ $course['fees'] }}</p>

<a href="/courses">Back to Course List</a>

</body>
</html>