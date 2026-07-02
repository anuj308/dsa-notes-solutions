// https://leetcode.com/problems/jump-game/

#include <bits/stdc++.h>
using namespace std;

// greedy , tc - O(n) , sc- O(1)

// nums = [2,3,1,1,4]
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    for(int i=0;i<n;i++){
        if(i > maxReach) return false;
        maxReach = max(maxReach,nums[i]+i);
        if(maxReach >= n-1) return true;
    }

    return false;
}

// dp top down

// Tc - o(n^2), sc - O(n)
bool canJump(vector<int>& nums) {
    int n = nums.size();
    
    vector<bool> dp(n,false);
    dp[n-1]=true;
    for(int i=n-2;i>=0;i--){
        int maxReach = nums[i]+i;
        for(int j=min(n-1,maxReach);j>i;j--){
            if(dp[j]){
                dp[i]=true;
                break;
            }
        }
    }

    return false;
}

int main(){


    return 0;
}