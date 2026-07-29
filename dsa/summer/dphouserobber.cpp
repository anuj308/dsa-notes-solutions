// https://leetcode.com/problems/house-robber/

// recursion
// tc - O(2^n) , sc - O(n)

int finAns(int idx,vector<int>& nums){
    if(idx<0) return 0;
    int rob = nums[idx]+finAns(n-2);
    int notrob = finAns(n-1);
    return max(rob,notrob);
}

int rob(vector<int>& nums) {
    int n = nums.size();    
    return finAns(n-1,nums);
}

// -------------------------------
// memorise
// tc - O(n) , sc- O(n) + recursion call stack
int finAns(int idx,vector<int>& nums,vector<int>& dp){
    if(idx<0) return 0;
    if(dp[idx]!=-1) return dp[idx];
    int rob = nums[idx]+finAns(n-2);
    int notrob = finAns(n-1);
    return dp[idx] = max(rob,notrob);
}

int rob(vector<int>& nums) {
    int n = nums.size();  
    vector<int> dp(n,-1);  
    return finAns(n-1,nums,dp);
}

// -----------------------
// tabulation
// tc - O(n) , sc- O(n)

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return 0;
    if(n==1) return nums[0];
    vector<int> dp(n,0);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[n-1];
}

// ------------------------
// tc - O(n) , sc- O(n)

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        int rob = nums[i];
        int notrob = 0;
        if(i-2>=0) rob+=dp[i-2];
        if(i-1>=0) notrob+=dp[i-1];

        dp[i] = max(rob,notrob);
    }
    return dp[n-1];
}

//  -----------------------
// space optimise
// tc - O(n) , sc- O(1)

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    int slast = nums[0];
    int last = max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
        int rob = nums[i] + slast;
        int notrob = last;

        int curr =  max(rob,notrob);
        slast = last;
        last = curr;
    }
    return last;
    }