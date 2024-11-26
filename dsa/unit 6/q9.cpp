// Single File Programming Question
// Problem Statement



// Sam is working on optimizing a data storage system that relies on efficient indexing and retrieval of data using a custom hashing algorithm.



// To accomplish this, he is tasked with designing a program to calculate hash values for given text keys.



// Note:

// The hash value is calculated as follows: 

// Initialize 'hashVal' to 0. 
// For each character 'ch' (ASCII value) in the 'text': 
// Update 'hashVal' using the formula: hashVal = 37 * hashVal + ch. 
// Finally, return 'hashVal % tSize' as the hash index.
// Input format :
// The first line of input consists of the string text, representing the text-based key.

// The second line consists of an integer tSize, representing the size of the hash table.

// Output format :
// The output displays an integer representing the calculated hash index using the hash function.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ text ≤ 102

// 1 ≤ tSize ≤ 109

// The string text contains lowercase and uppercase letters without any space.

// Sample test cases :
// Input 1 :
// Maximum
// 10000
// Output 1 :
// 5954
// Input 2 :
// Priority
// 10000
// Output 2 :
// 1174
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


// rember for big value use unsigned int like in this question i was getting wrong testcase as in int the value overflowed

// You are using GCC
unsigned int hashCalc(string key, int tableSize) {
    unsigned int hashVal = 0;
    for(auto c : key){
        hashVal = 37*hashVal + c;
        // cout << c << hashVal << endl;
    }
    return hashVal%tableSize;
}

int main() {
   
   string text;
   int n;
   cin >> text;
   cin >> n;
   
   int ans = hashCalc(text,n);
   cout << ans;