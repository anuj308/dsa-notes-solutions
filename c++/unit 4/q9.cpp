// Single File Programming Question
// Problem Statement



// Imagine you are developing a school management system, and you have two types of individuals: "Person" and "Student". Both types of individuals have some common attributes, such as their first name, last name, and ID number. The "Person" class serves as the base class for all individuals, and it contains a method to print their information.



// You need to create a specialized class called "Student" that inherits from the "Person" class. The "Student" class should have additional functionality to store test scores and calculate the student's grade based on those scores. Each student can have up to 10 test scores, and the number of actual scores may vary.





// Input format :
// The first line of input consists of a string representing the first name.

// The second line of input consists of a string representing the last name.

// The third line of input consists of an integer representing the ID.

// The fourth line of input consists of the number of test scores.

// The fifth line of input consists of an integer array of test scores, separated by a single space.

// Output format :
// The output displays the Name, ID, and Grade of the student in separate lines.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1<=Length of names <=100

// 1<=Id number <=1000

// 1<=Number of tests <=10

// 1<=Test scores <=100

// Sample test cases :
// Input 1 :
// Shruthi
// Ramesh
// 50
// 5
// 70 80 90 87 99
// Output 1 :
// Name: Shruthi Ramesh
// ID: 50
// Grade: E
// Input 2 :
// Monica
// Geller
// 51
// 7
// 36 35 40 45 49 47 41
// Output 2 :
// Name: Monica Geller
// ID: 51
// Grade: D
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    public:
        string firstName;
        string lastName;
        int id;
        int numscore;
        vector<int> testScore;
        void printPerson(){
            cout << "Name: " << firstName << " " << lastName << endl;
            cout << "ID: " << id << endl;
        }
};

class Student : public Person {
    public:
        Student(string f,string l,int id,int arr[],int numscore){
            this->firstName=f;
            this->lastName=l;
            this->id=id;
            this->numscore=numscore;
            this->testScore.assign(arr,arr+numscore);
        }
        char calculate(){
            int sum=0;
            for(int i=0;i<numscore;i++){
                sum+=testScore[i];
            }
            sum/=numscore;
            if(sum>=90 && sum<=100){
                return 'O';
            }else if(sum>=80 && sum<90){
                return 'E';
            }else if(sum>=70 && sum<80){
                return 'A';
            }else if(sum>=55 && sum<70){
                return 'P';
            }else if(sum>=40 && sum<55){
                return 'D';
            }else{
                return 'T';
            }
        }
};

int main() {
    string firstName, lastName;
    int id, numScores;

    cin >> firstName >> lastName >> id >> numScores;

    int testScores[10]; // Assuming the maximum number of scores is 10
    for (int i = 0; i < numScores; i++) {
        cin >> testScores[i];
    }

    Student s(firstName, lastName, id, testScores, numScores);
    s.printPerson();
    cout << "Grade: " << s.calculate();

    return 0;
}