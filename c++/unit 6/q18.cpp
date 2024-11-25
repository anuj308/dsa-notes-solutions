// Single File Programming Question
// Problem Statement



// You have been tasked with creating a Generic Pair Management System that can store and manage pairs of different data types. Each pair consists of two values - a float and a double. The system should provide functionalities to swap the values in the pair and display the pair details.



// Your task is to implement a template class called PairBase that can represent the base class for managing pairs of float and double values. The PairBase class should have the following functionalities:



// swap(): Swap the values in the pair.

// display(): Display the details of the pair, including both float and double values.

// Using the PairBase class, create a derived class template called PairDerived that inherits from PairBase to represent specific pairs of float and double values. The PairDerived class should inherit the functionalities from the base class and provide methods to work with the pair of values.



// Your task is to design the PairBase template class and the PairDerived derived class template to represent the float and double pairs effectively. Demonstrate the functionality of the classes by creating an instance of PairDerived and performing the swap operation on the pair values. Display the pair details before and after the swap to verify the correctness of your implementation.



// Note: This kind of question will be helpful in clearing CTS recruitment.

// Input format :
// The input consists of a floating-point and double-point values

// Output format :
// The output consists of swapping two numbers



// Refer to the sample input and output for format specifications.

// Sample test cases :
// Input 1 :
// 45.43
// 96.25
// Output 1 :
// Values before swap: 
// First: 45.43
// Second: 96.25
// Values after swap: 
// First: 96.25
// Second: 45.43
// Input 2 :
// 968.32
// 478.25
// Output 2 :
// Values before swap: 
// First: 968.32
// Second: 478.25
// Values after swap: 
// First: 478.25
// Second: 968.32
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// this part was to be done it was only editable

template<typename T,typename D>
class PairDerived{
  public:
    T a;
    D b;
    PairDerived(T a,D b) : a(a), b(b){}
    void display(){
        cout << "First: " << a << endl;
        cout << "Second: " << b << endl;
    }
    void swap(){
        T temp = a;
        a = b;
        b = temp;
    }
};
