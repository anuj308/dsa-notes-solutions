
// disjoint  set (union by rank)
//  by this we can find answer like in a graph does two node belong to same component or not in constant time and at every stage of graph formation.
// for brute force we can do dfs from the node and check do we find the other node or not.

// union(u,v)
//  pseudocode
// 1) find rank of ultimate parent of u,v
// 2) find rank of pu,pv
// 3) connect smaller

//  tc - O(4x) == constant
// path compression

// why joining low rank to high rank ? - so the height will be less and findParent will take less time to compute

// class DisjointSet{
//     vector<int> rank,parent;
//     public:
//         DisjointSet(int n){
//             rank.resize(n+1,0);
//             parent.resize(n+1);
//             for(int i = 0;i<=n;i++){
//                 parent[i] = i;
//             }
//         }
//         int findParent(int node){
//             if(node == parent[node]) return node;
//             return parent[node] = findParent(parent[node]);
//         }
//         void unionByRank(int u,int v){
//             int ulp_u = findParent(u);
//             int ulp_v = findParent(v);
//             if(ulp_u == ulp_v) return;
//             if(rank[ulp_u]<rank[ulp_v]){
//                 parent[ulp_u] = ulp_v;
//             }else if(rank[ulp_u] > rank[ulp_v]){
//                 parent[ulp_v] = ulp_u;
//             }else{
//                 parent[ulp_v] = ulp_u;
//                 rank[ulp_u]++;
//             }
//         }
// }
// int main(){
//     DisjointSet ds(7);
//     ds.unionByRank(1,2);
//     ds.unionByRank(2,3);
//     ds.unionByRank(4,5);
//     ds.unionByRank(5,6);
//     ds.unionByRank(6,7);
//     //  does 3 and 6 belong to same components
//     if(ds.findParent(3)==ds.findParent(7)) cout << "same" ;
//     else cout << "not same";
//     ds.unionByRank(3,7);
//     if(ds.findParent(3)==ds.findParent(7)) cout << "same" ;
//     else cout << "not same";

//     return 0;
// }

// union by size 

class DisjointSet{
    vector<int> size,parent;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
}
// int main(){
//     DisjointSet ds(7);
//     ds.unionBySize(1,2);
//     ds.unionBySize(2,3);
//     ds.unionBySize(4,5);
//     ds.unionBySize(5,6);
//     ds.unionBySize(6,7);
//     //  does 3 and 6 belong to same components
//     if(ds.findParent(3)==ds.findParent(7)) cout << "same" ;
//     else cout << "not same";
//     ds.unionBySize(3,7);
//     if(ds.findParent(3)==ds.findParent(7)) cout << "same" ;
//     else cout << "not same";

//     return 0;
// }

// kruskak algorithm

// sort all edges according to weight
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<pair<int,pair<int,int>>> edwt(V); // V
        for(auto it : edges){ // E
            int u = it[0];
            int v = it[1];
            int w = it[2];
            edwt.push_back({w,{u,v}});
            edwt.push_back({w,{v,u}});
        }
        
        sort(edwt.begin(),edwt.end()); // E log E
        int sum = 0;
        DisjointSet ds(V); // sc - O(2V)
        for(auto e : edwt){
            int u = e.second.first;
            int v = e.second.second;
            int w = e.first;
            if(ds.findParent(u)!=ds.findParent(v)){ // tc-O(4x)
                sum+=w;
                ds.unionBySize(u,v); // tc-O(4x)
            }
        }
        return sum;
        // tc - O(e log e), , Sc-O(3E)
    }
};



// Problem: 1319. Number of Operations to Make Network Connected
// URL: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = 0;
        DisjointSet ds(n);
        int extra = 0;
        for(auto c : connections){
            if(ds.findParent(c[0])!=ds.findParent(c[1])){
                ds.unionBySize(c[0],c[1]);
            }else extra++;
        }
        int components = 0;
        for(int i=0;i<n;i++){
            if(ds.findParent(i)==i) components++;
        }
        if(extra>=components-1) return components-1;
        return -1;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================

// Problem: 947. Most Stones Removed with Same Row or Column
// URL: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class DisjointSet{
    vector<int> size,parent;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow+maxCol+2);
        for(auto s : stones){
            int u = s[0];
            int v = s[1] + maxRow +1;
            if(ds.findParent(u)!=ds.findParent(v)){
                ds.unionBySize(u,v);
            }
        }
        int component = 0;
        vector<int> groups(maxRow+maxCol+2,0);
        for(int i=0;i<maxRow+maxCol+2;i++){
            int p = ds.findParent(i);
            if(p!=i){
                if(groups[p]==0) {
                    groups[p]=1;
                    component++;
                }
            }
        }
        return n-component;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================

// Problem: 721. Accounts Merge
// URL: https://leetcode.com/problems/accounts-merge/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class DisjointSet{
    vector<int> size,parent;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mpp;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                string email = accounts[i][j];
                if(mpp.find(email)!=mpp.end()){
                    ds.unionBySize(mpp[email],i);
                }else mpp[email]=i;
            }
        }
        unordered_map<int,vector<string>> acc;
        vector<vector<string>> ans;
        for(auto m : mpp){
            string email = m.first;
            int id = m.second;
            int p = ds.findParent(id);

            if(acc[p].size()==0){
                acc[p].push_back(accounts[p][0]);
                acc[p].push_back(email);
            }else acc[p].push_back(email);
        }
        for(auto a : acc){
            sort(a.second.begin()+1,a.second.end());
            if(a.second.size()!=0) ans.push_back(a.second);
        } 
        return ans;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================


// Problem: 827. Making A Large Island
// URL: https://leetcode.com/problems/making-a-large-island/
// Difficulty: Hard
// ==================== C++ SOLUTION ====================
// TC: O(n*n*4x*2), SC: O(3n)
class DisjointSet{
    vector<int> size,parent;
    public:
        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionBySize(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
};
class Solution {
public:
    int getNode(int row,int col,int n){
        return (row*n)+col;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> sum(n*n,0);
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                vector<pair<int,int>> dir = {{0,-1},{0,+1},{-1,0},{+1,0}};
                int u = getNode(i,j,n);
                for(auto d : dir){
                    int row = i+d.first;
                    int col = j+d.second;
                    if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==1){
                        int v = getNode(row,col,n);
                        if(ds.findParent(u)!=ds.findParent(v)){
                            ds.unionBySize(u,v);
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum[ds.findParent(getNode(i,j,n))]++;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vector<pair<int,int>> dir = {{0,-1},{0,+1},{-1,0},{+1,0}};
                    int nodeSum = 0;
                    unordered_map<int,int> sumFrom;
                    for(auto d : dir){
                        int row = i+d.first;
                        int col = j+d.second;
                        if(row>=0 && row<n && col>=0 && col<n && grid[row][col]==1){
                            int p = ds.findParent(getNode(row,col,n));
                            if(sumFrom.find(p)==sumFrom.end()){
                                nodeSum+=sum[p];
                                sumFrom[p]++;
                            }
                        }
                    }
                    ans=max(ans,nodeSum+1);
                }
            }
        }
        for(int i=0;i<n*n;i++){
            ans=max(ans,sum[i]);
        }
        return ans;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================


// Problem: 778. Swim in Rising Water
// URL: https://leetcode.com/problems/swim-in-rising-water/
// Difficulty: Hard
// ==================== C++ SOLUTION ====================
// TC: O(n*n*logn), SC: O(n*n)
class Solution {
    public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        minHeap.push({max(0,grid[0][0]),{0,0}});
        dis[0][0]=0;
        while(!minHeap.empty()){
            int time = minHeap.top().first;
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            minHeap.pop();
            if(row == n-1 && col == n-1) return time;
            vector<pair<int,int>> dir = {{0,-1},{0,+1},{+1,0},{-1,0}};
            for(auto d : dir){
                int nrow = row+d.first;
                int ncol = col+d.second;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && dis[nrow][ncol]>max(time,grid[nrow][ncol])){
                    int ntime = max(time,grid[nrow][ncol]);
                    dis[nrow][ncol]= ntime;
                    minHeap.push({ntime,{nrow,ncol}});
                }
            }
        }
        return dis[n-1][n-1];
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================




// Problem: 192. Critical Connections in a Network
// URL: https://leetcode.com/problems/critical-connections-in-a-network/
// Difficulty: Hard
// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(4n)

class Solution {
    private:
    int timer = 1;
public:
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis,vector<vector<int>>& ans,vector<int>& low,vector<int>& top){
        vis[node]=1;
        low[node]=top[node] = timer;
        timer++;
        for(auto e : adj[node]){
            if(e==parent) continue;
            if(vis[e]==0){
                dfs(e,node,adj,vis,ans,low,top);
                low[node] = min(low[node],low[e]);

                if(low[e]>top[node]){
                    ans.push_back({e,node});
                }
            }else{
                low[node] = min(low[node],low[e]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> ans; // bridge
        vector<int> vis(n,0);
        vector<int> low(n,0); // min time(top) of add adjacent node apart from parent 
        vector<int> top(n,0); // store the time of insertion during dfs
        vector<vector<int>> adj(n);
        int nc = connections.size();
        for(auto c : connections){
            int u = c[0];
            int v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj,vis,ans,low,top);

        return ans;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================


// articulation point - nodes om whose removal the graph breaks into multiple components.
// vector<int> low(n,0); // min time(top) of add adjacent node apart from parent and visited nodes
// vector<int> top(n,0); // store the time of insertion during dfs



// Problem: Articulation Point
// URL: https://www.geeksforgeeks.org/problems/articulation-point-1/1
// Difficulty: Hard
// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(4n)

// User function Template for C++

class Solution { 
    private:
    int timer = 1;
    public:
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis,vector<int>& mark,vector<int>& low,vector<int>& tin){
        vis[node]=1;
        low[node]=tin[node] = timer;
        timer++;
        int child = 0;
        for(auto e : adj[node]){
            if(e==parent) continue;
            if(vis[e]==0){
                dfs(e,node,adj,vis,mark,low,tin);
                low[node] = min(low[node],low[e]);
                if(low[e]>=tin[node] && parent != -1){
                    mark[node]=1;
                }
                child++;
            }else{
                low[node] = min(low[node],tin[e]); 
            }
        }
        if(child>1 && parent == -1) mark[node]=1; 
    }
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> ans; // bridge
        vector<int> mark(V,0);
        vector<int> vis(V,0);
        vector<int> low(V,0); // min time(tin) of add adjacent node apart from parent and visited nodes
        vector<int> tin(V,0); // store the time of insertion during dfs
        dfs(0,-1,adj,vis,mark,low,tin);
        for(int i=0;i<V;i++){
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================
