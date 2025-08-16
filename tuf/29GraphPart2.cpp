

// Problem: Is Graph Biparite (785)
// URL: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// m is edges
// TC: O(n+m), SC: O(n)
bool dfs(int g, int toColored, vector<int> &col, vector<vector<int>> &graph)
{
    col[g] = toColored;
    if (toColored == 1)
        toColored = 2;
    else
        toColored = 1; // change color
    for (auto v : graph[g])
    {
        if (col[v] == 0)
        {
            if (!dfs(v, toColored, col, graph))
                return false;
        }
        else if (col[g] == col[v])
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> col(n, 0);
    // 0 - not visited
    // 1 - color 1 visted
    // 2 - color 2 visited
    for (int g = 0; g < n; g++)
    {
        if (col[g] == 0)
        {
            if (!dfs(g, 1, col, graph))
                return false;
        }
    }
    return true;
}

/* ==================== PYTHON SOLUTION ====================
// m is edges
# TC: O(n+m), SC: O(n)
class Solution:
    def dfs(self,g,adj,vis,pathVis):
        vis[g]=1
        pathVis[g]=1
        for v in adj[g]:
            if not vis[v]:
                if self.dfs(v,adj,vis,pathVis):
                    return True
            elif pathVis[v]:
                return True
        pathVis[g]=0
        return False
    def isCycle(self, V, edges):
        
        vis = [0]*V
        pathVis = [0]*V
        
        adj = [[] for _ in range(V)]
        
        for u,v in edges:
            adj[u].append(v)
        
        for g in range(0,V):
            if not vis[g]:
                if self.dfs(g,adj,vis,pathVis):
                    return True
        return False
*/

/* ==================== JAVA SOLUTION ====================
class Solution {
    public boolean dfs(int g,ArrayList<ArrayList<Integer>> adj,int[] vis,int[] visPath){
        vis[g]=1;
        visPath[g]=1;
        for(int e : adj.get(g)){
            if(vis[e]==0){
                if(dfs(e,adj,vis,visPath)) return true;
            }else if(visPath[e]==1) return true;
        }
        visPath[g]=0;
        return false;
    }
    public boolean isCyclic(int V, int[][] edges) {
        int[] vis = new int[V];
        int[] visPath = new int[V];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        
        for(int i=0;i<V;i++){
            adj.add(new ArrayList<>());
        }
        for(int[] e : edges){
            adj.get(e[0]).add(e[1]);
        }
        for(int g=0;g<V;g++){
            if(vis[g]==0){
                if(dfs(g,adj,vis,visPath)) return true;
            }
        }
        return false;
    }
}
*/

// topological sort algo (DFS)
// - linear ordering  of vertices such that if there is and edge between u & v , u appears before V in that ordering
//  works in DAG only.(directed acyclic graph)

// Problem: Topological sort 
// URL: https://www.geeksforgeeks.org/problems/topological-sort/1
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
void dfs(int g,vector<int> adj[],vector<int>& vis,stack<int>& st){
        vis[g]=1;
        for(auto e : adj[g]){
            if(!vis[e]){
                dfs(e,adj,vis,st);
            }
        }
        st.push(g);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> vis(V,0);
        stack<int> st;
        vector<int> adj[V];
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
        }
        for(int g=0;g<V;g++){
            if(!vis[g]){
                dfs(g,adj,vis,st);
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

/* ==================== PYTHON SOLUTION ====================
# TC: O(n), SC: O(n)
class Solution:
    def dfs(self,g,adj,vis,stack):
        vis[g]=1
        for v in adj[g]:
            if not vis[v]:
                self.dfs(v,adj,vis,stack)
        stack.append(g)
        
    def topoSort(self, V, edges):
        vis = [0]*V
        stack = []
        
        adj = [[] for _ in range(0,V)]
        
        for u,v in edges:
            adj[u].append(v)
        
        for g in range(0,V):
            if not vis[g]:
                self.dfs(g,adj,vis,stack)
        
        return stack[::-1];
*/

/* ==================== JAVA SOLUTION ====================
class Solution {
    public static void dfs(int g,ArrayList<ArrayList<Integer>> adj,int[] vis,Stack<Integer> stack){
        vis[g]=1;
        
        for(int v : adj.get(g)){
            if(vis[v]==0){
                dfs(v,adj,vis,stack);
            }
        }
        stack.push(g);
    }
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        ArrayList<Integer> ans= new ArrayList<>();
        int[] vis = new int[V];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        for(int i=0;i<V;i++){
            adj.add(new ArrayList<>());
        }
        for(int[] e : edges){
            adj.get(e[0]).add(e[1]);
        }
        for(int g=0;g<V;g++){
            if(vis[g]==0){
                dfs(g,adj,vis,stack);
            }
        }
        while(!stack.isEmpty()){
            ans.add(stack.pop());
        }
        return ans;
    }
}
*/