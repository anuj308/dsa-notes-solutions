<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class studentController extends Controller
{
    //
    function students (){
        $data = new \App\Model\student;
        $data->fun();
        $student = \App\Model\student::all();
        return $student;
    }
}
