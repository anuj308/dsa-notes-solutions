// // Single File Programming Question
// // Problem Statement



// // Bindu is working on a program to convert decimal numbers to binary representation using a stack data structure implemented with a linked list. She needs your help in designing and implementing this program.



// // Your task is to design and implement the stack with the specified push and pop operations to support this conversion.

// // Input format :
// // The input consists of an integer d, representing the decimal number to be converted into binary.

// // Output format :
// // The output prints "Binary representation: " followed by the binary representation of the input decimal number.



// // Refer to the sample output for formatting specifications.

// // Code constraints :
// // The stack used for the conversion can have a maximum size of 32.

// // 1 ≤ d ≤ 512

// // Sample test cases :
// // Input 1 :
// // 10
// // Output 1 :
// // Binary representation: 1010
// // Input 2 :
// // 37
// // Output 2 :
// // Binary representation: 100101
// // Note :
// // The program will be evaluated only after the “Submit Code” is clicked.


// #include <iostream>
// #include <stack>
// #include <vector>
// using namespace std;

// int main(){
    
//     int n;
//     cin >> n;
    
//     stack<int> task;
//     int t =n;
//     while(t>0){
//         int ans = t%2;
//         t=t/2;
//         task.push(ans);
//     }
    
//     cout << "Binary representation: ";
    
//     while(!task.empty()){
//         cout << task.top();
//         task.pop();
//     }
    
//     return 0;
// }


