
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