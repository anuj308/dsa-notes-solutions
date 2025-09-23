
// LeetCode Daily: 2025-09-23
// Problem: 165. Compare Version Numbers
// URL: https://leetcode.com/problems/compare-version-numbers
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(n) Sc-O(n)
class Solution {
public:
    int wcompareVersion(string version1, string version2) {
        vector<long long> v1;
        vector<long long> v2;
        long long v = 0;
        for(char i : version1){
            if(i=='.'){
                v1.push_back(v);
                v=0;
            }else v= v*10+i-'0';
        }
        v1.push_back(v);
        v=0;
        for(char i : version2){
            if(i=='.'){
                v2.push_back(v);
                v=0;
            }else v= v*10+(i-'0');
        }
        v2.push_back(v);
        int n1 = v1.size();
        int n2 = v2.size();
        while(v1.size()<n2) v1.push_back(0);
        while(v2.size()<n1) v2.push_back(0);
        n1=v1.size();
        for(int i=0;i<n1;i++){
            if(v1[i]<v2[i]) return -1;
            if(v1[i]>v2[i]) return 1;
        }
        return 0;
    }
};
//  ==================== PYTHON SOLUTION ====================
// # Tc-O(1), Sc-O(1)

        
        

// /* ==================== JAVA SOLUTION ====================