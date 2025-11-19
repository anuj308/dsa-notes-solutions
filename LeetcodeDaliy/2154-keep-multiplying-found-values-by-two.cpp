
// LeetCode Daily: 2025-11-19
// Problem: 2154. Keep Multiplying Found Values by Two
// URL: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(1)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> mpp;
        for(auto it : nums) mpp[it]++;
        while(true){
            if(mpp.find(original)!=mpp.end()){
                original*=2;
            }else break;
        }
        return original;
    }
};
/* ==================== PYTHON SOLUTION ====================
*/

/* ==================== JAVA SOLUTION ====================
*/