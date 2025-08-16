
// LeetCode Daily: 2025-08-16
// Problem: Maximum of 69 number     (1323)
// URL: https://leetcode.com/problems/maximum-69-number
// Difficulty: Easy

// ==================== C++ SOLUTION ====================
//Tc-O(N^2), Sc-O(n)
int maximum69Number (int num) {
    int ans = num;
    vector<int> d;
    while(num>0){ // O(n)
        d.push_back(num%10);
        num/=10;
    }
    reverse(d.begin(),d.end()); // O(n/2)
    int n = d.size();
    for(int i=0;i<n;i++){ // Tc-O(N^2)
        int temp = d[i];
        if(d[i]==6) d[i]=9;
        int digit = 0;
        for(auto t : d) digit = digit*10 + t;
        ans=max(ans,digit);
        d[i]=temp;
    }
    return ans;
}

/* ==================== PYTHON SOLUTION ====================
# Tc-O(N^2), Sc-O(n)
class Solution(object):
    def maximum69Number (self, num):
        ans = num
        d = []
        while(num>0):
            d.append(num%10)
            num/=10
        d.reverse()
        n = len(d)
        for i in range(0,n):
            temp = d[i]
            if d[i]==6:
                d[i]=9
            digit = 0
            for no in d:
                digit = 10*digit + no
            ans=max(ans,digit)
            d[i]=temp

        return ans
*/

/* ==================== JAVA SOLUTION ====================
// Tc-O(N^2), Sc-O(n)
class Solution {
    public int maximum69Number (int num) {
        int ans = num;
        List<Integer> d= new ArrayList<>();
        while(num>0){
            d.add(num%10);
            num/=10;
        }
        Collections.reverse(d);
        int n = d.size();
        for(int i=0;i<n;i++){
            int temp = d.get(i);
            if(d.get(i)==6) d.set(i,9);
            int digit = 0;
            for(int t : d) digit = digit*10 + t;
            ans= Math.max(ans,digit);
            d.set(i,temp);
        }
        return ans;
    }
}

// Alternative Java bit manipulation:
// return n > 0 && (n & (n-1)) == 0 && (n & 0x55555555) != 0;
*/