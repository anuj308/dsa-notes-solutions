# https://leetcode.com/problems/remove-element/description/
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k=0
        n = len(nums)
        ans=[]
        for i in range(0,n):
            if nums[i]!=val:
                ans.append(nums[i])
                k+=1
        nums.clear()
        for i in range(0,k):
            nums.insert(i,ans[i])
        return k