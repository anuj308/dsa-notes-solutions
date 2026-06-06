<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class HomeController extends Controller
{
    //
    function getId($id){
        return "hi ". $id;
    }
    function test($id){
        return "test " . $id; 
    }
}
