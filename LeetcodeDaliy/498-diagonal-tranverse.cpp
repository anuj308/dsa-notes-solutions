
// LeetCode Daily: 2025-08-25
// Problem: diagonal Tranverse     (498)
// URL: https://leetcode.com/problems/diagonal-traverse/description/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O((n*m)/2), Sc-O(1)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int m = mat[0].size();
        if(m==1) {
            for(int i=0;i<n;i++){
                ans.push_back(mat[i][0]);
            }
            return ans;
        }
        if(n==1){
            for(int i=0;i<m;i++){
                ans.push_back(mat[0][i]);
            }
            return ans;
        }
        int row = -1;
        int col = 0;
        for(int i=0;i<=(n*m)/2;i++){
            cout << i << endl;
            if(i%2==0){
                if(row<n-1) row++;
                else col++;
                while(row>=0 && row<n && col>=0 && col<m){
                    ans.push_back(mat[row][col]);
                    row--;
                    col++;
                }
                row++;
                col--;
            }
            else{
                if(col<m-1) col++;
                else row++;
                while(row>=0 && row<n && col>=0 && col<m){
                    ans.push_back(mat[row][col]);
                    row++;
                    col--;
                }
                row--;
                col++;
            }
        }
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================
# Tc-O((n*m)/2), Sc-O(1)
class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        n=len(mat)
        m=len(mat[0])
        ans= []
        if(m==1):
            for i in range(0,n):
                ans.append(mat[i][0])
            return ans
        if(n==1):
            for i in range(0,m):
                ans.append(mat[0][i])
            return ans
        row=-1
        col=0
        for i in range(0,((m*n)/2)+1):
            if(i%2==0):
                if(row<n-1):
                    row+=1
                else:
                    col+=1
                while(row>=0 and row<n and col>=0 and col<m):
                    ans.append(mat[row][col])
                    row-=1
                    col+=1
                row+=1
                col-=1
            else:
                if(col<m-1):
                    col+=1
                else:
                    row+=1
                while(row>=0 and row<n and col>=0 and col<m):
                    ans.append(mat[row][col])
                    row+=1
                    col-=1
                row-=1
                col+=1

        return ans
        
*/

/* ==================== JAVA SOLUTION ====================
# Tc-O((n*m)/2), Sc-O(1)
class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[] ans = new int[n*m];
        int row = -1;
        int col = 0;
        if(n==1){
            for(int i=0;i<m;i++){
                ans[i]=mat[0][i];
            }
            return ans;
        }
        if(m==1){
            for(int i=0;i<n;i++){
                ans[i]=mat[i][0];
            }
            return ans;
        }
        int idx = 0;
        for(int i=0;i<=(n*m)/2;i++){
            if(i%2==0){
                if(row<n-1) row++;
                else col++;
                while(row>=0 && row<n && col>=0 && col<m){
                    ans[idx]=mat[row][col];
                    idx++;
                    row--;
                    col++;
                }
                row++;
                col--;
            }else{
                if(col<m-1) col++;
                else row++;
                while(row>=0 && row<n && col>=0 && col<m){
                    ans[idx]=mat[row][col];
                    idx++;
                    row++;
                    col--;
                }
                row--;
                col++;
            }
        }

        return ans;
    }
}

*/