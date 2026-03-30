<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\View\View;

class UserController extends Controller
{

    function abc(){
        return view('About');
    }

    function user(Request $req){
        echo $req;
        $name = $req->$name;
        return "welcome user " . $name;
    }

    function userDetail($name, $id){
        return view("User",compact('name','id'));
    }   

    function userAge($age){
        if(!ctype_digit($age)){
            return "Give age in numbers only";
        }else if($age>100 || $age<0){
            return "Give Valid Age";
        }
        else if($age>=18){
            return $age;
        }else return "Not eligible for voting";
    }   
}
