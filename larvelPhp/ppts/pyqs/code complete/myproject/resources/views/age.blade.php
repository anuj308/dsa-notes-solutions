<!DOCTYPE html>
<html>
<body>

<h2>Age Validation Form</h2>

<form method="POST" action="/age">
    @csrf

    Enter Age:
    <input type="text" name="age">

    @error('age')
        <p style="color:red">{{ $message }}</p>
    @enderror

    <br><br>
    <button type="submit">Submit</button>
</form>

</body>
</html>