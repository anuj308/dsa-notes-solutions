

// LeetCode Daily: 2025-10-13
// Problem: 3228. maximum-number-of-operations-to-move-ones-to-the-end
// URL: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n) Sc-O(1)
class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(); 
        int c = 0;
        int one = 0;
        for(int i=0;i<n;){
            if(s[i]=='1'){
                one++;
                i++;
            }
            else{
                int j = i;
                while(s[j]=='0'){
                    j++;
                }
                i=j;
                c+=one;
            }
        }

        return c;
    }
};
//  ==================== PYTHON SOLUTION ====================

        
        

// /* ==================== JAVA SOLUTION ====================
