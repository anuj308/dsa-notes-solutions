// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

// mst is where a subset of graph where n node and n-1 edges are there
// tc - O(E log V) , sc -O(V+E)
int spanningTree(int V, vector<vector<int>>& edges) {
    // code here
    vector<vector<pair<int,int>>> adj(V);
    for(auto e : edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    
    int sum = 0;
    vector<int> vis(V,0);
    minHeap.push({0,0});
    while(!minHeap.empty()){
        auto [cost,u] = minHeap.top();
        minHeap.pop();
        if(vis[u]==1) continue;
        vis[u]=1;
        sum+=cost;
        for(auto [v,w] : adj[u]){
            if(vis[v]==0){
                minHeap.push({w,v});
            }
        }
    }
    return sum;
}