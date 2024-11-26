// /Single File Programming Question
// Problem Statement



// Shekin is developing a program to assist a robot in navigating a warehouse. The warehouse is depicted as a grid, with specific cells representing obstacles that the robot must avoid.



// Your task is to create a program that uses Depth-First Search (DFS) to determine a path for the robot to travel from an initial position to a designated target location within the warehouse.

// Input format :
// The first line of input consists of two integers separated by a space: V and E, where V represents the number of vertices (cells) in the warehouse grid and E represents the number of edges (connections between cells) indicating possible paths.

// The next E lines each consist of two integers, v and w, separated by a space, representing an edge connecting cell v to cell w.

// The last line consists of a single integer, startVertex, which is the starting position of the robot within the warehouse.

// Output format :
// The output should print a message in the format "Depth First Traversal starting from vertex [startVertex]:", where [startVertex] is the integer representing the initial cell.



// Following that next line, it should list the visited cells in DFS traversal order, separated by spaces.



// Refer to the sample output for the exact format.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ V ≤ 10

// 0 <= E <= V*(V-1)/2

// 0 <= v, w < V

// 0 <= startVertex <= V

// Sample test cases :
// Input 1 :
// 6 6
// 0 1
// 0 2
// 1 3
// 2 4
// 3 5
// 4 5
// 0
// Output 1 :
// Depth First Traversal starting from vertex 0:
// 0 1 3 5 2 4 
// Input 2 :
// 5 4
// 0 1
// 0 2
// 1 3
// 3 4
// 0
// Output 2 :
// Depth First Traversal starting from vertex 0:
// 0 1 3 4 2 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <iostream>
using namespace std;
#define MAX_VERTICES 100

// You are using GCC
void addEdge(int adj[MAX_VERTICES][MAX_VERTICES], int v, int w) {
    adj[v][w]=1;
}

void DFS(int adj[MAX_VERTICES][MAX_VERTICES], int visited[MAX_VERTICES], int V, int v) {
    
    visited[v]=1;
    cout << v << " ";
    
    for(int i=0;i<V;i++){
        if(adj[v][i] == 1 && !visited[i]){
            DFS(adj, visited, V, i);
        }
    }
}



int main() {
    int V, E;
    cin >> V;
    cin >> E;

    int adj[MAX_VERTICES][MAX_VERTICES] = {0};
    int visited[MAX_VERTICES] = {0};

    for (int i = 0; i < E; ++i) {
        int v, w;
        cin >> v >> w;
        addEdge(adj, v, w);
    }

    int startVertex;
    cin >> startVertex;

    cout << "Depth First Traversal starting from vertex " << startVertex << ":\n";
    DFS(adj, visited, V, startVertex);

    return 0;
}