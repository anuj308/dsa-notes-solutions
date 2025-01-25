def NthRoot(n: int, m: int) -> int:
    high = m
    low = 0
    while(high>=low):
        mid=int((high+low)/2)
        a = pow(mid,n)
        if(a<=m):
            if(a==m):
                return mid
            low = mid + 1
        else:
            high = mid - 1
    return -1