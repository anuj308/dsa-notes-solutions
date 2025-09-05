
// LeetCode Daily: 2025-09-04
// Problem: Find Closest Person     (3516)
// URL: https://leetcode.com/problems/find-closest-person/description
// Difficulty: EASY

// ==================== C++ SOLUTION ====================
//Tc-O(1), Sc-O(1)
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xDis = abs(z - x);
        int yDis = abs(z - y);
        if(xDis==yDis) return 0;
        if(xDis<yDis) return 1;
        return 2;
    }
};

//  ==================== PYTHON SOLUTION ====================
// # Tc-O(1), Sc-O(1)

        
        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(1), Sc-O(1)
class Solution {
    public int findClosest(int x, int y, int z) {
        int xDis = Math.abs(z - x);
        int yDis = Math.abs(z - y);
        if(xDis==yDis) return 0;
        if(xDis<yDis) return 1;
        return 2;
    }
}