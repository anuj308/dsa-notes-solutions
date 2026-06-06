
@include('commom.header')
<h1> home</h1>
@include('commom.footter',['data'=>'this is data'])
@includeif('commom.foer',['data'=>'this is data'])
<!-- include if there then show other wise not so no error vs include -->

<x-message-banner msg="user login success" class="success"/>
<x-message-banner msg="user login failed" class="error"/>


<style>
    .success{
        background:lightgreen;
        color:red;
        padding:10px 10px;
    }
    .error{
        background:red;
        color:black;
        padding:10px 10px;
    }

</style>