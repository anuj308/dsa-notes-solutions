<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\DB;

class EmployeeController extends Controller
{
    // Display Data
    public function index()
    {
        $employees = DB::table('employees')->get();

        return view('employee-index', compact('employees'));
    }

    // Add Form
    public function create()
    {
        return view('employee-create');
    }

    // Store Data
    public function store(Request $request)
    {
        DB::table('employees')->insert([
            'name' => $request->name,
            'department' => $request->department,
            'salary' => $request->salary,
        ]);

        return redirect('/employees');
    }

    // Edit Form
    public function edit($id)
    {
        $employee = DB::table('employees')
                        ->where('id', $id)
                        ->first();

        return view('employee-edit', compact('employee'));
    }

    // Update Data
    public function update(Request $request, $id)
    {
        DB::table('employees')
            ->where('id', $id)
            ->update([
                'name' => $request->name,
                'department' => $request->department,
                'salary' => $request->salary,
            ]);

        return redirect('/employees');
    }

    // Delete Data
    public function delete($id)
    {
        DB::table('employees')
            ->where('id', $id)
            ->delete();

        return redirect('/employees');
    }
}