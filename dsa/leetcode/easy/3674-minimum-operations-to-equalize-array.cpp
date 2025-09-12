
// https://leetcode.com/problems/minimum-operations-to-equalize-array/
// Tc-O(n)
class Solution {
    public int minOperations(int[] nums) {
        int last = nums[0];
        int n = nums.length;
        for(int i=1;i<n;i++){
            if(nums[i]!=last) return 1;
        }
        return 0;
    }
}