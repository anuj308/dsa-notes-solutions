
// LeetCode Daily: 2025-10-1
// Problem: 1518. Water Bottles
// URL: https://leetcode.com/problems/water-bottles
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles>=numExchange){
            int newBottles = emptyBottles/numExchange;
            ans+= newBottles;
            emptyBottles = emptyBottles%numExchange + newBottles;
        }
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================
*/
class Solution(object):
    def numWaterBottles(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        ans = numBottles
        emptyBottles = numBottles
        while(emptyBottles>=numExchange):
            newBottles = emptyBottles/numExchange
            ans+= newBottles
            emptyBottles = emptyBottles%numExchange + newBottles
        return ans

//  ==================== JAVA SOLUTION ====================
// Tc-O(N), Sc-O(1)
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;
        while(emptyBottles>=numExchange){
            int newBottles = emptyBottles/numExchange;
            ans+= newBottles;
            emptyBottles = emptyBottles%numExchange + newBottles;
        }
        return ans;
    }
}