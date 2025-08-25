
// LeetCode Daily: 2025-08-19
// Problem: no of Zero filled subarray     (2348)
// URL: https://leetcode.com/problems/number-of-zero-filled-subarrays
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long  ans = 0;
        int n = nums.size();
        int zero = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans+=zero+1;
                zero++;
            }else {
                zero = 0;
            }
        }
        return ans;
    }
};

/* ==================== PYTHON SOLUTION ====================
# Tc-O(N), Sc-O(1)
class Solution(object):
    def zeroFilledSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        zero = 0
        n = len(nums)
        for i in range(0,n):
            if(nums[i]==0):
                ans+=zero+1
                zero+=1
            else:
                zero=0
        return ans
        
*/

/* ==================== JAVA SOLUTION ====================
# Tc-O(N), Sc-O(1)
class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long ans = 0;
        int zero = 0;
        int n = nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans+=zero+1;
                zero++;
            }else zero=0;
        }
        return ans;
    }
}

*/