
// Problem: shortest-path-in-undirected-graph-having-unit-distance ()
// URL: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class Solution {
    public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> ans(n,INT_MAX); // dis
        vector<bool> vis(n,false);
        queue<int> q; // node , distance
        ans[src]=0;
        vis[src]=true;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto e : adj[node]){
                if(!vis[e]){
                    ans[e]=ans[node]+1;
                    vis[e]=true;
                    q.push(e);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================




// Problem: shortest-path-in-undirected-graph ()
// URL: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class Solution {
  public:
    void topoSort(int node,vector<vector<pair<int,int>>>& adj,vector<bool>& vis,stack<int>& st){
        vis[node]=true;
        for(auto e : adj[node]){
            if(!vis[e.first]){
                topoSort(e.first,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V); //V
        for(auto e : edges){
            //   u               v     edges weight
            adj[e[0]].push_back({e[1],e[2]});
        }
        // topp sort
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){ // O(V+E)
            if(!vis[i]){
                topoSort(i,adj,vis,st); 
            }
        }
        
        //  take node from stack and update the distance
        vector<int> dis(V,INT_MAX);
        dis[0]=0;
        while(!st.empty()){ // O(V+E)
            int node = st.top();
            st.pop();
            if(dis[node]!=INT_MAX){
                for(auto e : adj[node]){
                    dis[e.first]=min(dis[e.first],dis[node]+e.second);
                }
            }
        }
        for(int i=0;i<V;i++){ //V
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================
