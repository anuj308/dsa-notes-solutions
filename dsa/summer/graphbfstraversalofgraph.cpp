
// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

vector<int> bfs(vector<vector<int>> &adj) {
    // code here
    vector<int> ans;
    int n = adj.size();
    vector<int> vis(n,0);
    queue<int> q;
    q.push(0);
    vis[0]=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    
    return ans;
}