#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArrayBruteForce(vector<int>& nums) {
    // brute force tc- O(2N) , sc - O(N)
    int n = nums.size();
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(nums[i]<0){
            neg.push_back(nums[i]);
        }else{
            pos.push_back(nums[i]);
        }
    }
    int k=0,l=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            nums[i]=pos[k];
            k++;
        }else{
            nums[i]=neg[l];
            l++;
        }
    }
    return nums;
}
vector<int> rearrangeArray(vector<int>& nums) {
    // tc - O(N) sc - O(N)
        int n = nums.size();
        vector<int>ans(n);
        int negIndex=1;
        int posIndex=0;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negIndex]=nums[i];
                negIndex+=2;
            }else{
              ans[posIndex]=nums[i];
              posIndex+=2;
            }
        }
        return ans;
    }

vector<int> alternateNumbers(vector<int>&a) {
    // https://www.naukri.com/code360/problems/alternate-numbers_6783445
    // brute force tc- O(2N) , sc - O(N)
    int n = a.size();
    vector<int>pos;
    vector<int>neg;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            neg.push_back(a[i]);
        }else{
            pos.push_back(a[i]);
        }
    }
    int totalPos = pos.size();
    int totalNeg = neg.size();
    
    if(totalNeg>totalPos){
        for(int i=0;i<totalPos;i++){
            a[i*2]=pos[i];
            a[i*2+1]=neg[i];
        }
        int ind=2*totalPos;
        for(int i=totalPos;i<totalNeg;i++){
            a[ind]=neg[i];
            ind++;
        }
    }else{
        for(int i=0;i<totalNeg;i++){
            a[i*2]=pos[i];
            a[i*2+1]=neg[i];
        }
        int ind=2*totalNeg;
        for(int i=totalNeg;i<totalPos;i++){
            a[ind]=pos[i];
            ind++;
        }
    }
    return a;
    
}

// #include <bits/stdc++.h>
// brute force - to find all ther permutation - then liner search - next index 
//  tc - O(N! * N) , for permutation, liner search
// next permutation optimal
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    // tc - O(N+N+N) - O(3N) , sc - 
    int breakPoint=-1;
    for(int i=n-2;i>=0;i--){
        if(permutation[i]<permutation[i+1]){
            breakPoint=i;
            break;
        }
    }
    if(breakPoint==-1){
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    for(int i=n-1;i>breakPoint;i--){
        if(permutation[breakPoint]<permutation[i]){
            swap(permutation[breakPoint],permutation[i]);
            break;
        }
       
    }
    reverse(permutation.begin() + breakPoint+ 1,permutation.end());
    return permutation;
}


int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}