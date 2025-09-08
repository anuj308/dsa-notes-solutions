
// Problem: Add digit (258)
// URL: https://leetcode.com/problems/add-digits
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
//Tc-O(logn), Sc-O(1)
class Solution {
    public int addDigits(int num) {
        while(num>=0){ // log n but run every few times
            int n = num;
            int val = 0;
            while(n>0){ // log n
                val += n%10;
                n/=10;
            }
            if(val<10) return val;
            num = val;
        }
        return -1;
    }
}
//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================
class Solution {
    public int addDigits(int num) {
        while(num>=0){
            int n = num;
            int val = 0;
            while(n>0){
                val += n%10;
                n/=10;
            }
            if(val<10) return val;
            num = val;
        }
        return -1;
    }
}