
// LeetCode Daily: 2025-09-03
// Problem: find-the-number-of-ways-to-place-people-ii  (3025)
// URL: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/

// ==================== C++ SOLUTION ====================
//Tc-O(n^2), Sc-O(1)
class Solution {
public:
    bool static cmp(vector<int>& a,vector<int>& b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),cmp);
        int ans = 0;
        for(int i=0;i<n;i++){
            int maxY = INT_MIN;
            for(int j=i+1;j<n;j++){
                if(points[i][1]>=points[j][1]){
                    if(points[j][1]>maxY){
                        ans++;
                        maxY=points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(n^2), Sc-O(1)
class Solution {
    public int numberOfPairs(int[][] points) {
        int n = points.length;
        Arrays.sort(points,(a,b)->{
            if(a[0]!=b[0]) return Integer.compare(a[0],b[0]);
            return Integer.compare(b[1],a[1]);
        });
        int ans = 0;
        for(int i=0;i<n;i++){
            int maxY = Integer.MIN_VALUE; 
            for(int j=i+1;j<n;j++){
                if(points[i][1]>=points[j][1]){
                    if(points[j][1]>maxY){
                        ans++;
                        maxY = points[j][1];
                    }
                }
            }
        }
        return ans;
    }
}