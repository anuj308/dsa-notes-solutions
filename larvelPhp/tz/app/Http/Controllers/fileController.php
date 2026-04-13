<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class fileController extends Controller
{
    function uploadData(Request $req){
        $filename = $req->file;
        // echo $filename;
        $path = $req->file('file')->store('uploads','public');
        // echo $path;
        $fileNameArray=explode('/',$path);
        $fileName = $fileNameArray[1];

        // return "File uploaded successfully ". $fileName;

        return view('FileDisplay',['path'=>$fileName]);
    }
}
