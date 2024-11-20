// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces


class Solution {
  public:
    void dfs(int node,vector<int> adjLs[], int vis[]){
        vis[node] = 1; 
        for(auto it : adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
        
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int ans =0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans++;
                dfs(i,adjLs,vis);
            }
        }
        return ans;
    }
};