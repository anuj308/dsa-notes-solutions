
// LeetCode Daily: 2025-11-21
// Problem: 1930. Unique Length-3 Palindromic Subsequences
// URL: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n^2), Sc-O(n)
 int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<char,int> mpp;
        vector<int> u;
        for(int i=0;i<n;i++){ // o(n)
            mpp[s[i]]++;
            u.push_back(mpp.size());
        }
        int ans = 0;
        for(auto i : mpp){ 
            if(i.second>=2){ // o(n/2)
                char c = i.first;
                int left = 0;
                int right = n-1;
                while(s[left]!=c){
                    left++;
                }
                while(s[right]!=c){
                    right--;
                }
                unordered_map<char,int> um;
                for(int t=left+1;t<=right-1;t++) um[s[t]]++; // O(n)
                ans+=um.size();
            }
        }
        return ans;
    }

//Tc-O(n^3), Sc-O(1) -- time limit exceeded

 int countPalindromicSubsequence(string s) {
        int n = s.length();
        unordered_map<string,int> mpp;
        for(int i=0;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int p=j+1;p<=n-1;p++){
                    if(s[i]==s[p]){
                        string a = "";
                        a+=s[i];
                        a+=s[j];
                        a+=s[p];
                        mpp[a]++;
                    }
                }
            }
        }
        return mpp.size();
    }
/* ==================== PYTHON SOLUTION ====================

*/

/* ==================== JAVA SOLUTION ====================

*/