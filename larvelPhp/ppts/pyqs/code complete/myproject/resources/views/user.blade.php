<!DOCTYPE html>
<html>
<body>

<h2>User Form</h2>

<form method="POST" action="/user">
    @csrf

    Username:
    <input type="text" name="username" value="{{ old('username') }}">
    @error('username')
        <p style="color:red">{{ $message }}</p>
    @enderror
    <br><br>

    Email:
    <input type="text" name="email" value="{{ old('email') }}">
    @error('email')
        <p style="color:red">{{ $message }}</p>
    @enderror
    <br><br>

    <button type="submit">Submit</button>
</form>

</body>
</html>