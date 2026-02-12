
// LeetCode Daily: 2026-02-12
// Problem: 3713. Longest Balanced Substring I
// URL: https://leetcode.com/problems/longest-balanced-substring-i/description/
//Tc-O(N^2), Sc-O(26)
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mpp;
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                int last = mpp[s[j]];
                bool pos = true;
                for(auto it : mpp){
                    if(it.second!=last){
                        pos=false;
                        break;
                    }
                }
                if(pos) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};

//  ==================== PYTHON SOLUTION ====================
// # Tc-O(1), Sc-O(1)

        
        

// /* ==================== JAVA SOLUTION ====================
