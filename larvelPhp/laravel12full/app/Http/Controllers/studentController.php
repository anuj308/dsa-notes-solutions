<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class studentController extends Controller
{
    //
    function students (){
        $data = new \App\Models\student;
        $data->fun();
        $student = \App\Models\student::all();
        return $student;
    }
}
