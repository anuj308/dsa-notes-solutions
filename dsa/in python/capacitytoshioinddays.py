from math import *

def leastWeightCapacity(weights, d):
    n = len(weights) 
    
    low = maxOfArr(n,weights)
    high = sumOfArr(n,weights)
    while(high>=low):
        mid=int((high+low)/2)
        a = weightsMinDay(weights,mid)
        if(a<=d):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return low

def weightsMinDay(arr,weight): #if array is sorted
    ans = 1
    temp = 0
    for i in arr:
        if(temp + i>weight):
            ans = ans  + 1
            temp = 0
            temp =  i
        else:
            temp = temp + i
    return ans 

def maxOfArr(n,arr):
    ans = -1
    for i in arr:
        if(i>ans):
            ans = i
    return ans

def sumOfArr(n,arr):
    ans = 0
    for i in arr:
        ans += i
    return ans