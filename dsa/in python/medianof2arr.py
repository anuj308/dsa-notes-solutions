def median(a: int, b: int) -> float:
    i =0
    j =0
    n1 =len(a)
    n2 = len(b)
    n = n1 + n2
    second = int(n/2)
    first = int(n/2 - 1)
    felement = -1
    selement = -1
    count =0
    # print(count,first,second)
    while(i <n1 and j < n2):
        if(a[i]<b[j]):
            if(count == first):
                felement = a[i]
            if(count == second):
                selement = a[i]
            # print(i,count,"i")
            count+=1
            i+=1
        else:
            if(count == first):
                felement = b[j]
            if(count == second):
                selement = b[j]
            # print(j,count,"j")
            count+=1
            j+=1
    while(i < n1):
        if(count == first):
            felement = a[i]
        if(count == second):
            selement = a[i]
        count+=1
        i+=1
    while(j < n2):
        if(count == first):
            felement = b[j]
        if(count == second):
            selement = b[j]
        count+=1
        j+=1
    # print("element",felement,selement)
    if(n%2==0):
        return (felement + selement)/2.0
    else:
        return float(selement)



# with binary search more optimised

# def median(a: int, b: int) -> float:
#     n1 = len(a)
#     n2 = len(b)
#     if(n1>n2):
#         return median(b,a)
#     n = n1 + n2
#     low = 0
#     high = n1
#     left = (n1 + n2 + 1)/2 
#     while(high>=low):
#         mid1 = int((low + high)/2)
#         mid2 = int(left - mid1)
#         l1 = -1
#         l2 = -1
#         r1 = 999999999
#         r2 = 999999999
#         if(mid1 < n1):
#             r1 = a[mid1]
#         if(mid2 < n2):
#             r2 = b[mid2]
#         if(mid1 - 1 >= 0):
#             l1 = a[mid1 - 1]
#         if(mid2 - 1 >= 0):
#             l2 = b[mid2 - 1]
#         if(l1<=r2 and l2<=r1):
#             if(n%2==1):
#                 return float(max(l1,l2))
#             else:
#                 return (max(l1,l2)+min(r1,r2))/2.0
                
#         elif(l1>r2):
#             high = mid1 - 1
#         else:
#             low = mid1 + 1