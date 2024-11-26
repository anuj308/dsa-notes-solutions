// Single File Programming Question
// Problem statement﻿



// Sarah has been tasked with developing a program to determine the shortest paths among nodes in a network represented as a graph containing nodes and weighted edges. 



// Her goal is to implement the Floyd-Warshall algorithm to compute the shortest path matrix for this network.

// Input format :
// The first line of input consists of an integer 'n', representing the number of nodes in the network.

// The next 'n' lines contain 'n' space-separated integers, representing the adjacency matrix 'graph' of the network. Each integer is the weight of the edge from node 'i' to node 'j'.

// Output format :
// The output prints the shortest path matrix as 'n x n' integers, where each element graph[i][j] represents the shortest distance from node 'i' to node 'j'.

// Print each row of the matrix on a new line, with elements separated by a space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the given test cases will fall under the following constraints:

// 1 ≤ n ≤ 100

// 0 ≤weight of edge≤ 999

// graph[i][i] = 0

// Sample test cases :
// Input 1 :
// 4
// 0 3 999 4
// 8 0 2 999
// 5 999 0 1
// 2 999 999 0
// Output 1 :
// 0 3 5 4 
// 5 0 2 3 
// 3 6 0 1 
// 2 5 7 0 
// Input 2 :
// 3
// 0 1 2
// 3 0 4
// 5 6 0
// Output 2 :
// 0 1 2 
// 3 0 4 
// 5 6 0 
// Input 3 :
// 4
// 0 5 999 10
// 999 0 3 999
// 999 999 0 1 
// 999 999 999 0
// Output 3 :
// 0 5 8 9 
// 999 0 3 4 
// 999 999 0 1 
// 999 999 999 0 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>// You are using GCC
void floydWarshall(int **graph, int n)
{
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                graph[i][j] =std:: min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main(void)
{
    int n, i, j;
    std::cin >> n;
    int **graph = (int **)std::malloc((long unsigned)n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)std::malloc((long unsigned)n * sizeof(int));
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 100;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            std::cin >> graph[i][j];
        }
    }

    floydWarshall(graph, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
