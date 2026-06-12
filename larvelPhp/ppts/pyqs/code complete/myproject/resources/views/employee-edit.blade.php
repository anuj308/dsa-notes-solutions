<h2>Edit Employee</h2>

<form action="/employees/update/{{ $employee->id }}" method="POST">
    @csrf

    Name:
    <input type="text" name="name" value="{{ $employee->name }}"><br><br>

    Department:
    <input type="text" name="department" value="{{ $employee->department }}"><br><br>

    Salary:
    <input type="number" name="salary" value="{{ $employee->salary }}"><br><br>

    <button type="submit">Update</button>
</form>