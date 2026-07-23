
// https://leetcode.com/problems/rotting-oranges/

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    int freshOranges = 0;

    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) freshOranges++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    int time = 0;
    if(freshOranges==0) return time;
    while(!q.empty()){
        int nq = q.size();
        for(int i=0;i<nq;i++){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto it : dir){
                int nr = it.first + r;
                int nc = it.second + c;

                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    freshOranges--;
                }
            }

        }
        time++;
        if(freshOranges==0) return time;
    }

    return -1;
}