<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Rules\CheckAge;
  
class AgeController extends Controller
{
    public function form()
    {
        return view('age');
    }

    public function submit(Request $request)
    {
        $request->validate([
            'age' => ['required', 'numeric', new CheckAge]
        ]);

        return "Valid Age!";
    }
    //
}
