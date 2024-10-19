// Single File Programming Question
// Problem Statement



// The Tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to another rod. You are given the number of disks N. Initially, these disks are in rod 1. You need to print all the steps of disk movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.



// Note: The disks are arranged such that the top disk is numbered 1 and the bottom-most disk is numbered N. Also, all the disks have different sizes, and a bigger disk cannot be put on top of a smaller disk. 

// Input format :
// The input consists of a single integer N, representing the number of disks initially placed on rod 1.

// Output format :
// The output prints a series of lines representing each move of a disk from one rod to another.

// After all moves are printed, the last line prints the total number of moves made during the Tower of Hanoi puzzle.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 8

// Sample test cases :
// Input 1 :
// 2
// Output 1 :
// move disk 1 from rod 1 to rod 2
// move disk 2 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 3
// 3
// Input 2 :
// 3
// Output 2 :
// move disk 1 from rod 1 to rod 3
// move disk 2 from rod 1 to rod 2
// move disk 1 from rod 3 to rod 2
// move disk 3 from rod 1 to rod 3
// move disk 1 from rod 2 to rod 1
// move disk 2 from rod 2 to rod 3
// move disk 1 from rod 1 to rod 3
// 7
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;

int moveDisks(int n, char source, char auxiliary, char destination,int ans){
    if(n == 0){
        return 0;
    }
    
    int moves = moveDisks(n-1,source,destination,auxiliary,ans); // source to auxiliary
    
    cout << "Move disk " << n << " from rod " << source << " to rod " << destination << endl;
    moves++;
    
    moves += moveDisks(n-1,auxiliary,source,destination,ans); // auxiliary to destination
    return moves;
}

int main() {
    int n;
    cin >> n;
    
    int totalMoves = moveDisks(n, '1', '2', '3',0);
    
    cout << totalMoves << endl;
    
    return 0;
}