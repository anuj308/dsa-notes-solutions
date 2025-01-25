from os import *
from sys import *
from collections import *
from math import *
def lowerBound(arr: [int], n: int, x: int) -> int:
    high=n-1
    low=0
    ans=-1
    while(high>=low):
        mid= int((high+low)//2)
        if(arr[mid]>=x):
            ans = mid
            high = mid-1
        else:
            low= mid+1
    # print(ans)
    return ans
def rowMaxOnes(mat, n, m):
    countStore=-1
    indexStore=-1
    index=0
    for i in mat:
        if(m==1):
            if(i[0]==1):
                if(1>countStore and indexStore<index):
                    countStore = 1
                    indexStore = index
                index+=1

        c = lowerBound(i,m,1)
        # print(c,"bound")
        if(c==-1):
            continue
        if(m - c>countStore and indexStore<index):
            countStore = m - c
            indexStore = index
            # print(countStore,indexStore,"Asa")
        index+=1
    return indexStore