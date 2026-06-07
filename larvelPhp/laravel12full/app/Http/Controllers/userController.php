<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class userController extends Controller
{
    function addUser(Request $req){
        
    $req->validate([
        'name'=>'required | min:3 | max:10',
        'skill'=>'required',
        'gender'=>'required',
        'city'=>'required',
        'age'=>'required',
    ],[
        'name.required'=>"name cannot be empty",
        'name.min'=>"name should be atleast 3 char",
        'name.max'=>"name max can be 10 char",
        'skill.required'=>"skill is imp plz add",
    ]);
        return $req;
    }
}
