def findKRotation(arr : [int]) -> int:
    n = len(arr)
    high = n - 1
    low = 0
    ansValue = 999999999999999
    ansIndex = 0
    while(high>=low):
        mid=int((high+low)/2)
        if(arr[low]<=arr[mid]):
            if(ansValue>arr[low]):
                ansValue = arr[low]
                ansIndex = low
            low = mid + 1
        else:
            if(ansValue>arr[mid]):
                ansValue = arr[mid]
                ansIndex = mid
            high = mid - 1
    return ansIndex