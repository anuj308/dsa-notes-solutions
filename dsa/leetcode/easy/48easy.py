class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = s.split(" ")
        for i in range(len(ans) - 1, -1, -1):
            # print(i,len(ans[i]))
            if len(ans[i])!=0:
                # print(i,len(ans[i]),"answer")
                return len(ans[i])
                break
        # print(len(ans[-1]))
        