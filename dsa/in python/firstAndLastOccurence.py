def upperBound(arr: [int], x: int, n: int) -> int:
    high= n - 1
    low = 0
    ans = n
    while(high>=low):
        mid=int((high+low)/2)
        if(arr[mid]>x):
            ans = mid
            high = mid - 1
        else:
            low = mid + 1
    return ans

def lowerBound(arr: [int], n: int, x: int) -> int:
    high=n-1
    low=0
    ans=-1
    while(high>=low):
        mid= int((high+low)/2)
        if(arr[mid]>=x):
            ans = mid
            high = mid-1
        else:
            low= mid+1
    return ans

def getFirstLast(arr,x,n):
    # second method
    def getLast(arr,n,x):
        high = n - 1
        low = 0
        ans=-1
        while(high>=low):
            mid=int((high+low)/2)
            if(arr[mid]==x):
                ans=mid
                low = mid + 1
            elif(arr[mid]<x):
                low = mid + 1
            else:
                high= mid - 1
        return ans
    first = lowerBound(arr,n,x)
    last = upperBound(arr,x,n) - 1
    if(first == n or arr[first]!=x):
        print("first: ",-1,"last: ",-1) 
    else:   
        print("first: ",first,"last: ",last)
        print("first: ",first,"last: ",getLast(arr,n,x))

a = int(input("enter no of number: "))
b = input("en: ")
arr = b.split(" ")
for i in range(a):
    arr[i]=int(arr[i])


c = True
while(c):
    print("type end or 0 to exit")
    d = int(input("target: "))
    if(c=="end"):
        c=False
    getFirstLast(arr,d,a) 
    
