<h2>Add Employee</h2>

<form action="/employees/store" method="POST">
    @csrf

    Name:
    <input type="text" name="name"><br><br>

    Department:
    <input type="text" name="department"><br><br>

    Salary:
    <input type="number" name="salary"><br><br>

    <button type="submit">Save</button>
</form>