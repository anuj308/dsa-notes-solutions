// Single File Programming Question
// Problem Statement



// Gopi is working on a project that involves finding the shortest path between two nodes in a graph. He needs your help to implement a program that can efficiently find the shortest path between two nodes using the Breadth-First Search (BFS) algorithm.



// Write a program to help Gopi implement this functionality. The program should take an undirected graph as input and find the shortest path between two given nodes.

// Input format :
// The first line contains an integer, v, representing the number of vertices in the graph.

// The second line contains an integer, e, representing the number of edges in the graph.

// The next e lines each contain two space-separated integers, src and dest, indicating an edge between vertex source and vertex destination.

// The last two lines contain two integers, 'source' and 'destination', which specify the source and destination nodes for which you need to find the shortest path. These two lines are separated by a newline character.

// Output format :
// The output is displayed in the following format:



// The first line consists of "Shortest path length is: X", where X represents the shortest path length.

// The second line consists of "Path is: ", followed by the nodes in the shortest path, space-separated.



// Refer to the sample output for the exact format.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ v ≤ 15

// 0 ≤ e ≤ v * (v - 1) / 2

// 0 ≤ source, destination < v

// Sample test cases :
// Input 1 :
// 8
// 10
// 0 1
// 0 3
// 1 2
// 3 4
// 3 7
// 4 5
// 4 6
// 4 7
// 5 6
// 6 7
// 0 
// 7
// Output 1 :
// Shortest path length is: 2
// Path is: 0 3 7 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


#include <iostream>
#include <climits>
using namespace std;


// You are using GCC
void add_edge(int adj[][100], int src, int dest)
{
    adj[src][dest] = 1;
    adj[dest][src] = 1;
}

bool BFS(int adj[][100], int src, int dest, int v, int pred[], int dist[])
{
    bool visited[v];
    for(int i=0;i<v;i++){
        visited[i]= false;  
        dist[i]=-1;
        pred[i]=-1;
    }
    
    visited[src]= true;
    dist[src]=0;
    
    int currentLevel[v];
    int nextLevel[v];
    int currentLevelCount = 0, nextLevelCount = 0;
    
    currentLevel[currentLevelCount++] = src;
    
    while(currentLevelCount > 0){
        
        for(int i=0; i<currentLevelCount; i++){
            int u = currentLevel[i];
            
            if(u == dest){
                return true;
            }
            
            for(int vtx =0; vtx< 100; vtx++){
                if(adj[u][vtx] == 1 && !visited[vtx]){
                    visited[vtx] = true;
                    dist[vtx] = dist[u] + 1;
                    pred[vtx] = u;
                    nextLevel[nextLevelCount++] = vtx;
                }
            }
        }
            currentLevelCount = nextLevelCount;
            for(int i=0; i<nextLevelCount; i++){
                currentLevel[i] = nextLevel[i];
            }
            nextLevelCount = 0;
    }
    return false;
}

void printShortestDistance(int adj[][100], int s, int dest, int v, int pred[], int dist[])
{
    cout << "Shortest path length is: " << dist[dest] << endl;
    int anscount=0;
    int ans[v];
    int crawl = dest;
    cout << "Path is: ";
    while(crawl != -1){
        ans[anscount] = crawl;
        anscount++;
        crawl = pred[crawl];
    }
    for(int i=anscount - 1; i>=0;i--){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main()
{
    int v, e;
    cin >> v;

    int adj[100][100] = {0};

    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int src, dest;
        cin >> src >> dest;
        add_edge(adj, src, dest);
    }

    int source, dest;
    cin >> source >> dest;

    int pred[v], dist[v];

    if (BFS(adj, source, dest, v, pred, dist))
        printShortestDistance(adj, source, dest, v, pred, dist);
   
    return 0;
}