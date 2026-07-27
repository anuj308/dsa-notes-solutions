
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
    vector<int> dis(n+1,INT_MAX);
    vector<vector<pair<int,int>>> adj(n+1);
    dis[k]=0;
    for(auto e : times){
        adj[e[0]].push_back({e[1],e[2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    minHeap.push({0,k});
    while(!minHeap.empty()){
        auto [d,u] = minHeap.top();
        minHeap.pop();
        if(d!=dis[u]) continue;
        for(auto [v,w] : adj[u]){
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                minHeap.push({dis[v],v});
            }
        } 
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(dis[i]==INT_MAX) return -1;
        ans=max(ans,dis[i]);
    }
    return ans;
}