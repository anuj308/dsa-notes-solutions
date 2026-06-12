<!DOCTYPE html>
<html>
<head>
    <title>Edit Book</title>
</head>
<body>

<h2>Edit Book</h2>

<form action="/update/{{ $book->id }}" method="POST">
    @csrf

    Title:
    <input type="text" name="title"
           value="{{ $book->title }}">
    <br><br>

    Author:
    <input type="text" name="author"
           value="{{ $book->author }}">
    <br><br>

    Price:
    <input type="number" name="price"
           value="{{ $book->price }}">
    <br><br>

    <button type="submit">Update</button>

</form>

</body>
</html>