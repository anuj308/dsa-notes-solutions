
// LeetCode Daily: 2026-05-02
// Problem: 88. Rotated Digits
// URL: https://leetcode.com/problems/rotated-digits/description
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n), Sc-O(1)

class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int num = i;
            int newnum =0;
            int z = 1;
            bool pos = true;
            while(num>0){
                int t = num%10;
                if(t==2) t=5;
                else if(t==5) t=2;
                else if(t==6) t=9;
                else if(t==9) t=6;
                else if(t==3 || t==4 || t==7){
                    pos = false;
                    break;
                }
                newnum+= t*z;
                z*=10;
                num/=10;
            }
            if(pos && i!=newnum) ans++;
        }

        return ans;
    }
};
/* ==================== PYTHON SOLUTION ====================
        
*/

/* ==================== JAVA SOLUTION ====================

*/