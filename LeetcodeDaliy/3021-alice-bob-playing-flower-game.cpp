
// LeetCode Daily: 2025-08-28
// Problem: alice and bob playing flower game    (3021)
// URL: https://leetcode.com/problems/alice-and-bob-playing-flower-game/
// Difficulty: Medium
// respect this discussion:- https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/comments/3141621/
// ==================== C++ SOLUTION ====================
//Tc-O(1), Sc-O(1)
class Solution {
public:
    long long flowerGame(int n, int m) {
        // odd then alice wins so, odd = (even + odd) or (odd + even)
        long long ans = 0;
        long long evenX = n/2;
        long long oddX = n/2;
        if(n%2!=0) oddX++;
        long long evenY = m/2;
        long long oddY = m/2;
        if(m%2!=0) oddY++;
        ans+=(evenX*oddY);
        ans+=(evenY*oddX);
        return ans;
    }
};

//  ==================== PYTHON SOLUTION ====================
// # Tc-O(1), Sc-O(1)
class Solution(object):
    def flowerGame(self, n, m):
        """
        :type n: int
        :type m: int
        :rtype: int
        """
        ans = 0
        evenX = n/2
        oddX = n - evenX
        evenY = m/2
        oddY = m - evenY
        ans+=oddX*evenY
        ans+=oddY*evenX
        return ans
        
        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(1), Sc-O(1)
class Solution {
    public long flowerGame(int n, int m) {
        long evenX = n/2;
        long oddX = n - evenX;
        long evenY = m/2;
        long oddY = m - evenY;
        return evenX*oddY + evenY*oddX;
    }
}

