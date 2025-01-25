def findPeakElement(arr: [int]) -> int:
    n = len(arr)
    low = 1
    high = n - 2
    if(n==1):
        return 1
    if(arr[0]>arr[1]):
        return 0
    if(arr[n - 1]>arr[n - 2]):
        return n - 1
    while(high>=low):
        mid=int((high+low)/2)
        if(arr[mid - 1]<arr[mid] and arr[mid]>arr[mid + 1]):
            return mid
        if(arr[mid - 1]<arr[mid]):
            low = mid + 1
        else:
            high = mid - 1