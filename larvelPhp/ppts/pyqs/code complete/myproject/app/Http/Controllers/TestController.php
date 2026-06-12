<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Rules\CheckName;

class TestController extends Controller
{
    // Show form
    public function form()
    {
        return view('test');
    }

    // Handle form submission
    public function submit(Request $request)
    {
        // 👉 WRITE YOUR VALIDATION HERE
        $request->validate([
            'name' => ['required', new CheckName]
        ]);

        return "Form Submitted Successfully!";
    }
}