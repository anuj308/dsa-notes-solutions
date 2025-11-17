
// LeetCode Daily: 2025-11-17
// Problem: 1437. Check If All 1's Are at Least Length K Places Away
// URL: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(n), Sc-O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int last = -1;
        for(int i=0;i<n;i++){
            if(last!=-1 && nums[i]==1 && i-last-1<k) return false;
            if(nums[i]==1) last =i;
        }


        return true;
    }
};
/* ==================== PYTHON SOLUTION ====================


/* ==================== JAVA SOLUTION ====================

*/