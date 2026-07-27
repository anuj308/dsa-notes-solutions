
// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

bool dfs(int g,vector<int> adj[],vector<int>& vis,vector<int>& pathVis){
    vis[g]=1;
    pathVis[g]=1;
    for(auto v : adj[g]){
        if(!vis[v]){
            if(dfs(v,adj,vis,pathVis)) return true;
        }else if(pathVis[v]) return true;
    }
    pathVis[g]=0;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> vis(V,0);
    vector<int> pathVis(V,0);
    vector<int> adj[V];
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
    }
    
    for(int g=0;g<V;g++){
        if(!vis[g]){
            if(dfs(g,adj,vis,pathVis)) return true;
        }
    }
    return false;
}