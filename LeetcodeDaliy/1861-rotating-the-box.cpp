
// LeetCode Daily: 2026-05-06
// Problem: 1861. Rotating the Box
// URL: https://leetcode.com/problems/rotating-the-box/description/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n^2), Sc-O(n)
vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
    int n = boxGrid.size();
    int m = boxGrid[0].size();
    vector<vector<char>> ans(m,vector<char>(n,'.'));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=boxGrid[n-1-j][i];
        }
    }
    for(int j=0;j<n;j++){ // col
        queue<int> spaceRow;
        for(int i=m-1;i>=0;i--){ // row
            if(ans[i][j] == '#' && !spaceRow.empty()){
                int srow = spaceRow.front();
                spaceRow.pop();
                ans[srow][j] = '#';
                ans[i][j] = '.';
                spaceRow.push(i);
            }
            else if(ans[i][j] == '*'){
                spaceRow = queue<int>(); // clear the queue
            }
            else if(ans[i][j] == '.'){
                spaceRow.push(i);
            }
        }
    }

    return ans;
}

/* ==================== PYTHON SOLUTION ====================

*/

/* ==================== JAVA SOLUTION ====================

*/