
// date :- 2025-10-14
// link :-https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/
// TYPE:- medium
// name :- 3349. Adjacent Increasing Subarrays Detection I


// C++
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==1 && n>1) return true;
        for(int i=0;i<=n-2*k;i++){
            bool pos = false;
            for(int j=i;j<i+2*k-1;j++){
                if(j==i+k-1) continue;
                if(nums[j]<nums[j+1]) pos = true;
                else {
                    pos = false;
                    break;
                }
            }
            if(pos) return true;
        }
        return false;
    }
};

// java
class Solution {
    public boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        int n = nums.size();
        if(k==1 && n>1) return true;
        for(int i=0;i<=n-2*k;i++){
            boolean pos = false;
            for(int j=i;j<i+2*k-1;j++){
                if(j==i+k-1) continue;
                if(nums.get(j)<nums.get(j+1)) pos = true;
                else {
                    pos = false;
                    break;
                }
            }
            if(pos) return true;
        }
        return false;
    }
}