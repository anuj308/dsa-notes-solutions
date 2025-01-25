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

