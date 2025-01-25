def searchInARotatedSortedArrayII(A : List[int], key : int) -> bool:
    n = len(A)
    high = n - 1
    low = 0
    while(high>=low):
        mid=int((high+low)/2)
        if(A[mid]==key):
            return True
	    #if low =mid = high we can't find the sorted side so trim down the search space
        if(A[mid]==A[low] and A[mid]==A[high]):
            low = low + 1
            high = high - 1
            continue
        elif(A[low]<=A[mid]):
            if(A[low]<=key and A[mid]>=key):
                high= mid - 1
            else:
                low = mid + 1
        else:
            if(A[mid]<key and A[high]>=key):
                low = mid + 1
            else:
                high = mid - 1
    return False
