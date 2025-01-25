from math import *

def smallestDivisor(arr: [int], limit: int) -> int:
    n = len(arr)
    high = maxOfArr(n,arr)
    low = 1
    ans = 9999999999
    while(high>=low):
        mid=int((high+low)/2)
        a = funFordivisor(n,arr,mid)
        if(a<=limit and mid<ans):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans
        

def funFordivisor(n,arr,div):
    ans = 0
    for i in arr:
        ans = ans + ceil(i/div)
    return ans


def maxOfArr(n,arr):
    ans = -1
    for i in arr:
        if(i>ans):
            ans = i
    return ans
