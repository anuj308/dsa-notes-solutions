def findLargestMinDistance(boards:list, k:int):
    n = len(boards)
    high = sumOfArr(n,boards)
    low = maxOfArr(n,boards)
    ans = 99999999
    if(k>n):
        return -1
    while(high>=low):
        mid=int((high+low)/2)
        p = PainterUse(n,boards,k,mid)
        if(p<=k):
            high = mid - 1
        else:
            low = mid + 1
    return low

def PainterUse(n,arr,painter,mid):
    last = 0
    painterUsed=1
    for i in arr:
        if(last+i<=mid):
            last+=i
        else:
            painterUsed+=1
            last = i
    return painterUsed

def sumOfArr(n,arr):
    ans = 0
    for i in arr:
        ans += i
    return ans

def maxOfArr(n,arr):
    ans = 0
    for i in arr:
        if(i>ans):
            ans = i
    return ans