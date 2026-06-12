<!DOCTYPE html>
<html>
<head>
    <title>Marks Form</title>
</head>
<body>

<h2>Enter Marks</h2>

<form method="POST" action="/marks-total">
    @csrf

    Subject 1:
    <input type="number" name="subject1"><br><br>

    Subject 2:
    <input type="number" name="subject2"><br><br>

    Subject 3:
    <input type="number" name="subject3"><br><br>

    <button type="submit">Calculate Total</button>

</form>

</body>
</html>