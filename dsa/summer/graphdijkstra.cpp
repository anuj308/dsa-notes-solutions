

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

    vector<vector<pair<int,int>>> adj(V);
    for(auto e : edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    minHeap.push({0,src});
    vector<int> dis(V,INT_MAX);
    dis[src]=0;
    while(!minHeap.empty()){
        int node = minHeap.top().second;
        int d = minHeap.top().first;
        minHeap.pop();
        if(dis[node]!=d) continue;
        for(auto it : adj[node]){
            int v = it.first;
            int w = it.second;
            if(dis[node]+w<dis[v]){
                dis[v]=dis[node]+w;
                minHeap.push({dis[v],v});
            }
        }
    }
    
    return dis;
}