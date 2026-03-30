<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class StudentController extends Controller
{
    function studentDetail($id){
    if(!ctype_digit($id)){
        return "Id will be in digit only";
    }else if($id<1 || $id>5) {
        return "Out of Range, id range is 1 to 5";
    }
    $students = [
        ['id' => 1, 'name' => 'John Doe', 'age' => 20],
        ['id' => 2, 'name' => 'Jane Smith', 'age' => 21],
        ['id' => 3, 'name' => 'Mike Johnson', 'age' => 19],
        ['id' => 4, 'name' => 'Sarah Williams', 'age' => 22],
        ['id' => 5, 'name' => 'Alex Brown', 'age' => 20]
    ];
    $result = null;



    
    foreach($students as $stud){
        if($stud['id']==$id){
            $result=$stud;
            break;
        }
    }
    return view('StudentDetails',compact('result'));
    }
}
