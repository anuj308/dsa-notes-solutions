<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class CourseController extends Controller
{
    private $courses = [
        1 => ['name' => 'BCA', 'duration' => '3 Years', 'fees' => '50000'],
        2 => ['name' => 'MCA', 'duration' => '2 Years', 'fees' => '70000'],
        3 => ['name' => 'B.Tech', 'duration' => '4 Years', 'fees' => '100000'],
        4 => ['name' => 'MBA', 'duration' => '2 Years', 'fees' => '90000'],
        5 => ['name' => 'BBA', 'duration' => '3 Years', 'fees' => '60000']
    ];

    public function index()
    {
        return view('courses', ['courses' => $this->courses]);
    }

    public function show($id)
    {
        $course = $this->courses[$id];
        return view('course-detail', ['course' => $course]);
    }
}