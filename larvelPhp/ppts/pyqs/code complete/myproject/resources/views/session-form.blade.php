<!DOCTYPE html>
<html>
<head>
    <title>Session Form</title>
</head>
<body>

<h2>Enter Your Name</h2>

<form method="POST" action="/set-session">
    @csrf
    <input type="text" name="username" placeholder="Enter name" required>
    <button type="submit">Save Session</button>
</form>

<br>

<a href="/get-session">View Session</a>

</body>
</html>