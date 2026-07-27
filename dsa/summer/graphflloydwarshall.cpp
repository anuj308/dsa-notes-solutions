// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// tc - O(V^3)
// to get short distance from all node to all node
void floydWarshall(vector<vector<int>> &dist) {
    // Code here
    int v = dist.size();
    
    for(int via=0;via<v;via++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][via]!=1e8 && dist[via][j]!=1e8 && dist[i][via]+dist[via][j]<dist[i][j]){
                    dist[i][j]=dist[i][via]+dist[via][j];
                }
            }
        }
    }
}