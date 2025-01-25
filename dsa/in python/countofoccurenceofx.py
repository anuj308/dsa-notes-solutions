def upperBound(arr: [int], x: int, n: int) -> int:
    high= n - 1
    low = 0
    ans = n
    while(high>=low):
        mid=int((high+low)/2)
        if(arr[mid]>x):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans

def lowerBound(arr: [int], n: int, x: int) -> int:
    high=n-1
    low=0
    ans=-1
    while(high>=low):
        mid= int((high+low)/2)
        if(arr[mid]>=x):
            ans = mid
            high = mid-1
        else:
            low= mid+1
    return ans


def count(arr: [int], n: int, x: int) -> int:
    first = lowerBound(arr,n,x)
    last = upperBound(arr,x,n) - 1
    if(first==-1):
        return 0
    count = last + 1 - first
    return count
