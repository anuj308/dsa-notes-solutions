<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Employee;
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
            'phoneNo'=>'required',
            'gender'=>'required',
            // 'phoneNo'=>'required|min:10|max:10',

            // for email required|email
        ]);

        $employee = new Employee;
        $employee->fullName = $req->fullName;
        $employee->age = $req->age;
        $employee->phoneNo = $req->phoneNo;
        $employee->gender = $req->gender;

        $employee->save();
        return "thank you";
    }
}
