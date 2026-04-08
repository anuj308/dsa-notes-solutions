<?php

namespace App\Http\Controllers;

use App\Mail\WelcomeMail;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Mail;

class EmailController extends Controller
{
    public function EmailData(Request $request)
    {
        $validated = $request->validate([
            'to' => ['required', 'email'],
            'sub' => ['required', 'string', 'max:120'],
            'msg' => ['required', 'string', 'max:2000'],
        ]);

        Mail::to($validated['to'])->send(new WelcomeMail($validated['sub'], $validated['msg']));

        return back()->with('success', 'Email sent successfully.');
    }
}
