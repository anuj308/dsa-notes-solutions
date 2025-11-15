
// LeetCode Daily: 2025-11-14
// Problem: 2536. Increment Submatrices by One
// URL: https://leetcode.com/problems/successful-pairs-of-spells-and-potions
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================
//Tc-O(q*n^2), Sc-O(1)
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n,vector<int>(n,0));
        int q = queries.size();
        for(int i=0;i<q;i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            for(int j=r1;j<=r2;j++){
                for(int k=c1;k<=c2;k++){
                    mat[j][k]++;
                }
            }
        }

        return mat;
    }
};
/* ==================== PYTHON SOLUTION ====================


/* ==================== JAVA SOLUTION ====================

*/