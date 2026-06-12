<!DOCTYPE html>
<html>
<head>
    <title>Student Form</title>
</head>
<body>

<h2>Student Registration</h2>

<form method="POST" action="/student-form">
    @csrf

    <!-- Name -->
    Name:
    <input type="text" name="name" value="{{ old('name') }}">
    @error('name') <div style="color:red">{{ $message }}</div> @enderror
    <br><br>

    <!-- Email -->
    Email:
    <input type="text" name="email" value="{{ old('email') }}">
    @error('email') <div style="color:red">{{ $message }}</div> @enderror
    <br><br>

    <!-- Gender (Radio) -->
    Gender:
    <input type="radio" name="gender" value="male"
        {{ old('gender') == 'male' ? 'checked' : '' }}> Male

    <input type="radio" name="gender" value="female"
        {{ old('gender') == 'female' ? 'checked' : '' }}> Female

    @error('gender') <div style="color:red">{{ $message }}</div> @enderror
    <br><br>

    <!-- Course (Dropdown) -->
    Course:
    <select name="course">
        <option value="">Select</option>
        <option value="BTech" {{ old('course') == 'BTech' ? 'selected' : '' }}>BTech</option>
        <option value="MBA" {{ old('course') == 'MBA' ? 'selected' : '' }}>MBA</option>
        <option value="MCA" {{ old('course') == 'MCA' ? 'selected' : '' }}>MCA</option>
    </select>
    @error('course') <div style="color:red">{{ $message }}</div> @enderror
    <br><br>

    <!-- Hobbies (Checkbox) -->
    Hobbies:
    <input type="checkbox" name="hobbies[]" value="reading"
        {{ in_array('reading', old('hobbies', [])) ? 'checked' : '' }}> Reading

    <input type="checkbox" name="hobbies[]" value="sports"
        {{ in_array('sports', old('hobbies', [])) ? 'checked' : '' }}> Sports

    <input type="checkbox" name="hobbies[]" value="music"
        {{ in_array('music', old('hobbies', [])) ? 'checked' : '' }}> Music

    @error('hobbies') <div style="color:red">{{ $message }}</div> @enderror
    <br><br>

    <!-- About (Textarea) -->
    About You:
    <textarea name="about">{{ old('about') }}</textarea>
    @error('about') <div style="color:red">{{ $message }}</div> @enderror
    <br><br>

    <button type="submit">Submit</button>

</form>

</body>
</html>