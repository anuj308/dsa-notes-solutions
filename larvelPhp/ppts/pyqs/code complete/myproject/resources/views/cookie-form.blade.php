<!DOCTYPE html>
<html>
<head>
    <title>Set Cookie</title>
</head>
<body>

<h2>Enter Your Name</h2>
<form method="POST" action="/set-cookie">
    @csrf
    <input type="text" name="name" placeholder="Enter name" required>
    <button type="submit">Set Cookie</button>
</form>

<br>

<a href="/get-cookie">Get Cookie</a><br>
<a href="/delete-cookie">Delete Cookie</a>

</body>
</html>