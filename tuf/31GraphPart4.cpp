
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