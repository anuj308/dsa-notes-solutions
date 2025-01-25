from typing import *


def missingK(vec: List[int], n: int, k: int) -> int:
    high = n - 1
    low = 0
    if(vec[0]>k):
        return k
    while(high>=low):
        mid=int((high+low)/2)
        mis = vec[mid]- (mid+1)
        if(mis<k):
            low  = mid + 1
        else:
            high = mid - 1
    # high point to lower (in array) of missing number , low point to high of missing number
    mis = vec[high]- (high+1)
    return vec[high] + (k - mis)


    