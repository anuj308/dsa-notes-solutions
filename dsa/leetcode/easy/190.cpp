
// link - https://leetcode.com/problems/reverse-bits/
// name - 190 reverse bits

// tc-O(1), Sc-O(1)
// C++
class Solution {
public:
    int reverseBits(int n) {
        vector<int> binary(32,0);
        if(n<0) binary[31]=1; // for negative it 1 and for positive it 0
        int c = 0; 
        while(n>0){ // to binary
            binary[c]=n%2;
            c++;
            n/=2;
        }
        // in binary it is already reversed
        int ans = 0;
        int p = 31;
        for(int i=0;i<32;i++){
            if(binary[i]==1) ans+= pow(2,p);
            p--;
        }
        return ans;
    }
};

// java
class Solution {
    public int reverseBits(int n) {
        int[] binary = new int[32];
        if(n<0) binary[31]=1;
        int c = 0;
        while(n>0){
            binary[c++] = n%2;
            n/=2;
        }
        int p = 31;
        int ans = 0;
        for(int i=0;i<32;i++){
            if(binary[i]==1) ans+=Math.pow(2,p);
            p--;
        }
        return ans;
    }
}