
// LeetCode Daily: 2026-02-07
// Problem: 1653. Minimum Deletions to Make String Balanced
// URL: https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int b = -1;
        int a = -1;
        int n = s.length();
        while(left<n && right<n){
            if(b==-1){
                if(s[left]=='b'){
                    b = left;
                    if(right==0) right=left+1;
                }else{
                    left++;
                    // right++;
                }
            }else if(a==-1){
                if(right>left && s[right]=='a'){
                    // a = right;
                    // s[b]=0;
                    // s[a]=0;
                    ans++;
                    b=-1;
                    a=-1;
                    left++;
                    right++;
                }else{
                    right++;
                }
            } // think a lot to modify from original idea as it not needed
        }
       
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================
*/
//  ==================== JAVA SOLUTION ====================
