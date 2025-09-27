
// LeetCode Daily: 2025-09-27
// Problem: 812. Largest Triangle Area
// URL: https://leetcode.com/problems/largest-triangle-area/description/
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(n^3), Sc-O(1)

#include <algorithm>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
       double ans = 0.0;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int z=0;z<n;z++){
                    if(i!=j && j!=z && z!=i){
                        int x1 = points[i][0];
                        int x2 = points[j][0];
                        int x3 = points[z][0];
                        int y1 = points[i][1];
                        int y2 = points[j][1];
                        int y3 = points[z][1];
                        double  area = abs(0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2)));
                        ans=max(ans,area);
                    } 
                }
            }
        }

       return ans;
    }
};