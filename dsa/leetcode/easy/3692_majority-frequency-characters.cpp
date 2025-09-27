
// Problem: Add digit (258)
// URL: https://leetcode.com/problems/add-digits
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
//Tc-O(n^2), Sc-O(1)
class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> mpp;
        for(auto it : s){
            mpp[it]++;
        }
        int highest = 0;
        for(auto it : mpp) highest=max(highest,it.second);
        string ans = "";
        int groupCount = 0;
        int freq = 0;
        for(int i=highest;i>0;i--){
            int g = 0;
            string a = "";
            int f = 0;
            for(auto it : mpp){
                if(it.second==i){
                    a+=it.first;
                    g++;
                    f+=it.second;
                }
            }
            if(groupCount==g && f>freq){
                ans = a;
                groupCount = g;
                freq = f;
            }
            if(g>groupCount){
                ans = a;
                groupCount = g;
                freq = f;
            }
        }

        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================
