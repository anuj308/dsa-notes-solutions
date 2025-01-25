def findPages(arr: [int], n: int, m: int) -> int:
    high = sumOfArr(n,arr)
    low = maxOfArr(n,arr)
    ans=99999999
    if(m>n):
        return -1
    while(high>=low):
        mid=int((high+low)/2)
        a = possiable(arr,n,m,mid)
        if(a<=m):
            high = mid - 1
        else:
            low = mid + 1
    return low


def possiable(arr,n,student,pages):
    studentAllocated=1
    last=0
    for i in arr:   
        if(i+last<=pages):
            last+=i 
        else:
            last = i
            studentAllocated+=1
    return studentAllocated

def maxOfArr(n,arr):
    ans = 0
    for i in arr:
        if(i>ans):
            ans = i
    return ans

def sumOfArr(n,arr):
    ans = 0
    for i in arr:
        ans += i
    return ans

