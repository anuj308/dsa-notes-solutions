def lowerBound(arr: [int], n: int, x: int) -> int:
    high=n-1
    low=0
    ans=-1
    ansx=0
    while(high>=low):
        mid= int((high+low)//2)
        if(arr[mid]>=x):
            ans = mid
            high = mid-1
        else:
            low= mid+1
            ansx=low
    if(ans==-1):
        # return ansx
        ans = ansx
    # return ans
    print(ans)

# def lowerBound(arr: [int], n: int, x: int) -> int:
#     high=n-1
#     low=0
#     ans=-1
#     while(high>=low):
#         mid= int((high+low)//2)
#         if(arr[mid]>=x):
#             ans = mid
#             high = mid-1
#         else:
#             low= mid+1
#     print(ans)
# #   return ans

a = int(input("enter no of number: "))
b = input("en: ")
arr = b.split(" ")
for i in range(a):
    arr[i]=int(arr[i])

c = True
while(c):
    print("typr end to exit")
    c = int(input("target: "))
    if(c=="end"):
        c=False
    lowerBound(arr,a,c) 
    
    

    