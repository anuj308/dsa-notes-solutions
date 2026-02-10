
// LeetCode Daily: 2026-02-10
// Problem: 3719. Longest Balanced Subarray I
// URL: https://leetcode.com/problems/longest-balanced-subarray-i/
// Difficulty: medium

// ==================== C++ SOLUTION ====================
//Tc-O(N^2), Sc-O(2N)
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            unordered_map<int,int> mppe;
            unordered_map<int,int> mppo;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) mppe[nums[j]]++;
                else mppo[nums[j]]++;
                if(mppe.size()==mppo.size()) ans=max(ans,j-i+1);
            }
        }
        if(ans==INT_MIN) return 0;
        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================
        
        

// /* ==================== JAVA SOLUTION ====================