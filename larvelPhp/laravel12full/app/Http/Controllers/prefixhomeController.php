<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class prefixhomeController extends Controller
{
    //
    function about (){
        return "About";
    }
    function home(){
        return "Home";
    }
    function name($name){
        return $name;
    }
}
