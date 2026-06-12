<!DOCTYPE html>
<html>
<head>
    <title>Books</title>
</head>
<body>

<h2>Book List</h2>

<a href="/create">Add Book</a>

<br><br>

<table border="1" cellpadding="10">

<tr>
    <th>ID</th>
    <th>Title</th>
    <th>Author</th>
    <th>Price</th>
    <th>Action</th>
</tr>

@foreach($books as $book)

<tr>
    <td>{{ $book->id }}</td>
    <td>{{ $book->title }}</td>
    <td>{{ $book->author }}</td>
    <td>{{ $book->price }}</td>

    <td>
        <a href="/edit/{{ $book->id }}">Edit</a>

        <a href="/delete/{{ $book->id }}">
            Delete
        </a>
    </td>
</tr>

@endforeach

</table>

</body>
</html>