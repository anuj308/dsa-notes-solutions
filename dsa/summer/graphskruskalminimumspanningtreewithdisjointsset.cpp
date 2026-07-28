
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// tc - O(4@) -- constant O(1)
class DisjointSet {
    vector<int>parent,size;
public: 
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++) {
            parent[i]=i;
        }
    }
    int findUParent(int u) {
        if(parent[u]==u) {
            return u;
        }
        return parent[u]=findUParent(parent[u]);
    }
    void unionBySize(int u,int v) {
        int ulp_u=findUParent(u);
        int ulp_v=findUParent(v);

        if(ulp_u==ulp_v)
            return;
        if(size[ulp_u]<size[ulp_v]) {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        DisjointSet dsu(V);
        vector<pair<int,pair<int,int>>> ed;
        for(auto e : edges){
            ed.push_back({e[2],{e[0],e[1]}});
        }
        
        sort(ed.begin(),ed.end());
        
        int sum = 0;
        for(auto it : ed){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(dsu.findUParent(u)!=dsu.findUParent(v)){
                dsu.unionBySize(u,v);
                sum+=wt;
            }
        }
        return sum;
    }
};