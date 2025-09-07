
// LeetCode Daily: 2025-09-07
// Problem: find-n-unique-integers-sum-up-to-zero   (1304)
// URL: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        if(n%2!=0) ans.push_back(0);
        for(int i=1;i<=n/2;i++){
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================
# Tc-O(N), Sc-O(1)


/* ==================== JAVA SOLUTION ====================
# Tc-O(N), Sc-O(1)
class Solution {
    public int[] sumZero(int n) {
        int[] ans = new int[n];
        int c = 0;
        for(int i=1;i<=n/2;i++){
            ans[c++]=i;
            ans[c++]=-i;
        }
        if(n%2!=0) ans[c]=0;
        return ans;
    }
}

*/