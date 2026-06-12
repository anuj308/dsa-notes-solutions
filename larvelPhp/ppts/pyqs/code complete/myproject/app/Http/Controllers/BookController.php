<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\Models\Book;

class BookController extends Controller
{
    // READ
    public function index()
    {
        $books = Book::all();
        return view('index', compact('books'));
    }

    // CREATE FORM
    public function create()
    {
        return view('create');
    }

    // STORE
    public function store(Request $request)
    {
        Book::create([
            'title' => $request->title,
            'author' => $request->author,
            'price' => $request->price
        ]);

        return redirect('/');
    }

    // EDIT FORM
    public function edit($id)
    {
        $book = Book::find($id);

        return view('edit', compact('book'));
    }

    // UPDATE
    public function update(Request $request, $id)
    {
        $book = Book::find($id);

        $book->update([
            'title' => $request->title,
            'author' => $request->author,
            'price' => $request->price
        ]);

        return redirect('/');
    }

    // DELETE
    public function destroy($id)
    {
        Book::find($id)->delete();

        return redirect('/');
    }
}