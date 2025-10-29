
// link :-https://leetcode.com/problems/smallest-number-with-all-set-bits/description
// TYPE:- easy
// name :- 3370. Smallest Number With All Set Bits


// C++
class Solution {
public:
    int smallestNumber(int n) {
        while(true){
            int num = n;
            bool ans = true;
            while(num>0){
                if(num%2==0){
                    ans = false;
                    break;
                }
                num/=2;
            }
            if(ans) return n;
            n++;
        }
        return -1;
    }
};

class Solution {
public:
    int smallestNumber(int n) {
        int num = 2;
        while(true){
           if(num-1>=n){
                return num-1;
           }
           num*=2;
        }
        return -1;
    }
};

// java
class Solution {
    public int smallestNumber(int n) {
        int num = 2;
        while(num>0){
           if(num-1>=n){
                return num-1;
           }
           num*=2;
        }
        return -1;
    }
}