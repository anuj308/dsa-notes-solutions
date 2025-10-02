
// LeetCode Daily: 2025-10-02
// Problem: 3100. Water Bottles II

// URL: https://leetcode.com/problems/water-bottles-ii
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(sqrt(N)), Sc-O(1)
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrunk = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles>=numExchange){
            int newBottles = 0;
            while(emptyBottles>=numExchange){
                emptyBottles-=numExchange;
                newBottles++;
                numExchange++;
            }
            emptyBottles+=newBottles;
            bottleDrunk+=newBottles;
        }
        return bottleDrunk;
    }
};
/* ==================== PYTHON SOLUTION ====================
# Tc-O(sqrt(N)), Sc-O(1)
class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        """
        :type numBottles: int
        :type numExchange: int
        :rtype: int
        """
        bottleDrunk = numBottles
        emptyBottles = numBottles

        while(emptyBottles>=numExchange):
            newBottles = 0
            while(emptyBottles>=numExchange):
                emptyBottles-=numExchange
                newBottles+=1
                numExchange+=1
            emptyBottles+=newBottles
            bottleDrunk+=newBottles
        
        return bottleDrunk
        
        
*/

/* ==================== JAVA SOLUTION ====================
# Tc-O(sqrt(N)), Sc-O(1)
class Solution {
    public int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottleDrunk = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles>=numExchange){
            int newBottles = 0;
            while(emptyBottles>=numExchange){
                emptyBottles-=numExchange;
                newBottles++;
                numExchange++;
            }
            emptyBottles+=newBottles;
            bottleDrunk+=newBottles;
        }
        return bottleDrunk;
    }
}
}
*/