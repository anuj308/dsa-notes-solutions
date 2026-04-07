<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class homeController extends Controller
{
    public function index($value=''){
        return view('home')->with(['value'=>$value]);
    }
    public function show($value=''){
        return view('home')->with(['value'=>$value]);
    }
    public function edit($value=''){
        return view('home')->with(['value'=>$value]);
    }
}
