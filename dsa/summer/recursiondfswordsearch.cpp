// https://leetcode.com/problems/word-search/


bool dfs(int ind,int i,int j,vector<vector<char>>& board,string& word,vector<vector<int>>& vis){
    if(ind==word.length()) return true;
    if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j]==1 || word[ind]!=board[i][j]) return false;
    vis[i][j]=1;
    bool ans = dfs(ind+1,i+1,j,board,word,vis) || dfs(ind+1,i-1,j,board,word,vis) || dfs(ind+1,i,j+1,board,word,vis) || dfs(ind+1,i,j-1,board,word,vis);
    vis[i][j]=0;
    return ans;
}
bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    int nw = word.length();
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]!=word[0]) continue;
            if(dfs(0,i,j,board,word,vis)) return true;
        }
    }

    return false;
}