// ingle File Programming Question
// Problem Statement



// You are tasked with developing a simple book cataloging program. The program allows the user to enter details of multiple books, such as title, author, and publication year. The program then displays the entered book information.



// Develop a book cataloging program that allows the user to enter the details of multiple books and displays the entered book information. Create a class called Book that stores all the attributes and also uses an array of objects to solve the problem.

// Input format :
// The first line of input consists of an integer n, representing the total number of books.



// For each book, the input consists of the following inputs:

// Title of the book (a string) in the first line.
// Author of the book (a string) in the second line.
// Publication year of the book (an integer) in the third line.
// Output format :
// In the output, each line displays the following information about the book on separate lines:

// Title of the book
// Author of the book
// Publication year of the book


// Refer to the sample output for the exact format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 50

// Sample test cases :
// Input 1 :
// 2
// India
// Gandhi
// 1947
// Tiger
// Haritha
// 2005
// Output 1 :
// Book Information:
// Book 1:
// Title: India
// Author: Gandhi
// Publication Year: 1947
// Book 2:
// Title: Tiger
// Author: Haritha
// Publication Year: 2005
// Input 2 :
// 2
// Harry Potter and the Chamber of Secrets
// J.K. Rowling
// 1998
// Harry Potter and the Prisoner of Azkaban 
// J.K. Rowling
// 1999
// Output 2 :
// Book Information:
// Book 1:
// Title: Harry Potter and the Chamber of Secrets
// Author: J.K. Rowling
// Publication Year: 1998
// Book 2:
// Title: Harry Potter and the Prisoner of Azkaban 
// Author: J.K. Rowling
// Publication Year: 1999

#include <bits/stdc++.h>
using namespace std;

class Book{
  public:
    int id;
    string title;
    string author;
    int publication;
    void get(int id){
        this->id=id;
        cin.ignore();  // to clear the input buffer when using getline
        getline(cin,title);
        this->title=title;
        getline(cin,author);
        this->author=author;
        cin >> publication;
        this->publication=publication;
    }
    void print(){
        cout << "Book " << id << ":" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publication Year: " << publication << endl;
    }
};
int main(){
  
    int n;
    cin >>n;
    int t=0;
    Book b1[n];
    cout << "Book Information: " << endl;
    while(t<n){
        b1[t].get(t+1);
        b1[t].print();
        t++;
    }
    
    return 0;
}