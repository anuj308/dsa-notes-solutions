
// LeetCode Daily: 2025-09-11
// Problem: sort-vowels-in-a-string   (2785)
// URL: https://leetcode.com/problems/sort-vowels-in-a-string/description/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(n)
class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char> vowels;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vowels.push_back(s[i]);
            }
        }
        sort(vowels.begin(),vowels.end());
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i]=vowels[c];
                c++;
            }
        }
        return s;
    }
};
/* ==================== PYTHON SOLUTION ====================
# Tc-O(N), Sc-O(n)

        
*/

/* ==================== JAVA SOLUTION ====================
# Tc-O(N), Sc-O(n)
class Solution {
    public String sortVowels(String s) {
        int n = s.length();
        char[] sc = s.toCharArray();
        ArrayList<Character> vowels = new ArrayList<>();
        for(int i=0;i<n;i++){
            char curr = s.charAt(i);
            if(curr=='a' || curr=='e' || curr=='i' || curr=='o' || curr=='u' || curr=='A' || curr=='E' || curr=='I' || curr=='O' || curr=='U'){
                vowels.add(curr);
            }
        }
        Collections.sort(vowels);
        int c = 0;
        for(int i=0;i<n;i++){
            char curr = s.charAt(i);
            if(curr=='a' || curr=='e' || curr=='i' || curr=='o' || curr=='u' || curr=='A' || curr=='E' || curr=='I' || curr=='O' || curr=='U'){
                sc[i]=vowels.get(c);
                c++;
            }
        }
        String ans = new String(sc);
        return ans;
    }
}
*/