// https://leetcode.com/problems/detect-cycles-in-2d-grid/
class Solution {
public:
    bool dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,int pr,int pc){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        char val = grid[row][col];

        int tomove[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        for(auto it : tomove){
            int nrow = row + it[0];
            int ncol = col + it[1];

            if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]!= val ){
                continue;
            }

            if(vis[nrow][ncol] == 1 && (nrow!=pr || ncol!=pc)){
                return true;
            }
            if(vis[nrow][ncol] == 0 && dfs(nrow,ncol,grid,vis,row,col)){
                return true;
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]){
                    if(dfs(i,j,grid,vis,-1,-1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};