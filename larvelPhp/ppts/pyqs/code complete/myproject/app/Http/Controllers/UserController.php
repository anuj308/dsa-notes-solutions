<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Rules\CheckUsername; // ✅ IMPORTANT LINE (FIX)

class UserController extends Controller
{
    public function form()
    {
        return view('user');
    }

    public function submit(Request $request)
    {
        $request->validate([
            'username' => ['required', new CheckUsername],
            'email' => 'required|email'
        ]);

        return "Form Submitted Successfully!";
    }
}