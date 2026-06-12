<!DOCTYPE html>
<html>
<head>
    <title>Employee Detail</title>
</head>
<body>

<h2>Employee Details</h2>

<p>ID: {{ $id }}</p>
<p>Name: {{ $employee['name'] }}</p>
<p>Department: {{ $employee['department'] }}</p>
<p>Salary: {{ $employee['salary'] }}</p>

<a href="/employee-form">Back</a>

</body>
</html>