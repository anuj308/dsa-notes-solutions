<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class FileController extends Controller
{
    public function upload(Request $request)
    {
        // Validation
        $request->validate([
            'file' => 'required|file|mimes:jpg,png,pdf|max:2048',
        ]);

        // Upload file
        if ($request->file('file')) {
            $file = $request->file('file');

            // Custom filename
            $filename = time() . '.' . $file->getClientOriginalExtension();

            // Store file in public/uploads
            $path = $file->storeAs('uploads', $filename, 'public');

            return back()->with('success', 'File uploaded successfully!')
                         ->with('file', $path);
        }

        return back()->with('error', 'File upload failed');
    }
}