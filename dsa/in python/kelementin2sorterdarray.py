# K-th Element of Two Sorted Arrays
# https://www.naukri.com/code360/problems/k-th-element-of-2-sorted-array_1164159?leftPanelTabValue=PROBLEM
# https://www.youtube.com/watch?v=D1oDwWCq50g



def kthElement(arr1: [int], n: int, arr2: [int], m: int, k: int) -> int:
    t = n + m
    i = 0
    j = 0
    count = 0
    while(i < n and j < m):
        if(arr1[i]<arr2[j]):
            if(count == k - 1):
                return arr1[i]
            count+=1
            i+=1
        else:
            if(count == k - 1):
                return arr2[j]
            count+=1
            j+=1

#with binary sarch

def kthElement(a: [int], n1: int, b: [int], n2: int, k: int) -> int:
    if(n1>n2):
        return kthElement(b,n2,a,n1,k)
    n = n1 + n2
    low = max(0,k-n2)
    high = min(n1,k)
    left = k
    while(high>=low):
        mid1 = int((low + high)/2)
        mid2 = int(left - mid1)
        l1 = -1
        l2 = -1
        r1 = 999999999
        r2 = 999999999
        if(mid1 < n1):
            r1 = a[mid1]
        if(mid2 < n2):
            r2 = b[mid2]
        if(mid1 - 1 >= 0):
            l1 = a[mid1 - 1]
        if(mid2 - 1 >= 0):
            l2 = b[mid2 - 1]
        if(l1<=r2 and l2<=r1):
            return max(l1,l2)
        elif(l1>r2):
            high = mid1 - 1
        else:
            low = mid1 + 1 
 

