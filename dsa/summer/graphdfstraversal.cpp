
// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}
vector<int> dfs(vector<vector<int>>& adj) {
    // Code here
    int n = adj.size();
    vector<int> vis(n,0);
    vector<int> ans;
    
    dfs(0,adj,vis,ans);
    
    return ans;
}