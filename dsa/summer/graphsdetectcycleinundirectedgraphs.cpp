
// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

void dfs(int node,int parent,bool& ans,vector<vector<int>>& adj,vector<int>& vis){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it,node,ans,adj,vis);
        else if(it!=parent){
            ans=true;
            break;
        }
    }
}
bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    
    vector<int> vis(V,0);
    
    vector<vector<int>> adj(V);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    
    for(int i=0;i<V;i++){
        bool ans = false;
        if(!vis[i]) dfs(i,-1,ans,adj,vis);
        if(ans) return true;
    }
    
    return false;
}