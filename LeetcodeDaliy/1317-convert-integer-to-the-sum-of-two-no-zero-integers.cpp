
// LeetCode Daily: 2025-09-08
// Problem: convert-integer-to-the-sum-of-two-no-zero-integer   (1317)
// URL: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integer
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
bool check(int a,int b){
    while(a>0){
        if(a%10==0) return true;
        a/=10;
    }
    while(b>0){
        if(b%10==0) return true;
        b/=10;
    }

    return false;
}
    vector<int> getNoZeroIntegers(int n) {
        int a = n-1;
        int b = 1;
        while(a>0 && b>0 && check(a,b)){
            a--;
            b++;
        }
        return {a,b};
    }
};

/* ==================== PYTHON SOLUTION ====================
# Tc-O(N), Sc-O(1)


/* ==================== JAVA SOLUTION ====================
# Tc-O(log n), Sc-O(1)
class Solution {
    boolean check(int a,int b){      
        while(a>0){
            if(a%10==0) return true;
            a/=10;
        }
        while(b>0){
            if(b%10==0) return true;
            b/=10;
        }
        return false;
    }
    public int[] getNoZeroIntegers(int n) {
        int a = n-1;
        int b = 1;
        while(a>0 && b>0 && check(a,b)){
            a--;
            b++;
        }
        int[] ans = {a,b};
        return ans;
    }
}

*/