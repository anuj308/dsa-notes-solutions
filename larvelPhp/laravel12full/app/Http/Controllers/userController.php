<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;
use Illuminate\Support\Facades\Http;

class userController extends Controller
{
    function addUser(Request $req){
        
    $req->validate([
        'name'=>'required | min:3 | max:10 | uppercase',
        'skill'=>'required',
        'gender'=>'required',
        'city'=>'required',
        'age'=>'required',
    ],[
        'name.required'=>"name cannot be empty",
        'name.min'=>"name should be atleast 3 char",
        'name.max'=>"name max can be 10 char",
        'name.uppercase'=>"name must be in uppercase updated custom message",
        'skill.required'=>"skill is imp plz add",
    ]);
        return $req;
    }
    function users(){
       $user = DB::select('select * from users');

       return view('users',['users'=>$user]);
    }
    function getData(){
        $response = Http::get('https://jsonplaceholder.typicode.com/todos');

        // return $response->body();
        return view('data',['data'=>json_Decode($response)]);
    }
    function getUserData(){
        $result = DB::table('users')->get();
        // return $result;
        return view('users',['users'=>$result]);
    }

    function getStudentData(){
        $result = DB::table('student')->get();
        // $result = DB::table('student')->where('phone no','123')->get();
        // $result = DB::table('student')->where('phone no','122673')->first();
        // $result = [$result];
        // $result = DB::table('student')->where('phone no', 'like', '%12%')->get();
        // return $result;

        // $result = DB::table('student')->insert([
        //     'name'=>'mohit',
        //     'email'=>'mohit@gm.com',
        //     'age'=>'34',
        //     'phone no'=>'22'

        // ]);

        // if($result){
        //     return "data inserted";
        // }else return "data insert fail";

        // $result = DB::table('student')->where('name','mohit')->update([
        //     'phone no'=>'3333'
        // ]);

        // if($result){
        //     return "data updated";
        // }else return "data updated fail";

        // if($result){
        //     return "data inserted";
        // }else return "data insert fail";

        // $result = DB::table('student')->where('name','mohit')->delete();
        // if($result){
        //     return "data deleted";
        // }else return "data deleted fail";

        return view('student',['users'=>$result]);
    }
}
