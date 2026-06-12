<!DOCTYPE html>
<html>
<head>
    <title>Add Book</title>
</head>
<body>

<h2>Add Book</h2>

<form action="/store" method="POST">
    @csrf

    Title:
    <input type="text" name="title">
    <br><br>

    Author:
    <input type="text" name="author">
    <br><br>

    Price:
    <input type="number" name="price">
    <br><br>

    <button type="submit">Save</button>
</form>

<br>

<a href="/">View Books</a>

</body>
</html>