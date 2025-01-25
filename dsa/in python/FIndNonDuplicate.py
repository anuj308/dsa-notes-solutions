def singleNonDuplicate(arr):
    n = len(arr)
    high = n - 2
    low = 1
    if(n==1):
        return arr[0]
    if(arr[0]!=arr[1]):
        return arr[0]
    if(arr[n - 1]!=arr[n - 2]):
        return arr[n - 1]
    while(high>=low):
        mid=int((high+low)/2)
        if(arr[mid]!=arr[mid-1] and arr[mid]!=arr[mid+1]):
            return arr[mid]
        if(mid%2==0):
            if(arr[mid - 1]== arr[mid]):
                high = mid - 1
            else:
                low = mid + 1
        else:
            if(arr[mid - 1]== arr[mid]):
                low = mid + 1
            else:
                high = mid - 1
