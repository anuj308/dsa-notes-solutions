
// LeetCode Daily: 2025-10-15
// Problem: 3350. Adjacent Increasing Subarrays Detection II
// URL: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
//Tc-O(N), Sc-O(1)
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int a = 1;
        int b = 1;
        int j = 0;
        int last = 0;
        while(j<n-1){
            while(j<n-1 && nums[j]<nums[j+1]){
                a++;
                j++;
            }
            j++;
            ans=max(ans,a/2);
            ans=max(ans,min(last,a));
            while(j<n-1 && nums[j]<nums[j+1]){
                b++;
                j++;
            }
            j++;
            ans=max(ans,b/2);
            ans=max(ans,min(a,b));
            last = b;
            a=1;
            b=1;
        }
        return ans;
    }
};

//  ==================== PYTHON SOLUTION ====================
// # Tc-O(N), Sc-O(1)

        
        

// /* ==================== JAVA SOLUTION ====================
// # Tc-O(N), Sc-O(1)
class Solution {
    public int maxIncreasingSubarrays(List<Integer> nums) {
        int ans = 0;
        int n = nums.size();
        int a = 1;
        int b = 1;
        int j = 0;
        int last = 0;
        while(j<n-1){
            while(j<n-1 && nums.get(j)<nums.get(j+1)){
                a++;
                j++;
            }
            j++;
            ans=Math.max(ans,a/2);
            ans=Math.max(ans,Math.min(last,a));
            while(j<n-1 && nums.get(j)<nums.get(j+1)){
                b++;
                j++;
            }
            j++;
            ans=Math.max(ans,b/2);
            ans=Math.max(ans,Math.min(a,b));
            last = b;
            a=1;
            b=1;
        }
        return ans;
    }
}