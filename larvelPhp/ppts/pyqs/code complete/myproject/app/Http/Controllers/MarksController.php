<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class MarksController extends Controller
{
    public function form()
    {
        return view('marks-form');
    }

    public function total(Request $request)
    {
        $s1 = $request->subject1;
        $s2 = $request->subject2;
        $s3 = $request->subject3;

        $total = $s1 + $s2 + $s3;

        return view('marks-result', compact('s1','s2','s3','total'));
    }
}