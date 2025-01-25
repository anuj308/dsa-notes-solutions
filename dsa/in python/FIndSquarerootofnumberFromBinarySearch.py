def floorSqrt(n):
   high = n
   low = 1
   ans=0
   while(high>=low):
      mid=int((high+low)/2)
      if(mid*mid<=n):
         ans = mid
         low = mid + 1
      else:
         high = mid - 1
   return ans



n= int(input())
print(floorSqrt(n))