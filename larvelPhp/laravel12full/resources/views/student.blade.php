

<!-- {{
    print_r($users);
}} -->

<table>
    <tr>
        <td>name</td>
        <td>email</td>
        <td>age</td>
        <td>phone no</td>
    </tr>
    @foreach($users as $user)
        <tr>
            <td>{{$user->name}}</td>
            <td>{{$user->email}}</td>
            <td>{{$user->age}}</td>
            <td>{{ $user->{'phone no'} }}</td>
        </tr>
    @endforeach
</table>