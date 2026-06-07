
<!-- {{print_r($errors)}} -->
<form action="addUser" method="post">

<!-- @if($errors->any())
@foreach($errors->all() as $err)
    {{$err}}
@endforeach
@endif -->
        <input  type="text" placeholder="enter your name" value="{{old('name')}}" name="name" id="name" class="{{$errors->first('name')? 'errorform':''}}">
        <label for="name"></label>
        <span style="color:red">@error('name'){{$message}}@enderror</span>
        <!-- <div>
            <input type="email" placeholder="enter your email" name="email">
        </div>
        <div>
            <input type="text" placeholder="enter your city" name="city">
        </div> -->
        <div>
            <h1>User skills</h1>
            <div>
                <input  type="checkbox" value="php" {{ in_array('php', old('skill', [])) ? 'checked' : '' }} name="skill[]" id="php"  class="{{$errors->first('skill')? 'errorform':''}}"/>
                <label for="php"> php </label>
            </div>
            <div>
                <input  type="checkbox" value="java" {{ in_array('java', old('skill', [])) ? 'checked' : '' }} name="skill[]" id="java" class="{{$errors->first('skill')? 'errorform':''}}"/>
                <label for="java"> java </label>
            </div>
            <div>
                <input  type="checkbox" value="node" {{ in_array('node', old('skill', [])) ? 'checked' : '' }} name="skill[]" id="node" class="{{$errors->first('skill')? 'errorform':''}}"/>
                <label for="node"> node </label>
            </div>
            <span style="color:red">@error('skill'){{$message}}@enderror</span>
        </div>
        <div>
            <h1>User Gender</h1>
            <div>
                <input  type="radio" value="male" {{ old('gender') == 'male' ? 'checked' : ''}} name="gender" id="male" class="{{$errors->first('gender')? 'errorform':''}}">
                <label for="male"> male </label>
            </div>
            <div>
                <input  type="radio" value="female" {{ old('gender') == 'female' ? 'checked' : ''}} name="gender" id="female" class="{{$errors->first('gender')? 'errorform':''}}">
                <label for="female"> female </label>
            </div>
            <span style="color:red">@error('gender'){{$message}}@enderror</span>
        </div>
        
        <div>
            <h2>City</h2>
            <select name="city" id="" value="{{old('city')}}" class="{{$errors->first('city')? 'errorform':''}}">
                <option value="rourkela">Rourkela</option>
                <option value="phagwara">Phagwara</option>
                <option value="Chandigarh">Chandigarh</option>
            </select>
            <span style="color:red">@error('city'){{$message}}@enderror</span>
        </div>
        <div>
            <h1>age</h1>
            <input type="range" name="age" min="18" value="{{old('age')}}" max="100" class="{{$errors->first('age')? 'errorform':''}}"/>
            <span style="color:red">@error('age'){{$message}}@enderror</span>
    </div>
    <div>
        <button>add new user</button>
    </div>
</form>

<style>
    input{
        border: 1px solid black;
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
    .errorform{
        border: 1px solid red;
        color: red;
    }
</style>