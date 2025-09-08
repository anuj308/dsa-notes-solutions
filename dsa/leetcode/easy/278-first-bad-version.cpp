
// Problem: First Bad Version (278)
// URL: https://leetcode.com/problems/first-bad-version
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
//Tc-O(log n), Sc-O(1)
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = 0;
        int low = 1;
        int high = n;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
//  ==================== PYTHON SOLUTION ====================

        

// /* ==================== JAVA SOLUTION ====================
/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int ans = 0;
        int low = 1;
        int high = n;
        while(high>=low){
            int mid = low + (high-low)/2;
            if(isBadVersion(mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
}














//  brute force, Tc-O(n), C++
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int ans = 0;
        for(int i=n;i>=1;i--){
            if(isBadVersion(i)) ans = i;
            else break;
        }

        return ans;
    }
};