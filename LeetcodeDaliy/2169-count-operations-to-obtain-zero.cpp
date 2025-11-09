
// LeetCode Daily: 2025-11-09
// Problem: 2169. Count Operations to Obtain Zero
// URL: https://leetcode.com/problems/count-operations-to-obtain-zero
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(n), Sc-O(n)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1>0 && num2>0){
            if(num1>=num2) num1-=num2;
            else num2-=num1;
            ans++;
        }
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================


/* ==================== JAVA SOLUTION ====================
