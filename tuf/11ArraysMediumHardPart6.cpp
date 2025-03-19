#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> generate(int numRows) {
    // done by me
    vector<vector<int>> ans;
    // tc - O(N^2) , sc O(N^2) + O(N)

    for(int i=0;i<numRows;i++){
        vector<int> arr;
        arr.push_back(1);

        for(int j=0;j<i-1;j++){
            int sum = ans[i-1][j] + ans[i-1][j+1];
            arr.push_back(sum);
        }

        if(i!=0){
            arr.push_back(1);
        }

        ans.push_back(arr);
    }

    return ans;
}

vector<int> majorityElementBetter(vector<int>& nums) {
        // tc - O(N) sc - O(N) by me
    int n = nums.size();
    int count=0;
    unordered_map<int,int> mpp; // element , value
    for(int i=0;i<n;i++){
        mpp[nums[i]]++;
    }

    vector<int> ans;
    for(auto it : mpp){
        if(it.second >n/3){
            ans.push_back(it.first);
        }
    }
    return ans;
}

// #include <bits/stdc++.h>
vector<int> majorityElement(vector<int> nums) {
    // optimal  tc - O(N) sc - O(1)
    int cnt1=0;
    int cnt2=0;
    int el1= INT_MIN;
    int el2= INT_MIN;
    int n = nums.size();
    for(int i=0;i<n;i++){
        if(cnt1==0 && el2!=nums[i]){
            el1 = nums[i];
            cnt1=1;
        }else if(cnt2==0 && el1!=nums[i]){
            el2 = nums[i];
            cnt2=1;
        }else if(nums[i]==el1){
            cnt1++;
        }else if(nums[i]==el2){
            cnt2++;
        }else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++){
        if(nums[i]==el1) cnt1++;
        if(nums[i]==el2) cnt2++;
    }
    vector<int> ans;
    if(cnt1 > n/3) ans.push_back(el1);
    if(cnt2 > n/3) ans.push_back(el2);
    sort(ans.begin(),ans.end());
    return ans;
}
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    // brute force - tc - O(N^3) + O(Log N) sc - O(N^2)
    set<vector<int>> st;
    int n = nums.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> arr = {nums[i],nums[j],nums[k]};
                    sort(arr.begin(),arr.end());
                    st.insert(arr);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


 vector<vector<int>> threeSumBetter(vector<int>& nums) { 
    // tc - O(N^2) + O(Log N) sc - O(N^2) + O(N)
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            set<int> hashset;
            for(int j=i+1;j<n;j++){
                int third = -(nums[i]+nums[j]);
                if(hashset.find(third)!=hashset.end()){
                    vector<int> arr = {nums[i], nums[j], third};
                    sort(arr.begin(),arr.end());
                    st.insert(arr);
                }
                hashset.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }

vector<vector<int>> threeSumOptimal1(vector<int>& nums) { 
    int n = nums.size();
    sort(nums.begin(),nums.end());

    vector<vector<int>> st;
    for(int i=0;i<n;i++){
        int j=i+1;
        int k= n-1;
        while(k>j){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                while(k>j){
                    j++;
                    if(nums[j-1]!=nums[j]){
                        break;
                    }
                }
            }else if(sum>0){
                while(k>j){
                    k--;
                    if(nums[k+1]!=nums[k]){
                        break;
                    }
                }
            }else{
                vector<int> arr= {nums[i],nums[j],nums[k]};
                st.push_back(arr);
                while(k>j){
                    j++;
                    if(nums[j-1]!=nums[j]){
                        break;
                    }
                }
                while(k>j){
                    k--;
                    if(nums[k+1]!=nums[k]){
                        break;
                    }
                }
            }
        }
        
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
vector<vector<int>> threeSum(vector<int>& nums) { 
   // tc - O(N^2) + O(Log N) sc - O(1)
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> st;
    for(int i=0;i<n;i++){
        if( i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1;
        int k= n-1;
        while(k>j){
            int sum = nums[i] + nums[j] + nums[k];
            if(sum<0){
                j++;
            }else if(sum>0){
                k--;
            }else{
                vector<int> arr= {nums[i],nums[j],nums[k]};
                st.push_back(arr);
                k--;
                j++;
                while(k>j && nums[j-1]==nums[j]) j++;
                while(k>j && nums[k+1]==nums[k]) k--;
            }
        }
        
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

vector<vector<int>> fourSumBruteForce(vector<int>& nums, int target) {
    // tc - O(N^4) + O(Log N) sc - O(N^2)
    int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int p=k+1;p<n;p++){
                    long long sum = (long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[p];
                    if(sum==(long long)target){
                        vector<int> arr = {nums[i],nums[j],nums[k],nums[p]};
                        st.insert(arr);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}
vector<vector<int>> fourSumBetter(vector<int>& nums, int target) {
    // tc - O(N^3)+ O(Log N) sc - O(N^2)
    int n = nums.size();
    sort(nums.begin(),nums.end());
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<int> hashset;
            for(int k=j+1;k<n;k++){
                int fourth = target-(nums[i]+nums[j]+nums[k]);
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int> arr = {nums[i],nums[j],nums[k],fourth};
                    st.insert(arr);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
     // tc - O(N^2 *M) = O(N^3) sc -O(1)
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> st;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1;
                int p = n-1;
                while(p>k){
                    long long sum = nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[p];
                    if(sum<target){
                        k++;
                    }else if(sum>target){
                        p--;
                    }else{
                        vector<int> arr = {nums[i],nums[j],nums[k],nums[p]};
                        st.push_back(arr);
                        k++;
                        p--;
                        while(p>k && nums[k-1]==nums[k]) k++;
                        while(p>k && nums[p+1]==nums[p]) p--;
                    }
                }
            }
        }
        return st;
    }

int maxLenBruteForce(vector<int>& arr) {
    // tc - O(N^2) sc - O(1)
    int n = arr.size();
    int startIndex;
    int endIndex;
    int longest =0;
    for(int i=0;i<n;i++){
        int sum=0;
        startIndex=i;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum==0){
                endIndex=j;
                int currentLength=(endIndex-startIndex) + 1;
                longest=max(longest,currentLength);
            }
        }
    }
    return longest;
}

int maxLen(vector<int>& arr) {
    // tc - O(N) , sc -O(N)
    int n = arr.size();
    int longest=0;
    map<int,int> mpp; // sum , index
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum==0){
            int startIndex = 0;
            int endIndex = i;
            int currentLength= (endIndex-startIndex) + 1;
            longest=max(longest,currentLength);
        }
        if(mpp.find(sum)!=mpp.end()){
            int startIndex = mpp[sum] + 1;
            int endIndex = i;
            int currentLength= (endIndex-startIndex) + 1;
            longest=max(longest,currentLength);
        }else{
            mpp[sum]=i;
        }
    }
    return longest;
}

int subarraysWithSumKBruteForce(vector < int > a, int b) {
    // tc - O(N^2) sc - O(1)
    int n = a.size();
    int ans=0;
    for(int i=0;i<n;i++){
        int value=0;
        for(int j=i;j<n;j++){
            value= value^a[j];
            if(value==b){
                ans++;
            }
        }
    }
    return ans;
}

int subarraysWithSumK(vector < int > a, int b) {
    // tc - O(N) sc - O(1)
    int n = a.size();
    int preSum=0;
    unordered_map<int,int> mpp; // sum(xor) , count
    mpp[0]=1;
    int ans=0;
    for(int i=0;i<n;i++){
        preSum= preSum^a[i];
        int rest = b^preSum;
        if(mpp.find(rest)!=mpp.end()){
            ans+=mpp[rest];
        }
        mpp[preSum]++;
      
    }
    return ans;
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}