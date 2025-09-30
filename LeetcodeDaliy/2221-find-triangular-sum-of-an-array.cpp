
// LeetCode Daily: 2025-09-30
// Problem: 2221. Find Triangular Sum of an Array
// URL: https://leetcode.com/problems/find-triangular-sum-of-an-array/description
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================
//Tc-O(N^2), Sc-O(1)
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while(n!=1){
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
};

/* ==================== PYTHON SOLUTION ====================


/* ==================== JAVA SOLUTION ====================
# Tc-O(n^2), Sc-O(1)
class Solution {
    public int triangularSum(int[] nums) {
        int n = nums.length;
        while(n!=1){
            for(int i=0;i<n-1;i++){
                nums[i]=(nums[i]+nums[i+1])%10;
            }
            n--;
        }
        return nums[0];
    }
}

*/