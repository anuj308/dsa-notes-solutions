<?php

namespace App\Models;

use mongoDB\Laravel\Eloquent\Model;

class Student extends Model
{
    protected $fillable = ["name", "rollno"];
}
