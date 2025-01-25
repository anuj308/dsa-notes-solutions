def largestSubarraySumMinimized(a: [int], k: int) -> int:
    n = len(a)
    high = sumOfArr(n,a)
    low = maxOfArr(n,a)
    while(high>=low):
        mid=int((high+low)/2)
        b = noOfSubArr(n,a,k,mid)
        if(b<=k):
            high = mid - 1
        else:
            low = mid + 1
    return low

def noOfSubArr(n,arr,split,mid):
    last = 0
    splitIn=1
    for i in arr:
        if(last+i<=mid):
            last+=i
        else:
            splitIn+=1
            last = i
    return splitIn
def sumOfArr(n,arr):
    ans = 0
    for i in arr:
        ans+=i
    return ans
def maxOfArr(n,arr):
    ans = 0
    for i in arr:
        if(i>ans):
            ans = i 
    return ans
