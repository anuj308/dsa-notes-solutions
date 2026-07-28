// https://codeforces.com/problemset/problem/1167/C


#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    public: 
    vector<int>parent,size;
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


int main(){
    int n,g;
    cin >> n >> g;
    DisjointSet dsu(n);
    for(int i=0;i<g;i++){
        int si;
        cin >> si;
        int u;
        for(int j=0;j<si;j++){
            int val;
            cin >> val;
            if(j==0) u=val;
            else dsu.unionBySize(u,val);
        }
    }

    for(int i=1;i<=n;i++){
        int ulp_P =  dsu.findUParent(i);
        cout << dsu.size[ulp_P] << " ";
    }

    return 0;
}