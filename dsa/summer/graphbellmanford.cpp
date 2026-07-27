// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// tc - O(v*E), sc-O(v)

// to detect cycle, work in neg weight 
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    // Code here
    vector<int> cost(V,1e8);
    cost[src]=0;
    
    for(int i=0;i<V-1;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(cost[u]!=1e8 && cost[u]+w<cost[v]){
                cost[v]=cost[u]+w;
            }
        }
    }
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        if(cost[u]!=1e8 && cost[u]+w<cost[v]){
            return {-1};
        }
    }
    return cost;
}