// Single File Programming Question
// Problem Statement



// Latha is studying graph theory and is currently learning about finding the shortest paths in a weighted directed graph. She wants to implement the Floyd-Warshall algorithm to compute the shortest distances between all pairs of vertices in the graph.



// Write a program to help Latha determine the shortest distances between all pairs of vertices in a given graph.

// Input format :
// The first line of input consists of two integers, V and E, where:

// V is the number of vertices (0-indexed).
// E is the number of edges in the graph.
// The next E lines each contain three integers, u, v, and w, representing a directed edge from vertex u to vertex v with weight w.

// Output format :
// For each vertex pair (i, j), print the shortest distance from i to j. If there is no path from i to j, print INF.

// The diagonal elements are 0 as there will be no connection between the same element and to same element ( Eg: 0 to 0,1 to 1 so on..).



// Refer to the sample output for formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ V ≤ 4

// 0 ≤ E ≤ V ∗ (V − 1) / 2

// 0 ≤ u, v < V

// −100 ≤ w ≤ 100

// Sample test cases :
// Input 1 :
// 3 3
// 0 1 3
// 1 2 2
// 2 0 1
// Output 1 :
// 0 3 5 
// 3 0 2 
// 1 4 0 
// Input 2 :
// 4 4
// 0 1 5
// 1 2 3
// 2 3 1
// 0 3 10
// Output 2 :
// 0 5 8 9 
// INF 0 3 4 
// INF INF 0 1 
// INF INF INF 0 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// Marks : 10
// Negative Marks : 0

// You are using GCC
void floydWarshall(int n, vector<vector<int>> &graph) {
    
   
    for(int k=0;k<n;k++){
        for(int i=0; i<n;i++){
            for(int j=0;j<n; j++){
                graph[i][j]=min(graph[i][j],graph[i][k],graph[k][j]);
            }
        }
    }
    
     for(int i=0; i<n;i++){
            for(int j=0;j<n; j++){
                if(graph[i][j]==0){
                    cout << "INF" << " ";
                }else if(i==i){
                    cout << 0 << " ";
                }else{
                    cout << graph[i][j] << " ";
                }
            }
            cout << endl;
        }
    
}
int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0; 
    }
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }
    floydWarshall(n, graph);
    return 0;
}