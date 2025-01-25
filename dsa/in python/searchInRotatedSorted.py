def search(arr, n, k):
    high = n -1
    low = 0
    while(high>=low):
        mid = int((high+low)/2)
        if(arr[mid]==k):
            return mid
        elif(arr[low]<=arr[mid]):
            if(arr[low]<=k and arr[mid]>=k):
                high= mid - 1
            else:
                low =  mid + 1
        else:
            if(arr[mid]<=k and arr[high]>=k):
                low= mid + 1
            else:
                high= mid - 1
    return -1

a = int(input("enter no of number: "))
b = input("en: ")
arr = b.split(" ")
for i in range(a):
    arr[i]=int(arr[i])

c = True
while(c):
    print("typr end to exit")
    c = int(input("search: "))
    if(c=="end"):
        c=False
    ans = search(arr,a,c) 
    print(ans)