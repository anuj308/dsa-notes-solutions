<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class userloginController extends Controller
{
    public function userdata(Request $req){

        $req->session()->put('user',$req->user);
        return "Data recived";
    }
}
