// Single File Programming Question
// Problem Statement



// Lithish is working on a project that involves analyzing the connectivity of various data points represented as vertices in a graph. He needs to perform Depth First Traversal (DFS) on the given graph (connected undirected graph) to explore its vertices and understand the relationships between them.



// Write a program to help Lithish perform DFS on the given graph.

// Input format :
// The first line of input consists of the two integers V and E, separated by a space. V represents the number of vertices, and E represents the number of edges in the graph.

// The next E lines consist of two integers, v and w, separated by a space, indicating an edge between vertex v and vertex w.

// The last line of input consists of the startVertex, representing the starting vertex for DFS traversal.

// Output format :
// The output should print the Depth First Traversal of the graph starting from a specified vertex, following format:

// "Depth First Traversal starting from vertex [vertex]:

// [u1] [u2] [u3]... [un]".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 2 ≤ V ≤ 10

// 0 <= E <= V*(V-1)/2

// 0 <= v, w < V

// 0 ≤ startVertex < V

// Sample test cases :
// Input 1 :
// 4 3
// 0 1
// 1 2
// 2 3
// 0
// Output 1 :
// Depth First Traversal starting from vertex 0:
// 0 1 2 3 
// Input 2 :
// 4 6
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// 3 0
// 1
// Output 2 :
// Depth First Traversal starting from vertex 1:
// 1 2 0 3 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

void Dfs(int node,vector<vector<int>>& adj,vector<bool>& visited){
    visited[node] = true;
    cout << node << " ";
    for(auto it : adj[node]){
        if(!visited[it]){
            Dfs(it,adj,visited);
        }
    }
}

int main(){
    
    int V,E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    vector<bool> visited(V,false);
    
    int v,w;
    for(int i=0; i<E; i++){
        cin >> v >> w;
        adj[v].push_back(w);
    }
    int x;
    cin >> x;
    cout << "Depth First Traversal starting from vertex " << x << ":" << endl;
    Dfs(x,adj,visited);
    
    return 0;
}