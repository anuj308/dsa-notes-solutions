<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class userController extends Controller
{
    function addUser(Request $req){
        echo $req;
        echo $req->name;
        echo $req->email;
        echo $req->city;
        return "working";
    }
}
