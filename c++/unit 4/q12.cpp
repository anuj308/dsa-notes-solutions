// Single File Programming Question
// Problem Statement



// Avinash hired you to create a student processing system for his university, and you have been given a design whereby the student class and their marks are stored in separate classes. Even the marks have been designed in such a way that the sports-related marks scored by the students are stored in a different class from the academic marks that the student achieves.



// If you were to generate a final report of the student's performance, then you would need to create another class that combines all of these classes to generate the total marks scored by each student.



// Use virtual base classes to aid you with the design. The class names to be used and the data to be stored are provided in the below diagram.





// Input format :
// The first line consists of the student ID, which is an integer.

// The second line and third line consist of float values: mark1 and mark2.

// The last line consists of a float value, representing the score.

// Output format :
// The first line of the output displays the student ID.

// The second line displays the mark1.

// The third line displays the mark2.

// The fourth line displays the score.

// The last line displays the total score.

// If the given mark or score is not within the range, it displays the corresponding message.



// All output values except student ID are float values rounded to one decimal place.



// Refer to the sample output for exact specifications.

// Code constraints :
// 0.0 ≤ valid marks, score ≤ 100.0

// Sample test cases :
// Input 1 :
// 48293
// 45.7
// 69.3
// 70.0
// Output 1 :
// ID: 48293
// Mark 1: 45.7
// Mark 2: 69.3
// Score: 70.0
// Total score: 185.0
// Input 2 :
// 353335
// -1
// 35.6
// 22.5
// Output 2 :
// Invalid mark 1
// Input 3 :
// 534324
// 100.0
// 200.9
// 53.8
// Output 3 :
// Invalid mark 2
// Input 4 :
// 1234
// 100.0
// 100.0
// 200.0
// Output 4 :
// Invalid score
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will resu
#include <bits/stdc++.h>
using namespace std;

class student{
    public:
        int id;
};

class testmarks: virtual public student{
    public:
        double m1;
        double m2;
};

class sportmarks: virtual public student{
    public:
        double pe;
};

class result: virtual public testmarks, virtual public sportmarks{
    public:
        result(int id,double m1,double m2,double pe){
            this->id=id;
            this->m1=m1;
            this->m2=m2;
            this->pe=pe;
        }
        void totalScore(){
            if(m1>100.0 || m1<0.0){
                cout << "Invalid mark 1" << endl;
            }else if(m2>100.0 || m2<0.0){
                cout << "Invalid mark 2" << endl;
            }else if(pe>100.0 || pe<0.0){
                cout << "Invalid score" << endl;
            }else{
                cout << "ID: " << id << endl;
                cout << "Mark 1: " << m1 << endl;
                cout << "Mark 2: " << m2 << endl;
                cout << "Score: " << fixed << setprecision(1) << pe << endl;
                cout << "Total score: " << fixed << setprecision(1) << m1+m2+pe << endl;
            }
        }
};

int main(){
    int n;
    double m1,m2,p;
    cin >> n;
    cin >> m1;
    cin >> m2;
    cin >> p; 
    result r(n,m1,m2,p);
    r.totalScore();
    
    return 0;
}