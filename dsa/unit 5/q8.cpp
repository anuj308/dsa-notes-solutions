// Single File Programming Question
// Problem Statement



// Joyal, a logistics manager, is responsible for optimizing the dispatch of delivery trucks based on their fuel consumption rates. To achieve this, he implements a min-heap data structure that organizes the trucks so that the one with the lowest fuel consumption is always at the top.



// After selecting the most efficient truck for dispatch, Joyal needs to delete this minimum element from the min-heap and ensure that the next lowest fuel-consuming truck becomes available for the next delivery. Can you assist Joyal in automating this process efficiently?

// Input format :
// The first line contains an integer n, representing the number of delivery trucks.

// The second line contains n space-separated integers, representing the fuel consumption rates of the trucks.

// Output format :
// The output prints the updated min-heap after deleting the minimum element.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ n ≤ 9

// 1 ≤ fuel consumption rates ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 12 54 90 21 60
// Output 1 :
// 21 54 90 60 
// Input 2 :
// 8
// 27 21 53 12 89 22 65 56
// Output 2 :
// 21 27 22 56 89 53 65 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
