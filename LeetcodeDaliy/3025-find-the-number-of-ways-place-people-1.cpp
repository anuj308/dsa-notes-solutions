
// LeetCode Daily: 2025-09-02
// Problem: find-the-number-of-ways-to-place-people-i  (3025)
// URL: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/

// ==================== C++ SOLUTION ====================
//Tc-O(n^3), Sc-O(1)
class Solution {
public:
    bool check(vector<vector<int>>& points,int a,int b){
        int n = points.size();
        for(int i=0;i<n;i++){
            if(i==a || i==b) continue;
            if((points[a][0]<=points[i][0]) && (points[i][0]<=points[b][0]) && (points[a][1]>=points[i][1]) && (points[i][1]>=points[b][1])) {
                return false;
            }
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && points[i][0]<=points[j][0] && points[i][1]>=points[j][1]){
                    if(check(points,i,j)) ans++;
                }
            }
        }
        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(n^3), Sc-O(1)
class Solution {
    public boolean check(int[][] points,int a,int b){
        int n = points.length;
        for(int i=0;i<n;i++){
            if(i==a || i==b) continue;
            if((points[a][0]<=points[i][0]) && (points[i][0]<=points[b][0]) && (points[a][1]>=points[i][1]) && (points[i][1]>=points[b][1])) {
                return false;
            }
        }
        return true;
    }
    public int numberOfPairs(int[][] points) {
        int n = points.length;
        Arrays.sort(points,(a,b)->{
            if(a[0]!=b[0]) return Integer.compare(a[0],b[0]);
            return Integer.compare(a[1],b[1]);
        });
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && points[i][0]<=points[j][0] && points[i][1]>=points[j][1]){
                    if(check(points,i,j)) ans++;
                }
            }
        }

        return ans;
    }
}

