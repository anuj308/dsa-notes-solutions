// Single File Programming Question
// Problem Statement



// Anu is developing an online quiz platform, and you need to identify the top performers among the participants in each quiz. Each participant's score is stored in an array, and you want to find the two highest scores for each quiz.



// Write a program using class templates to find the two highest scores for both integer and floating-point scores for a given quiz.



// Note: This kind of question will help in clearing Capgemini recruitment.

// Input format :
// The first line contains a single integer, n, representing the number of participants in the quiz.

// The second line contains n space-separated integers representing the integer scores of the participants.

// The third line contains n space-separated floating-point numbers representing the floating-point scores of the participants.

// Output format :
// The first line contains two space-separated integers representing the highest and second-highest integer scores, respectively.

// The second line contains two space-separated floating-point numbers representing the highest and second-highest floating-point scores, respectively.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 1000 (number of participants).

// 0 ≤ integer_score ≤ 100 (integer scores range from 0 to 100).

// 0.00 ≤ floating_point_score ≤ 100.00 (floating-point scores have up to two decimal places).

// Sample test cases :
// Input 1 :
// 5
// 10 31 21 9 8
// 7.8 6.21 3.67 90.99 2.1
// Output 1 :
// 31 21
// 90.99 7.8
// Input 2 :
// 6
// -90 -67 -80 -34 -25 -38
// 0.12 0.111 0.999 0.543 0.67 0.433
// Output 2 :
// -25 -34
// 0.999 0.67
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


// You are using GCC
#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
	T *ptr;
	int size;
public:
	Array(T arr[], int s);
	void print();
};

template <typename T>
Array<T>::Array(T array[], int s) {
    T largest1 = -9999999999;
    T largest2 = -99999999;
    
    for(int j=0;j<s;j++){
        if(array[j]> largest1){
            largest1 = array[j];
        }
    }
    
    // cout << largest1 << endl;
    for(int j=0;j<s;j++){
        
        if(array[j]< largest1 && array[j]> largest2){
            largest2 = array[j];
            
        }
        // cout << largest2 << endl;
    }
    // above is done by me below code was given in question
    
 
    // for (int i = 2; i < s; i++)
    // {
    //     if (array[i] > largest1)
    //     {
    //         largest1 = array[i];

    //     }
    //     else if (array[i] > largest2 && array[i] != largest1)
    //     {
    //         largest2 = array[i];
    //     }
    // }
 
    cout<<largest1<<" "<<largest2;
    
}



int main() {
	
	int n;
	cin>>n;
	int ar[n];
	float br[n];
	for(int i=0;i<n;i++){
	    cin>>ar[i];
	}
	for(int i=0;i<n;i++){
	    cin>>br[i];
	}
	
	Array<int> a(ar, n);
	cout<<"\n";
	Array<float> b(br, n);
	
	return 0;
}