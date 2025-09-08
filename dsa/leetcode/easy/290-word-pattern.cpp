
// Problem: Word Pattern (290)
// URL: https://leetcode.com/problems/word-pattern/description/
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
//Tc-O(n*log n), Sc-O(n)

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.length();
        vector<string> ss;
        string temp = "";
        for(auto str : s){  // n
            if(str==' '){
                ss.push_back(temp);
                temp = "";
            }
            else temp+=str;
        }
        ss.push_back(temp);
        int ns = ss.size();
        if(ns!=n) return false;
        unordered_map<char,string> mpp;
        unordered_map<string,char> mww;
        for(int j=0;j<n;j++){
            int p = pattern[j];
            string word = ss[j];
            if(mpp.find(p)==mpp.end() && mww.find(word)==mww.end()){
                mww[word]=p;
                mpp[p]=word;
            }else if(mpp[p]!=word || mww[word]!=p) break;
            if(j==(n-1)) return true;
        }
        return false;
    }
};