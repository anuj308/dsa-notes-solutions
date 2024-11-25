// https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find_the_number_of_islands

class Solution {
  public:
    void bfs(int row, int col, vector<vector<int>> &vis,vector<vector<char>>& grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int delrow = -1 ; delrow <=1 ; delrow++){
                for(int delcol =-1; delcol <=1; delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow >= 0 && nrow<n && ncol >= 0 && ncol < m &&
                       grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                           vis[nrow][ncol] = 1;
                           q.push({nrow,ncol});
                       }
                }
            }
            
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < m ; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    ans++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return ans;
    }
};

// in leetcode there a a change to check only horixzontal and vertically neighbour or islands

class Solution {
public:
    void bfs(int row,int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int x = -1; x<=1; x++){
                int nrow = row + x;
                int ncol = col + x;
                    if(row>=0 && row<n && ncol>=0 && ncol<m &&
                     grid[row][ncol] == '1' && !vis[row][ncol]){
                        vis[row][ncol]=1;
                        q.push({row,ncol});
                    }
                    if(nrow>=0 && nrow<n && col>=0 && col<m && 
                    grid[nrow][col] == '1' && !vis[nrow][col]){
                        vis[nrow][col]=1;
                        q.push({nrow,col});
                    }
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    ans++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return ans;
    }
};q