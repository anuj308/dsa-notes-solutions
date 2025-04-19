#include <bits/stdc++.h>
using namespace std;
int countDigit(long long num){
    int c=0;
    while(num){ // for counting n digit
        c++;
        num/=10;
    }
    return c;
}
bool isKpalindromic(long long x,int k){
    stringstream ss;
    ss << x;
    string s = ss.str();
    int xc = countDigit(x);
    for(long long i=0;i<xc;i++){
        if(s[i]=='0') continue;
        for(int j=0;j<xc;j++){
            string st = "";
            st += s[i];
            if(i!=j) st += s[j];
            for(int h=0;h<xc;h++){
                if(h!=i && h!=j){
                    st+=s[h];
                }   
            }
            if(stoll(st)%k==0){
                int n = st.length();
                int possiable = true;
                for(int i=0;i<n/2;i++){
                    if(st[i]!=st[n - i - 1]){
                        possiable=false;
                    }
                }
                
                if(possiable==true) {
                    cout << x  << " " << st << endl;
                    return true;
                }
            }         
        }
    }
    return false;
}

long long countGoodIntegers(int n, int k) {
    long long nstart = pow(10,n-1);
    long long nend = n;
    nend = pow(10,n) - 1; // if n = 1 - nend = 9 , n = 2 - nend = 99 ...
    long long goodCount = 0;
    // cout << nend << endl;
    for(long long x=nstart;x<=nend;x++){
        if(isKpalindromic(x,k)){
            // cout << x << endl;
            goodCount++;
        }

    }
    return goodCount;
}

 bool checkKthBit(int n, int k) {
        // Your code here
        // first change to binary
        string bi = "";
        int nu = n;
        while(nu){
            bi += (char)nu%2;
            nu/=2;
        }
        cout << bi;
        if(bi[k]=='1') return true;
        return false;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<vector<int>,int> mpp;
        long long ans=0;
        for(int i=0;i<=nums1.size()-3;i++){
            for(int j=i+1;j<nums1.size()-1;j++){
                for(int k=j+1;k<nums2.size();k++){
                    if(nums1[i]!=nums1[j] && nums1[j]!=nums1[k] && nums1[k]!=nums1[i]){
                        vector<int> vv = {nums1[i],nums1[j],nums1[k]};
                        mpp[vv]++;
                    }
                }
            }
        }
        for(int i=0;i<=nums2.size()-3;i++){
            for(int j=i+1;j<nums2.size()-1;j++){
                for(int k=j+1;k<nums2.size();k++){
                    vector<int> vv = {nums2[i],nums2[j],nums2[k]};
                    if(mpp.find(vv)!=mpp.end()){
                        ans++;
                    }
                }
            }
        }
        return ans;
    } /// time limit exceded - brute force - O(N^3 * N)
    int pair(vector<int>&nums,int low,int high,int n){
        int cnt = 0;
        for(int i=low;i<=high;i++){
            for(int j=i+1;j<=high;j++){
                if(i<j && nums[i]==nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // cout << pair(nums,i,j,n) << " ";
                if(pair(nums,i,j,n)>=k) ans++;
            } 
        }
        return ans;
    } // time limit exceded O(N^4) 
int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    // cout << countGoodIntegers(3,5);
    cout << checkKthBit(19641,4) ;

    // cout << isKpalindromic(400,4);
    // cout << "Askda";
    // // int goodCount=0;
    //  int x = 110;
    // vector<int> arr;
    // int xc = 3; // count digit
    // int k = 2;
    // stringstream ss;
    // ss << x;
    // string s = ss.str();
    // unordered_map<long long,int> mpp;
    // for(long long i=0;i<xc;i++){
    //     if(s[i]=='0') continue;
    //     for(int j=0;j<xc;j++){
    //         string st = "";
    //         st += s[i];
    //         if(i!=j) st += s[j];
    //         for(int h=0;h<xc;h++){
    //             if(h!=i && h!=j){
    //                 st+=s[h];
    //             }   
    //         }
    //         long long num = stoll(st);
    //         if(mpp.find(num)!=mpp.end()){
    //             continue;
    //         }
    //         mpp[num]++;
    //         cout << num << " " << isKpalindromic(num,k) << endl;
    //     }
       
    // }
    // for(auto c : arr){
    //     cout << c << " ";
    // }

    return 0;
}