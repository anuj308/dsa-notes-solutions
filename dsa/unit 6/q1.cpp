// Single File Programming Question
// Problem Statement



// Siddhu works for a logistics company that handles a complex supply chain. This supply chain includes many suppliers, warehouses, and retail stores, all connected through different routes and transportation methods.



// Your job is to assist him in creating a program that utilizes Breadth-First Search (BFS) traversal to improve the supply chain's efficiency. The program will find the best route for delivering products from a supplier to a retail store.

// Input format :
// The first line consists of two integers, V and E, separated by a space, where V represents the number of vertices (locations, suppliers, warehouses, and retail stores), and E represents the number of edges (connections between these locations).

// The next E lines each consist of two integers, u and v, separated by a space, representing an edge between location u and location v.

// Output format :
// The output prints the BFS traversal order of the supply chain, separated by spaces.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 <= V <= 10

// 0 <= E <= V*(V-1)/2

// 0 <= u, v < V

// Sample test cases :
// Input 1 :
// 6 8
// 0 1
// 0 2
// 1 3
// 2 3
// 2 4
// 3 4
// 4 5
// 5 0
// Output 1 :
// 0 1 2 3 4 5 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <bits/stdc++.h>
using namespace std;

class Graph{
  public:
    int V;
    list <int> *adj;
    Graph(int V){
        this->V =V;
        adj = new list<int>[V];
    }
    void addEdge(int v,int w){
        adj[v].push_back(w);
        // adj[w].push_back(v);
    }
    void Bfs(int s){
        // vector<bool> visited(V,false); // this is good then below one
        bool *visited = new bool[V];
        for(int i=0; i< V; i++){
            visited[i] = false;
        }
        list<int> queue;
        visited[s] = true;
        queue.push_back(s);
        list<int> ::iterator i;
        while(!queue.empty()){
            s = queue.front();
            cout << s << " ";
            queue.pop_front();
            for(i = adj[s].begin(); i!= adj[s].end(); i++){
                if(!visited[*i]){
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    }
    
};

int main(){
    int V,E;
    cin >> V >> E;
    int snode,enode;
    Graph g(V);
    while(E!=0){
        cin >> snode >> enode;
        g.addEdge(snode,enode);
        E--;
    }
    g.Bfs(0);
    return 0;
}