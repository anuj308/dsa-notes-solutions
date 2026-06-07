
<!-- 
{{
    print_r($users);
}} -->

<table>
    <tr>
        <td>name</td>
        <td>email</td>
    </tr>
    @foreach($users as $user)
        <tr>
            <td>{{$user->name}}</td>
            <td>{{$user->email}}</td>
        </tr>
    @endforeach
</table>