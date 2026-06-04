
// LeetCode Daily: 2026-06-04
// Problem: 3751. Total Waviness of Numbers in Range I
// URL: https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
// Difficulty: EASY
// ==================== C++ SOLUTION ====================
//Tc-O(n), Sc-O(1)
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int i=num1;i<=num2;i++){
            if(i<100) continue;
            int n = i;
            int last2 = n%10;
            int last1 = -1;
            n/=10;
            while(n>0){
                int temp = n%10;
                if(last1!=-1){
                    if(last1>temp && last1>last2) ans++;
                    if(last1<temp && last1<last2) ans++;
                    last2 = last1;  
                    last1 = temp;
                }else{
                    last1 = temp;
                }
                n/=10;
            }
        }
        return ans;
    }
};

//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================

