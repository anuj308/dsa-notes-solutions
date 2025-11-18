
// LeetCode Daily: 2025-10-18
// Problem: 717. 1-bit and 2-bit Characters
// URL: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Difficulty: easy

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        for(int i=0;i<n;){
            if(i==n-1) return true;
            if(bits[i]==1 && bits[i+1]==1) i+=2;
            else if(bits[i]==1 && bits[i+1]==0) i+=2;
            else i++;
        }
        return false;
    }
};
//  ==================== PYTHON SOLUTION ====================
        
        

// /* ==================== JAVA SOLUTION ====================