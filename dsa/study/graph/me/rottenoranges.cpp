// https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>> &vis,
     int &fresh,int &freshOranges){
        int n = grid.size();
        int m = grid[0].size();
            for(int x = -1; x<=1; x++){
                int nrow = row + x;
                int ncol = col + x;
                if(nrow>=0 && nrow<n && col>=0 && col<m &&
                !vis[nrow][col] && grid[nrow][col] == 1){
                    vis[nrow][col] = 1;
                    fresh++;
                    freshOranges--;
                    grid[nrow][col] = 2; // for next iteration this will also we rotten
                }
                if(row>=0 && row<n && ncol>=0 && ncol<m &&
                !vis[row][ncol] && grid[row][ncol] == 1){
                    vis[row][ncol] = 1;
                    fresh++;
                    freshOranges--;
                    grid[row][ncol] = 2;
                }
            }
        // }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int freshOranges = 0;
        // function to find fresh oranges
         for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 1){
                      freshOranges++;
                    }
                }
            }
        //if freshOranges are 0 then return 0 as there are no oranges
        if(freshOranges == 0) return 0;
        
        int ans = 0;
        int fresh = freshOranges;
        while(fresh!=0){
            fresh = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(!vis[i][j] && grid[i][j] == 2){
                        vis[i][j]=1;
                        bfs(i,j,grid,vis,fresh,freshOranges);
                    }
                }
            }
            //reset vis to 0
             for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                   vis[i][j]=0;
                }
            }
            if(fresh>0){
                ans++;
            }
        }
        // for case where we can't rot oranges - we have fresh oranges but not 
        // in up,down,side
        if(freshOranges!=0){
            return -1;
        }
        
        return ans;
    }
};

//  as it was beating only 26% approx so more optimise code is below with the help of chatgpt

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;

        queue<pair<int,int>> q;

        // function to find fresh oranges
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    freshOranges++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        //if freshOranges are 0 then return 0 as there are no oranges
        if(freshOranges == 0) return 0;
        
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            int fresh = 0;

            for(int k = 0; k<size; k++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(int x=-1; x<=1; x++){
                    int nrow = row + x;
                    int ncol = col + x;
                    if(nrow>=0 && nrow<n && col>=0 && col<m &&
                   grid[nrow][col] == 1){
                        fresh++;
                        freshOranges--;
                        grid[nrow][col] = 2; // for next iteration this will also we rotten
                        q.push({nrow,col}); // pushing rotten organge for next iteration 
                        // or after a minute
                }
                if(row>=0 && row<n && ncol>=0 && ncol<m &&
                     grid[row][ncol] == 1){
                        fresh++;
                        freshOranges--;
                        grid[row][ncol] = 2;
                        q.push({row,ncol});
                }
                }
            }
            if(fresh>0){
                ans++;
            }
        }
        // for case where we can't rot oranges - we have fresh oranges but not 
        // in up,down,side
        if(freshOranges!=0){
            return -1;
        }
        
        return ans;
    }
};
// https://www.geeksforgeeks.org/problems/rotten-oranges2536/1