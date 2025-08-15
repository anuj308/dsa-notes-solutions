
// LeetCode Daily: 2025-08-15
// Problem: Power of Four (342)
// URL: https://leetcode.com/problems/power-of-four/
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
// TC: O(log n), SC: O(1)
bool isPowerOfFour(int n) {
    long long v = 1;
    while(v <= n) {
        if(v == n) return true;
        v *= 4;
    }
    return false;
}

// Alternative C++ O(1) bit manipulation:
// return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;

// power of four is allways positive
// (n & (n-1)) == 0 this check is n power of 2. - because 2 power number will always be 100.. so 
// (n & 0x55555555) != 0 this check is n bit number(2 power) is in even or not.
//  as power of four have there single bit in even positions only.
//  0x55555555 - 01010101010101010101010101010101 - single bit in even positons

/* ==================== PYTHON SOLUTION ====================
# TC: O(log n), SC: O(1)
def isPowerOfFour(self, n):
        """
        :type n: int
        :rtype: bool
        """
        v = 1
        while(v<=n):
            if v == n:
                return True
            v*=4
        return False

# Alternative Python one-liner:
# return n > 0 and (n & (n-1)) == 0 and (n & 0x55555555) != 0
*/

/* ==================== JAVA SOLUTION ====================
// TC: O(log n), SC: O(1)
public boolean isPowerOfFour(int n) {
    long v = 1;
    while (v <= n) {
        if (v == n) return true;
        v *= 4;
    }
    return false;
}

// Alternative Java bit manipulation:
// return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
*/