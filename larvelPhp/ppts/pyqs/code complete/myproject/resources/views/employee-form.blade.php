<!DOCTYPE html>
<html>
<head>
    <title>Employee Form</title>
</head>
<body>

<h2>Employee Form</h2>

<form method="POST" action="/employee-save">
    @csrf

    Name:
    <input type="text" name="name"><br><br>

    Department:
    <input type="text" name="department"><br><br>

    Salary:
    <input type="number" name="salary"><br><br>

    <button type="submit">Submit</button>
</form>

</body>
</html>