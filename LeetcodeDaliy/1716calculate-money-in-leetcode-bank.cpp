
// LeetCode Daily: 2025-10-25
// Problem: 1716. Calculate Money in Leetcode Bank
// URL: https://leetcode.com/problems/calculate-money-in-leetcode-bank
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(n), Sc-O(1)
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int w = n/7;
        ans+=(28*w);
        if(w>1){
            for(int i=1;i<w;i++){
                ans+=(i*7);
            }
        } 
        for(int i=0;i<n%7;i++){
            ans+=(i+1+w);
        }
        return ans;
    }
};
/* ==================== PYTHON SOLUTION ====================

        
*/

/* ==================== JAVA SOLUTION ====================


*/