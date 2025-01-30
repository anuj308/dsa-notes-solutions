# https://leetcode.com/problems/roman-to-integer/
def romanToInt(s):
    print(s)
    ans=0
    for i in range(0,len(s)):
        if i>0 and s[i-1] == "I" and s[i]=="V":
            ans+=3
        elif i>0 and s[i-1] == "I" and s[i]=="X":
            ans+=8
        elif i>0 and s[i-1] == "X" and s[i]=="L":
            ans+=30
        elif i>0 and s[i-1] == "X" and s[i]=="C":
            ans+=80
        elif i>0 and s[i-1] == "C" and s[i]=="D":
            ans+=300
        elif i>0 and s[i-1] == "C" and s[i]=="M":
            ans+=800
        elif s[i] == "I":
            ans+=1
        elif s[i] == "V":
            ans+=5
        elif s[i] == "X":
            ans+=10
        elif s[i] == "L":
            ans+=50
        elif s[i] == "C":
            ans+=100
        elif s[i] == "D":
            ans+=500
        elif s[i] == "M":
            ans+=1000
        print(s[i],ans)
    print(ans)   

romanToInt("MCMXCIV")