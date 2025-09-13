
// LeetCode Daily: 2025-09-13
// Problem: 3541. Find Most Frequent Vowel and Consonant
// URL: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> mpp;
        for(auto i : s){
            mpp[i]++;
        }
        int vowels = 0;
        int consonant = 0;
        for(auto m : mpp){
            if(m.first=='a' || m.first=='e' || m.first=='i' || m.first=='o' || m.first=='u') vowels=max(vowels,m.second);
            else consonant=max(consonant,m.second);
        }
        return vowels + consonant;
    }
};

//  ==================== PYTHON SOLUTION ====================

        
        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(N), Sc-O(1)
class Solution {
    public int maxFreqSum(String s) {
        int[] mpp = new int[26];
        int n = s.length();
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            mpp[ch-'a']++;
        }
        int vowels = 0;
        int consonant = 0;
        for(int i=0;i<26;i++){
            char ch = (char)(i+'a');
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') vowels=Math.max(vowels,mpp[i]);
            else consonant=Math.max(consonant,mpp[i]);
        }
        return vowels + consonant;
    }
}