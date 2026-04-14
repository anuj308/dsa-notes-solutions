<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class register extends Controller
{
    function index () {
        return view('form');
    }
    function register(Request $req){
        // echo $req;
        $req->validate([
            'fullName'=>'required',
            'age'=>'required',
            'phoneNo'=>'required|min:10|max:10'
            // for email required|email
        ]);
        return "thank you";
    }
}
