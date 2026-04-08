<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class DbController extends Controller
{
    public function fee(){
        return view('g.fee');
    }
    public function marks(){
        return view('g.marks');
    }
    public function details(){
        return view('g.details');
    }
}
