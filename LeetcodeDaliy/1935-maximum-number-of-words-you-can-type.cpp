
// LeetCode Daily: 2025-09-15
// Problem: 1935. Maximum Number of Words You Can Type
// URL: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> broken;
        for(auto &b : brokenLetters){
            broken[b]=1;
        }
        int ans = 0;
        bool include = true;
        for(auto &c : text){
            if(c==' '){
                if(include) ans++;
                include = true;
            }
            if(include && broken.find(c)!=broken.end()){
                include = false;
            }
        }
        if(include) ans++;
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================
# Tc-O(N), Sc-O(1)


/* ==================== JAVA SOLUTION ====================
# Tc-O(n), Sc-O(1)
class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        Set<Character> broken = new HashSet<>();
        for(char b : brokenLetters.toCharArray()){
            broken.add(b);
        }
        int ans = 0;
        boolean include = true;
        for(char c : text.toCharArray()){
            if(c==' '){
                if(include) ans++;
                include = true;
            }
            if(include && broken.contains(c)){
                include = false;
            }
        }
        if(include) ans++;
        return ans;
    }
}

*/