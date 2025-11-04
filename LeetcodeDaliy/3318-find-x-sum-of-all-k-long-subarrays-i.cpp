
// date :- 2025-11-04
// link :-https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/
// TYPE:- easy
// name :- 3318. Find X-Sum of All K-Long Subarrays I

// Tc- o(n^2)
// C++
class Solution {
public:
    bool static cmp(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second > b.second;
        return a.first > b.first;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<=n-k;i++){
            map<int,int> mpp;
            for(int j=i;j<i+k;j++){
                mpp[nums[j]]++;
            }
            vector<pair<int,int>> mp;
            for(auto it : mpp){
                mp.push_back({it.second,it.first});
            }
            sort(mp.begin(),mp.end(),cmp);
            int p=0;
            int value = 0;
            int nm = mp.size();
            int k = 0;
            while(k<nm && k<x){
                value+=mp[k].first*mp[k].second;
                k++;
            }
            ans.push_back(value);
        }
        return ans;
    }
};

// java
