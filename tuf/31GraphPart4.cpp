
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

class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i = 0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }
        void unionByRank(int u,int v){
            int ulp_u = findParent(u);
            int ulp_v = findParent(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
}
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(5,6);
    ds.unionByRank(6,7);
    //  does 3 and 6 belong to same components
    if(ds.findParent(3)==ds.findParent(7)) cout << "same" ;
    else cout << "not same";
    ds.unionByRank(3,7);
    if(ds.findParent(3)==ds.findParent(7)) cout << "same" ;
    else cout << "not same";

    return 0;
}

// union by size 