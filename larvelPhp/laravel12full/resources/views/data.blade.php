

<!-- {{ print_r($data)}} -->

<h1> user data</h1>

<table>
    <tr>
        <td>userid</td>
        <td>id</td>
        <td>title</td>
        <td>completed</td>
    </tr>
    @foreach($data as $d)
        <tr>
            <td>{{$d->userId}}</td>
            <td>{{$d->id}}</td>
            <td>{{$d->title}}</td>
            <td>{{$d->completed}}</td>
        </tr>
    @endforeach
</table>