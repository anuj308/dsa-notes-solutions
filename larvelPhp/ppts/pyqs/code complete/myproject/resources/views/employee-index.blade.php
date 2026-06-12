<h2>Employee List</h2>

<a href="/employees/create">Add Employee</a>

<table border="1" cellpadding="10">
    <tr>
        <th>ID</th>
        <th>Name</th>
        <th>Department</th>
        <th>Salary</th>
        <th>Action</th>
    </tr>

    @foreach($employees as $employee)

    <tr>
        <td>{{ $employee->id }}</td>
        <td>{{ $employee->name }}</td>
        <td>{{ $employee->department }}</td>
        <td>{{ $employee->salary }}</td>

        <td>
            <a href="/employees/edit/{{ $employee->id }}">
                Edit
            </a>

            <a href="/employees/delete/{{ $employee->id }}">
                Delete
            </a>
        </td>
    </tr>

    @endforeach

</table>