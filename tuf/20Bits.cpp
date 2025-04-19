#include <bits/stdc++.h>
using namespace std;
bool checkKthBit(int n, int k) {
    // Your code here
    // first change to binary
    string bi = "";
    int nu = n;
    while(nu){
        bi += (nu%2) ? '1' : '0';
        nu/=2;
    }
    if(k >= bi.size()) return false; // out of bound
    return bi[k]=='1';
}
bool checkKthBit(int n, int k) {
    // if (n & ( 1 << k)) == 0 means n - k th bit is 1 - 1 & 1 is 1
    // else  it 0
   return (n & ( 1 << k)) != 0;
}
int setBits(int n){
    // Write your code here.
    int nu = n;
    string bi="";
    while(nu){
        bi += (nu%2) ? '1' : '0'; 
        // If nu%2 -- 0 - false 
        // If nu%2 -- 1 - true.
        nu/=2;
    }
    int c = -1;
    for(int k=0;k<bi.size();k++){
        if(bi[k]=='0'){
            c = k;
            break;
        } 
    }
    if(c==-1) return n;
    return n ^( 1 << c);
}
bool isPowerOfTwo(int n) {
    int nu = n;
    string bi = "";
    while(nu){
        bi += (nu%2) ? '1' : '0';
        nu/=2;
    }
    int ans=0;
    for(auto k : bi){
        if(k=='1') ans++;
    }
    if(n<0) ans++; // as first bit if neg - store - 1
    return ans==1;
}
bool isPowerOfTwo(int n) {
    if(n<=0) return false;  // neg or 0 can not be in power of 2 only if we consider negative power which we do not in this question
    return (n & (n - 1)) == 0;
}
int setBits(int n) {
    // Write Your Code here
    int nu = n;
    string bi = "";
    while(nu){
        bi+= (nu%2) ? '1' : '0';
        nu/=2;
    }
    int ans=0;
    for(auto k : bi){
        if(k=='1') ans++;
    }
    return ans;
} // count no of ones
int setBits(int n) {
    // Write Your Code here
    int ans = 0;
    while(n>1){
        ans+= (n & 1); // if nth last bit is 1 & 1 - 1 or 0 & 1 - 1
        n = n >> 1; // neans nu/2
    }
    if(n==1) ans++;
    return ans;
}
void swapNumber(int &a, int &b) {
	a = a ^ b;
	b = a ^ b; // (a ^ b)^ b ^ b = 0 -- a
	a = a ^ b; // (a ^ b)^ b =  a ^ a = 0 -- b
}
bool isEven(int n) {
    // code here
    return (n%2)==0;
}
int divide(int dividend, int divisor) {
    if(dividend==divisor) return 1;
    bool sign = true;
    if(dividend>=0 && divisor<0) sign = false;
    else if(dividend<=0 && divisor>0) sign = false;
    long n = labs((long)dividend);
    long d = labs((long)divisor);
    long ans = 0;
    while(n >= d){
        int cnt = 0;
        while(n >= (d << (cnt+1))){// d * 2 ^cnt+1
            cnt++;
        }
        ans += (1 << cnt);
        n = n - (d << cnt);
    }
    if(ans == (1 << 31) && sign==true){
        return INT_MAX;
    }
    if(ans == (1 << 31) && sign==false){
        return INT_MIN; 
    }
    return sign ? ans : -1*ans;
}
int minBitFlips(int start, int goal) {
    int nu= start^goal; // so if both bit are different then 1 otherwise 0
    int ans = 0; // for counting no of 1s in nu
    while(nu>1){
        ans += nu%2;
        nu = nu >> 1; // nu/2
    }
    if(nu==1) ans++;
    return ans;
}// by me
int singleNumber(vector<int>& nums) {
    int n = nums[0];
    for(int i=1;i<nums.size();i++){
        n = n ^ nums[i];
    }
    return n;
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    int subset = 1 << n;
    for(int num=0;num<subset;num++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(num & (1 << j)){
                v.push_back(nums[j]);
            }
        }
        ans.push_back(v);
    }
    return ans;
} // tc - 0(2^N * n)
int findXOR(int l, int r) {
    // complete the function here
    int xorr = l;
    for(int i=l+1;i<=r;i++){
        xorr = xorr ^ i;
    }
    return xorr;
} // tc O(n) brute force
int funNXor(int n){
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
    return n;
} // function which give Xor from 1 to n
int findXOR(int l, int r) {// xor l , l+ 1 ... r
    
    // xor (1 ^ 2 .. l - 1 ) ^ (1 ^ 2 ^ ... r) =  xor l , l+ 1 ... r
    return funNXor(l-1) ^ funNXor(r);
} 
vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    long long xo = 0;
    for(int i=0;i<N;i++){
        xo = xo ^ Arr[i];
    }
    long long rightMost = (xo & (xo-1))^xo;
    long long b1=0;
    long long b2=0;
    for(int i=0;i<N;i++){
        if(Arr[i] & rightMost){
            b1= b1^Arr[i]; 
        }else{
            b2=b2^Arr[i];
        }
    }
    if (b1 > b2)
        return {(int)b1, (int)b2};  // Larger first
    return {(int)b2, (int)b1};  // Larger first
} //  tc - O(2n) sc - O(1)
int main(){
    return 0;
}