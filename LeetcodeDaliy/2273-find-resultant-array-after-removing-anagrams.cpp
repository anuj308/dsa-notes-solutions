
// LeetCode Daily: 2025-10-13
// Problem: 2273. Find Resultant Array After Removing Anagrams
// URL: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams
// Difficulty: easy

// ==================== C++ SOLUTION ====================
//Tc-O(n^2) Sc-O(n)
class Solution {
public:
    bool anagram(unordered_map<int,unordered_map<char,int>>& mpp,int i,int j){
        if(mpp[i].size()!=mpp[j].size()) return false;        
        for(auto m : mpp[i]){
            int f = m.first;
            if(mpp[j].find(f)==mpp[j].end()) return false;
            else if(mpp[j][f]!=mpp[i][f]) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n = words.size();
        vector<bool> vis(n,false);
        unordered_map<int,unordered_map<char,int>> mpp;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(auto w : words[i]) freq[w]++;
            mpp[i]=freq;
        }
        int i = 0;
        while(i<n){
            int j = i+1;
            if(!vis[i]){
                while(j<n && anagram(mpp,i,j)){
                    vis[j]=true;
                    j++;
                }
                ans.push_back(words[i]);
            }
            i++;
        }
        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================
// # Tc-O(1), Sc-O(1)

        
        

// /* ==================== JAVA SOLUTION ====================