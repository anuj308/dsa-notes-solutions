
// link :-https://leetcode.com/problems/vowels-game-in-a-string
// TYPE:- medium
// name :- 3227 Vowels Game in a String


// C++
class Solution {
    public boolean doesAliceWin(String s) {
        int n = s.length();
        int vowels = 0;
        for(int j=0;j<n;j++){
            char v = s.charAt(j);
            if(v=='a' || v=='e' || v=='i' || v=='o' || v=='u'){
                vowels++;
            }
        }  // Tc-O(n) sc-O(1)
        if(vowels==0) return false;
        if(vowels%2!=0) return true;
        return true;
    }
}


// java
class Solution {
    public boolean doesAliceWin(String s) {
        int n = s.length();
        int vowels = 0;
        for(int j=0;j<n;j++){
            char v = s.charAt(j);
            if(v=='a' || v=='e' || v=='i' || v=='o' || v=='u'){
                vowels++;
            }
        }  // Tc-O(n) sc-O(1)
        if(vowels==0) return false;
        if(vowels%2!=0) return true;
        return true;
    }
}