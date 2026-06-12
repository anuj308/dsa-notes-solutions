<!DOCTYPE html>
<html>
<head>
    <title>Student Form</title>
</head>
<body>

<h1>Student Registration Form</h1>

<form method="POST" action="/student-display">
    @csrf
    
    Name:
    <input type="text" name="name"><br><br>

    Email:
    <input type="email" name="email"><br><br>

    Course:
    <input type="text" name="course"><br><br>

    <button type="submit">Submit</button>

</form>

</body>
</html>