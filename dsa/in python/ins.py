   
def getCeil(a,n,x):
    high = n-1
    low =0
    ceil = -1
    ceilx= 0
    while(high>=low):
        mid=int((high+low)//2)
        if(a[mid]>=x):
            ceil = a[mid]
            high = mid-1
        else:
            # ceilx= a[mid]
            low= mid+1
    # if(ceil==-1):
    #     ceil=ceilx

    return ceil

def getFloor(a,n,x):
    highf= n -1
    lowf= 0
    floor = -1
    while(highf>=lowf):
        mid=int((highf+lowf)/2)
        if(a[mid]<=x):
            floor= a[mid]
            lowf=mid+1
        else:
            highf=mid-1
    return floor
def getFloorAndCeil(a, n, x):
    f = getFoor(a,n,x)
    c = getCeil(a,n,x)
    return f,c
    
