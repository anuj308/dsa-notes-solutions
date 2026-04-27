<div>
    <a href="{{url('form')}}"><button >Add</button></a>
    <table class="table table-striped">
        <thead>
            <tr>
                <th>Full Name</th>
                <th>Age</th>
                <th>Phone No</th>
                <th>Gender</th>
            </tr>
        </thead>
        <tbody>
            @forelse($employee as $emp)
                <tr>
                    <td>{{ $emp['fullName'] }}</td>
                    <td>{{ $emp['age'] }}</td>
                    <td>{{ $emp['phoneNo'] }}</td>
                    <td>{{ $emp['gender'] }}</td>

                    <td><a href="{{url('userEdit',['id' => $emp['id']])}}"><button>Edit</button></a></td>
                    <td><a href="{{url('userDelete',['id' => $emp['id']])}}"><button>Delete</button></a></td>
                </tr>
            @empty
                <tr>
                    <td colspan="4" class="text-center">No employee data available</td>
                </tr>
            @endforelse
        </tbody>
    </table>
</div>
