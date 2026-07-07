// https://leetcode.com/problems/house-robber-ii/

int robHouse(vector<int>& nums,int s,int e){
    int n = e-s+1;
    if(n==0) return 0;
    if(n==1) return nums[s];
    vector<int> dp(e+1,0);
    dp[s]=nums[s];
    dp[s+1]=max(nums[s],nums[s+1]);
    for(int i=max(s,2);i<=e;i++){
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
    }
    return dp[e];
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    return max(robHouse(nums,0,n-2),robHouse(nums,1,n-1));
}