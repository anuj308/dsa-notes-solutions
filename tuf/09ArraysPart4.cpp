#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    // tc- O(N^2)
    int n= nums.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && nums[i]+nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

vector<int> twoSumBetter(vector<int>& nums, int target) {
    // Better - O(N*log N) sc -O(N)

    map<int,int> mpp;
    
    for(int i=0;i<nums.size();i++){
        int rem = target - nums[i];
        if(mpp.find(rem)!=mpp.end()){
            return {mpp[rem],i};
        }
        mpp[nums[i]]=i;
    }
    return {-1,-1};
}

string read(int n, vector<int> book, int target)
{
    // Tc - O(N) + O(N logN) optimal sc - O(1)

    sort(book.begin(),book.end());

    int left = 0;
    int right = n-1;
    while(right>left){
        int sum = book[left]+book[right];
        if(sum==target){
            return "YES";
        }else if(sum > target) right--;
        else left++;
    }
    return "NO";
}


// #include <bits/stdc++.h> 
// with hashing - O(2N)
void sortArrayOptimalBetter(vector<int>& arr, int n)
{
    // tc - O(2N)
    int c1=0;
    int c2=0;
    int c3=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) c1++;
        else if(arr[i]==1) c2++;
        else c3++;
    }
    for(int i=0;i<c1;i++){
        arr[i]=0;
    }
    for(int i=c1;i<c2+c1;i++){
        arr[i]=1;
    }
    for(int i=c1+c2;i<c1+c2+c3;i++){
        arr[i]=2;
    }
  
}
void sortArrayOptimal(vector<int>& arr, int n)
{
    // tc - O(N)
    int low=0,mid=0,high=n-1;
    while(high >= mid){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid]==1){
            mid++;
        }else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

int majorityElementBetter(vector<int>& nums) {
    // tc O(N) + O(NlogN) sc- O(N)
    unordered_map<int,int> st;
    for(auto n : nums){
        st[n]++;
    }
    int n1 = nums.size();
    for(auto n : st){
        // cout << n.second << n1/2 << endl;
        if(n.second>(n1/2) ){
            return n.first;
        }
    }
    return -1;
}

// Optimal ->  O(N) sc - O(1)
    // Moore's Voting Algo
    // when there is a majority element its count will not be cancelled out.
int majorityElement(vector<int>& nums) {
   int cu;
   int count=0;
   for(int i=0;i<nums.size();i++){
        if(count==0){
            cu=nums[i];
            count++;
        }else if(nums[i]==cu){
            count++;
        }else {
            count--;
        }
   }
   return cu;
}

// brute force O(N^3)
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    
    for(int i=0;i<nums.size();i++){
       for(int j=i;j<nums.size();j++){
            int sum=0;
            for(int k=i;k<=j;k++){
                sum+=nums[k];
            }
            maxSum = max(sum,maxSum);
            sum=0;      
       }
    }
    return maxSum;
}
// Better O(N^2)
int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                maxSum = max(sum,maxSum);
            }
        }
        return maxSum;
    }
// optimal - Kadane algorithm tc - O(N) sc- O(1)
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum>maxSum){
            maxSum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}