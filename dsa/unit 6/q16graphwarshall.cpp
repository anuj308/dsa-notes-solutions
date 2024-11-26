// Single File Programming Question
// Problem Statement



// Sharon is developing a program that analyzes the reachability of nodes in a graph. Given an adjacency matrix representing the graph and its size, her goal is to determine whether there exists a path from one vertex to another for all pairs of vertices.



// Write a program to help Sharon perform this reachability analysis using Warshall's Algorithm.

// Input format :
// The first line of input consists of an integer N, representing the number of vertices in the graph.

// The following N lines consist of N space-separated integers, forming the adjacency matrix graph, where graph[i][j] is either 0 or 1.

// Output format :
// The output prints an NxN matrix representing the reachability matrix for all pairs of vertices.

// Each element in the matrix should be 1 if there is a path from the corresponding row vertex to the column vertex and 0 otherwise.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Each element of the adjacency matrix is either 0 or 1.

// Sample test cases :
// Input 1 :
// 4
// 0 1 0 0
// 0 0 1 0
// 0 0 0 1
// 0 0 0 0
// Output 1 :
// 0 1 1 1 
// 0 0 1 1 
// 0 0 0 1 
// 0 0 0 0 
// Input 2 :
// 3
// 0 1 0
// 0 0 1
// 0 0 0
// Output 2 :
// 0 1 1 
// 0 0 1 
// 0 0 0 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
using namespace std;// You are using GCC
void computeReachability(int **graph, int n) {
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(graph[i][k] + graph[k][j] == 2){
                    graph[i][j] = 1;
                }
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    int **graph = new int *[n];
    for (int i = 0; i < n; ++i) {
        graph[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    computeReachability(graph, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        delete[] graph[i];
    }
    delete[] graph;
    return 0;
}