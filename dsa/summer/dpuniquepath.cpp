


// https://leetcode.com/problems/unique-paths/description/
// --------- recursion
// tc - O(2^(n*m)) , sc - O(1)
int findAns(int i,int j){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    int up = findAns(i-1,j);
    int left = findAns(i,j-1);

    return up+left;
}
int uniquePaths(int m, int n) {
   return findAns(m-1,n-1);
}

// --------- memorise
// tc - O((n*m)) , sc - O(1)
int findAns(int i,int j,vector<vector<int>>& mat){
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(mat[i][j]!=-1) return mat[i][j];

    int up = findAns(i-1,j,mat);
    int left = findAns(i,j-1,mat);

    return mat[i][j] = up+left;
}
int uniquePaths(int m, int n) {
    vector<vector<int>> mat(m,vector<int>(n,-1));
    
   return findAns(m-1,n-1,mat);
}


// ------------- tabulation
// tc - O(n*m) , sc- O(n*m)

int uniquePaths(int m, int n) {
    vector<vector<int>> mat(m,vector<int>(n,0));
    for(int i=0;i<m;i++) mat[i][0]=1;
    for(int i=0;i<n;i++) mat[0][i]=1;

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            mat[i][j]=mat[i-1][j] + mat[i][j-1];
        }
    }


    return mat[m-1][n-1];
}

// ------------- space optimise
// tc - O(n*m) , sc- O(n*m)

int uniquePaths(int m, int n) {
    vector<int> prev(n,1);

    for(int i=1;i<m;i++){
        vector<int> curr(n);
        curr[0]=1;
        for(int j=1;j<n;j++){
            curr[j]=curr[j-1] + prev[j];
        }
        prev = curr;
    }


    return prev[n-1];
}