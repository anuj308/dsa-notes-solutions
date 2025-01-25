def findMin(arr: [int]):
    n = len(arr)
    high = n - 1
    low = 0
    ans = 999999999999999999
    while(high>=low):
        mid=int((high+low)/2)
        if(arr[low]<=arr[high]):
            if(arr[low]<ans):
                ans = arr[low]
            break
        if(arr[low]<=arr[mid]):
            if(arr[low]<ans):
                ans = arr[low]
            low = mid + 1
        else: 
            if(arr[mid]<ans): #here
                ans = arr[mid]
            high = mid - 1
    return ans


 # can use minmum function for input value ans,arr[mid] and in above ans , arr[low]

# more optimised

# def findMin(arr: [int]):
#     n = len(arr)
#     high = n - 1
#     low = 0
#     ans = 999999999999999999
#     while(high>=low):
#         mid=int((high+low)/2)
#         if(arr[low]<=arr[high]):
#             if(arr[low]<ans):
#                 ans = arr[low]
#             break
#         if(arr[low]<=arr[mid]):
#             if(arr[low]<ans):
#                 ans = arr[low]
#             low = mid + 1
#         else: 
#             if(arr[mid]<ans): #here
#                 ans = arr[mid]
#             high = mid - 1
#     return ans