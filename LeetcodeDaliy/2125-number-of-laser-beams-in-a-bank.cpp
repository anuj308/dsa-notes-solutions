
// LeetCode Daily: 2025-10-27
// Problem: 2125. Number of Laser Beams in a Bank
// URL: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================
//Tc-O(log N^2), Sc-O(1)
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int m = bank[0].size();
        int c = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int cCount = 0;
            for(int j=0;j<m;j++){
                if(bank[i][j]=='1') cCount++;
            }
            if(c!=0){
                ans+=c*cCount;
            }
            if(cCount!=0) c  = cCount;
        }
        return ans;
    }
};
/* ==================== PYTHON SOLUTION ====================
*/


//  ==================== JAVA SOLUTION ====================
// Tc-O(log N), Sc-O(1)
class Solution {
    public int numberOfBeams(String[] bank) {
        int n = bank.length;
        int m = bank[0].length();
        int c = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            int cCount = 0;
            for(int j=0;j<m;j++){
                if(bank[i].charAt(j)=='1') cCount++;
            }
            if(c!=0){
                ans+=c*cCount;
            }
            if(cCount!=0) c  = cCount;
        }
        return ans;
    }
}