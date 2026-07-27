
// https://www.geeksforgeeks.org/problems/topological-sort/1

 void dfs(int node,stack<int>& st,vector<vector<int>>& adj,vector<int>& vis){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it,st,adj,vis);
    }
    st.push(node);
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    vector<int> ans;
    vector<vector<int>> adj(V);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<int> vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,st,adj,vis);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}