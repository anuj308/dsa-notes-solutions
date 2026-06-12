<!DOCTYPE html>
<html>
<head>
    <title>Session & Cookie Example</title>
</head>
<body>

<h2>Enter Name</h2>

<form action="/store" method="POST">
    @csrf
    <input type="text" name="name" placeholder="Enter your name">
    <button type="submit">Submit</button>
</form>

</body>
</html>