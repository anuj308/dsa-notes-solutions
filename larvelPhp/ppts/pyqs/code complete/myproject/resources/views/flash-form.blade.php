<!DOCTYPE html>
<html>
<head>
    <title>Flash Message</title>
</head>
<body>

<h2>Submit Form</h2>

<!-- ✅ Display Flash Message -->
@if(session('success'))
    <p style="color: green;">
        {{ session('success') }}
    </p>
@endif

<form method="POST" action="/submit">
    @csrf
    <input type="text" name="data" placeholder="Enter something" required>
    <button type="submit">Submit</button>
</form>

</body>
</html>