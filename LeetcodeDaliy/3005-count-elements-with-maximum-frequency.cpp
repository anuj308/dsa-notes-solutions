
// LeetCode Daily: 2025-09-22
// Problem: 3005. Count Elements With Maximum Frequency
// URL: https://leetcode.com/problems/count-elements-with-maximum-frequencyhttps://leetcode.com/problems/valid-sudoku
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n) Sc-O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> mpp;
        int maxFreq = 0;
        for(auto i : nums){
            mpp[i]++;
            maxFreq=max(maxFreq,mpp[i]);
        }
        for(auto it : mpp){
            if(it.second==maxFreq) ans+=it.second;
        }
        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================

        
        

// /* ==================== JAVA SOLUTION ====================
