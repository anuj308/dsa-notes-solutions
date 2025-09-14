
// LeetCode Daily: 2025-09-14
// Problem: 966. Vowel Spellchecker
// URL: https://leetcode.com/problems/vowel-spellchecker/description/
// Difficulty: MEDIUM

// ==================== C++ SOLUTION ====================
//Tc-O(nlogn), Sc-O(3n)
class Solution {
public:
    string replaceVowels(string str){
        int n = str.length();
        for(int z=0;z<n;z++){
            char q = str[z];
            if(q=='a' || q=='e' || q=='i' || q=='o' || q=='u'){
                str[z]='#';
            }
        }
        return str;
    }
    string toLower(string str){
        string newStr = "";
        for(auto c : str){
            newStr += tolower(c);
        }
        return newStr;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        int n = queries.size();
        int nw = wordlist.size();
        unordered_map<string,int> mpp;
        unordered_map<string,string> lowerCase;
        unordered_map<string,string> wordsL;
        for(int i=nw-1;i>=0;i--){
            mpp[wordlist[i]]++;    
            string lower = toLower(wordlist[i]);
            lowerCase[lower]=wordlist[i];
            wordsL[replaceVowels(lower)]=wordlist[i];
        }
        for(int i=0;i<n;i++){
            string querie = queries[i];
            if(mpp.find(querie)!=mpp.end()){
                ans.push_back(querie);
                continue;
            }
            string queriesLowercase = toLower(querie);
            if(lowerCase.find(queriesLowercase)!=lowerCase.end()){ // check capitalization
                ans.push_back(lowerCase[queriesLowercase]);
                continue;
            }
            string qpattern = replaceVowels(queriesLowercase);
            if(wordsL.find(qpattern)!=wordsL.end()){ // vowel check
                ans.push_back(wordsL[qpattern]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
/* ==================== PYTHON SOLUTION ====================


/* ==================== JAVA SOLUTION ====================

*/