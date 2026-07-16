// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

void dfs(int i,int j,int& n,int& m,string ans,vector<vector<int>>& maze,vector<vector<int>>&vis,vector<string>& path){
    if(i==n-1 && j==m-1){
        path.push_back(ans);
        return;
    } 
    if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==1 || maze[i][j]==0) return;
    vis[i][j]=1;
    dfs(i+1,j,n,m,ans+"D",maze,vis,path);
    dfs(i-1,j,n,m,ans+"U",maze,vis,path);
    dfs(i,j+1,n,m,ans+"R",maze,vis,path);
    dfs(i,j-1,n,m,ans+"L",maze,vis,path);
    vis[i][j]=0;
}
vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    int m = maze[0].size();
    
    vector<string> path;
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    string ans = "";
    if(maze[0][0]==1) dfs(0,0,n,m,ans,maze,vis,path);

    sort(path.begin(),path.end());
    return path;
}