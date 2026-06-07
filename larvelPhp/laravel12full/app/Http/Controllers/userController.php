<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Http;

class userController extends Controller
{
    function addUser(Request $req){
        
    $req->validate([
        'name'=>'required | min:3 | max:10 | uppercase',
        'skill'=>'required',
        'gender'=>'required',
        'city'=>'required',
        'age'=>'required',
    ],[
        'name.required'=>"name cannot be empty",
        'name.min'=>"name should be atleast 3 char",
        'name.max'=>"name max can be 10 char",
        'name.uppercase'=>"name must be in uppercase updated custom message",
        'skill.required'=>"skill is imp plz add",
    ]);
        return $req;
    }
    function users(){
       $user = DB::select('select * from users');

       return view('users',['users'=>$user]);
    }
    function getData(){
        $response = Http::get('https://jsonplaceholder.typicode.com/todos');

        // return $response->body();
        return view('data',['data'=>json_Decode($response)]);
    }
}
