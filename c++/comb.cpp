#include <iostream>
using namespace std;

class Student{
    public:
    int age;
    string name;
    Student(int a,string n){
        age = a;
        name = n;
    }
    Student(const Student &obj){
        age= obj.age;
        name= obj.name;
        cout << "copy construtor called" << endl;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    void show(Student s){
        s.display();
    }
};

class book{
    public:
    string bookname;
    string author;
    float price;
    book(){
        bookname="";
        author="";
        price=0.0;
    }
    book(string bn,string a="author"){
        bookname=bn;
        author=a;
    }
    book(string bn,string a,float p): bookname(bn),author(a),price(p){
    }
    // book(string bn,string a,float p){
    //     bookname=bn;.
    //     author=a;
    //     price=p;
    // }
    void display(){
        cout << bookname << endl;
        cout << author << endl;
        cout << price << endl;
    }
};

class Animal{
    public:
    void eat(){
        cout << "I eat" << endl;
    }
};

class Dog : public Animal{
    public:
    void bark(){
        cout << "I bark" << endl;
    }
};

// class Person{
//     private:
//     string name;
//     int age;

//     void setPerson(string n,int a){
//         name=n;
//         age=a;
//     }
//     void showPerson(){
//         cout << "Name: " << name << endl;
//         cout << "Age: " << age << endl;
//     }
// };

// class Student: public Person{
//     private:
//     int rollNo;
//     void setStudent(int r){
//         rollNo=r;
//     }
//     void showRollNo(){
//         cout << "Rollno: " << rollNo << endl;
//     }
// };

// class Monitor: public Student{
//     private:
//     string section;
//     void setMonitor(string sec){
//         section = sec;
//     }
//     void showMonitor(){
//         cout << "Section: " << section << endl;
//     }
// };
// -----------------------------------------------------------------

class A{
    public:
    int x;
    A(int a){
        x=a;
    }
};

class B: public A{
    public:
    int y;
    B(int a,int b): A(a){
        y=b;
    }
};

class C : public B{
    public:
    int z;
    C(int a,int b,int c): B(a,b){
        z=c;
    }
    void display(){
        cout << "A: " << x << endl;
        cout << "B: " << y << endl;
        cout << "C: " << z << endl;
    }
};



int main(){
    // Student s1(10,"anuj");
    // Student s2(s1);
    // s1.display();
    // s2.display();
    // s1.show(s2);

    // book b1;
    // book b2("C++ Basics","aks");
    // book b3("OOP in C++","anuj",190.23);

    // cout << "Book 1:"<< endl;
    // b1.display();
    // cout << "Book 2:"<< endl;
    // b2.display();
    // cout << "Book 3:"<< endl;
    // b3.display();

    // Dog d1;
    // d1.bark();
    // d1.eat();

    C obj(1,2,3);
    obj.display();
    return 0;
}