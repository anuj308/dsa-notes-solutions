// https://www.geeksforgeeks.org/problems/flood-fill-algorithm1856/1

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
        int sr, int sc,int newColor) {
        int n = image.size();
        int m = image[0].size();
        vector <vector<int>> vis(n, vector<int>(m,0));
        int oldColor = image[sr][sc]; 
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int x = -1; x<=1; x++){
                int nrow = row + x;
                int ncol = col + x;
                if(nrow>=0 && nrow<n && col>=0 && col<m &&
                !vis[nrow][col] && image[nrow][col] == oldColor){
                    vis[nrow][col] = 1;
                    image[nrow][col] = newColor;
                    q.push({nrow,col});
                }
                if(row>=0 && row<n && ncol>=0 && ncol<m &&
                !vis[row][ncol] && image[row][ncol] == oldColor){
                    vis[row][ncol] = 1;
                    image[row][ncol] = newColor;
                    q.push({row,ncol});
                }
            }
        }
        return image;
    }
};
// https://leetcode.com/problems/flood-fill/submissions/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int oldColor = image[sr][sc];

        if(oldColor == color) return image;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int x = -1; x<=1; x++){
                int nrow = row + x;
                int ncol = col + x;
                if(nrow>=0 && nrow<n && col>=0 && col<m &&
                 !vis[nrow][col] && image[nrow][col] == oldColor){
                    vis[nrow][col]=1;
                    image[nrow][col] = color;
                    q.push({nrow,col});
                }
                if(row>=0 && row<n && ncol>=0 && ncol<m &&
                 !vis[row][ncol] && image[row][ncol] == oldColor){
                    vis[row][ncol]=1;
                    image[row][ncol] = color;
                    q.push({row,ncol});
                }
            }
        }
        return image;
    }
};