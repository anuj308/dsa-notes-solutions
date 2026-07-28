// https://leetcode.com/problems/making-a-large-island/

/**
* 827. Making A Large Island
* Link : https://leetcode.com/problems/making-a-large-island/description/
* Topic : Graph
*/
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
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();

        DisjointSet dsu(n*n);

        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    int node=(i*n)+j;

                    for(int k=0;k<4;k++) {
                        int newX=i+dx[k];
                        int newY=j+dy[k];

                        if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==1) {
                            int newNode=(newX*n)+newY;
                            dsu.unionBySize(node,newNode);
                        }
                    }


                }
            }
        }

        //we will try to merge the components by make 0->1
        bool atleastOneZero=false;
        int area=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    atleastOneZero=true;
                    int node=(i*n)+j;

                    int currArea=1;
                    set<int>st;
                    for(int k=0;k<4;k++) {
                        int newX=i+dx[k];
                        int newY=j+dy[k];

                        if(newX>=0 && newX<n && newY>=0 && newY<n && grid[newX][newY]==1) {
                            int newNode=(newX*n)+newY;
                            
                            int parentOfnewNode=dsu.findUParent(newNode);
                            st.insert(parentOfnewNode);
                        }
                    }
                    for(auto it:st) {
                        currArea+=dsu.size[it];
                    }
                    area=max(area,currArea);
                }
            }
        }
        if(atleastOneZero)
            return area;
        return n*n;
    }
};


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