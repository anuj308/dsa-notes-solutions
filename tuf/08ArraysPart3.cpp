#include <bits/stdc++.h>
using namespace std;

int missingNumberBruteForce(vector<int>&a, int n) { // tc - O(n*n) , sc - O(1)
    // Write your code here.
    for(int i=1;i<=n;i++){
        int flag=0;
        for(int j=0;j<n;j++){
            if(i==a[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return i;
        }
    }
    
}

int missingNumberBetter(vector<int>&a, int n) { // tc - O(2n) sc -O(n)
    // Write your code here.
    vector<int> vis(n+1,0);
    for(int i=0;i<n;i++){
        vis[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            return i;
        }
    }
    
}

int missingNumberBest(vector<int>&a, int n) { // tc - O(n) sc - O(1)
    // Write your code here.
    int sum = (n*(n+1))/2;
    int n1 = a.size();
    int sum2=0;
    for(int i=0;i<n1;i++){
        sum2+=a[i];
    }

    return sum-sum2;
}

int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int c=0;
    int ans=0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            c++;
            ans = max(ans,c);
        }else{
            c=0;
        }
    }
    return ans;
}

 int singleNumberBetter(vector<int>& nums) {
        // brute force is n*n
        unordered_map<int,int> freq;

        for(int n : nums){
            freq[n]++;
        }

        for(auto p : freq){
            if(p.second==1){
                return p.first;
            }
        }


      return -1;
    }

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // for positive and negative and for only positive also works
    map<long long,int> preSumMap;
    long long sum =0;
    int maxlen = 0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];
        if(sum==k){
            maxlen = max(maxlen,i+1);
        }
        long long rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            // if rem is there in map then
            int len = i - preSumMap[rem];
            maxlen = max(maxlen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){ 
            // if sum is not there then only update
            // preSumMap.find(sum) if not found returns preSumMap.end()
            preSumMap[sum]=i;

        }
    }
    return maxlen;
}

int longestSubarrayWithSumKBetter(vector<int> a, long long k) {
    // for positive only
    int n = a.size();
    int left = 0; 
    int right = 0;
    long long sum = a[0];
    int maxlen = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum-=a[left];
            left++;
        }
        if(sum==k){
            maxlen=max(maxlen,right - left + 1);
        }

        right++;
        if(right < n) sum+=a[right];
    }   
    return maxlen;
}
int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   

    return 0;
}