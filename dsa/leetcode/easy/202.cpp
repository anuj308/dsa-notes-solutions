
// link https://leetcode.com/problems/happy-number/
//  happy number (202)

// C++
class Solution {
public:
    bool isHappy(int n) {
        int c = 0;
        while(true){
            if(c>100) break;
            int val = 0;
            int num = n;
            while(num>0){
                val += pow(num%10,2);
                num/=10;
            }
            if(val==1) return true;
            n = val;
            c++;
        }
        return false;
    }
};


// java
class Solution {
    public boolean isHappy(int n) {
        int c = 0;
        while(true){
            if(c>100) break;
            int val = 0;
            int num = n;
            while(num>0){
                val+= Math.pow(num%10,2);
                num/=10;
            }
            if(val==1) return true;
            n = val;
            c++;
        }
        return false;
    }
}