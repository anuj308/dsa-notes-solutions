<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class CityController extends Controller
{
    private $cities = [
        1 => ['name' => 'Delhi', 'state' => 'Delhi', 'population' => '19 Million'],
        2 => ['name' => 'Mumbai', 'state' => 'Maharashtra', 'population' => '20 Million'],
        3 => ['name' => 'Chandigarh', 'state' => 'Punjab', 'population' => '1 Million'],
        4 => ['name' => 'Jaipur', 'state' => 'Rajasthan', 'population' => '3 Million']
    ];

    public function index()
    {
        return view('cities', ['cities' => $this->cities]);
    }

    public function show($id)
    {
        $city = $this->cities[$id];
        return view('city-detail', compact('city'));
    }
}
