// https://www.geeksforgeeks.org/problems/number-of-provinces/1

void dfs(int node,vector<vector<int>>& adj,vector<int>&vis){
    vis[node]=1;
    
    for(auto it : adj[node]){
        
        if(!vis[it]) dfs(it,adj,vis);
    }
}
int countConnected(int V, vector<vector<int>>& edges) {
    // code here
    int c = 0;
    vector<int> vis(V,0);
    vector<vector<int>> adj(V);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    for(int i=0;i<V;i++){
        if(!vis[i]){
            c++;
            dfs(i,adj,vis);
        }
    }
    return c;
}