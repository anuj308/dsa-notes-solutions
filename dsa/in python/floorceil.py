# x is target
# n is no of element in the arr
def getceil(arr,n,x):
    high = n - 1
    low = 0
    ans=-1
    while(high>=low):
        mid = int((high+low)/2)
        if(arr[mid]>=x):
            ans = arr[mid]
            high = mid - 1
        else:
            low = mid + 1
    return ans

def getFloor(arr,n,x):
    high = n - 1
    low = 0
    ans= -1
    while(high>=low):
        mid = int((high+low)/2)
        if(arr[mid]<=x):
            ans = arr[mid]
            low = mid + 1
        else:
            high = mid - 1
    return ans

def getFloorCeil(arr,n,x):
    f = getFloor(arr,n,x)
    c = getceil(arr,n,x)
    print("floor: ",f,"ceil: ",c)

a = int(input("enter no of number: "))
b = input("en: ")
c = int(input("target: "))
arr = b.split(" ")
for i in range(a):
    arr[i]=int(arr[i])

getFloorCeil(arr,a,c)
    

