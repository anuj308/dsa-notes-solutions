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
        echo "thank you for the information";

        return redirect('userDataDetails');
    }
    function allData(){
        $employee = Employee::all();
        $data = compact('employee');
        return view('userData')->with($data);
    }
    function edit($id){
        $employee = Employee::find($id);
        
        if(is_null($employee)){
            
            return redirect('/userDataDetails');
        }
        $data=compact('employee');
        return view('form')->with($data);
    }
    function update(Request $req,$id){
        $employee = Employee::find($id);
        $employee->fullName = $req->fullName;
        $employee->age = $req->age;
        $employee->phoneNo = $req->phoneNo;
        $employee->gender = $req->gender;

        $employee->save();

        return redirect('userDataDetails');
    }
}
