

<form method="post" action="addUser">
    @csrf
    <div>
        <input  type="text" placeholder="enter your name" name="name">
    </div>
    <div>
        <input type="email" placeholder="enter your email" name="email">
    </div>
    <div>
        <input type="text" placeholder="enter your city" name="city">
    </div>
    <div>
        <button>add new user</button>
    </div>
</form>

<style>f
    input{
        border: 1px solid red;
        height: 24px;
        width: 200px;
        border-radius: 2px;
        color: orange;
        padding:10px 10px;
    }
    div{
        margin: 10px;
    }
    button{
        padding:10px;
        border: 1px solid red;
        height: 24px;
        width: 200px;
        border-radius: 2px;
        color: orange;
    }
</style>