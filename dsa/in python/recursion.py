# print name n times
# normal way ----------

# name = input("enter name: ")
# time= int(input("times: "))
# for i in range(time):
#     print(name)

# recursion way
# def nameTimes(name,time,count):
#     if(count==time):
#         return
#     print(name,time,count)
#     count+=1
#     nameTimes(name,time,count)
# name = input("enter name: ")
# time= int(input("times: "))
# nameTimes(name,time,0)

# print 1 to n 

# def numPrint(i,n):
#     if(i>n):
#         return
#     print(i)
#     numPrint(i+1,n)
# n = int(input("enter number: "))
# numPrint(1,n)

# by back tracking , not use i+1
# def numPrint(i,n):
#     if(i<1):
#         return
#     numPrint(i-1,n)
#     print(i)
# n = int(input("enter number: "))
# numPrint(n,n)

#  print n to 1

# def numPrint(i,n):
#     if(i<n):
#         return
#     print(i)
#     numPrint(i-1,n)
# n = int(input("enter number: "))
# numPrint(n,1)


# sum n to 1 number

# def sumNumber(i,sum):
#     if(i<1):
#         print(sum)
#         return
#     sumNumber(i-1,sum+i)

# a = int(input("enter number: "))
# sumNumber(a,0)

# sum of number form n to 1

# def funC(n):
#     if(n==0):
#         return 0
#     return n + funC(n - 1)

# n = int(input("enter number: "))
# a = funC(n)
# print(a)

# factorial of n 
# def funC(n):
#     if(n==1):
#         return 1
#     return n * funC(n - 1)

# n = int(input("enter number: "))
# a = funC(n)
# print(a)

# reverse the array
# def swap(a,b,arr):
#     temp = arr[a]
#     arr[a] = arr[b]
#     arr[b] = temp
# def function(arr,n,i):
#     if(i>=n/2):
#         return
#     swap(i,n-i-1,arr)
#     function(arr,n,i+1)

# ar1= input("enter number: ")
# arr = ar1.split(" ")
# a = len(arr)
# for i in range(a):
#     arr[i]=int(arr[i])

# function(arr,a,0)
# print('reversed array: ',arr)


# problem on functional recursion

# def fun(i,n,arr):
#     if(i>=n/2):
#         return True
#     if(arr[i]!=arr[n-i-1]):
#         return False
#     return fun(i+1,n,arr)
# ar1= input("enter number: ")
# arr = ar1.split(" ")
# a = len(arr)
# for i in range(a):
#     arr[i]=int(arr[i])

# ans = fun(0,a,arr)
# print('it is a same on reversing: ',ans)

# fibonaccni in recursion
# tc - 2**n exponencial
# def fibo(n):

# print all subsequences