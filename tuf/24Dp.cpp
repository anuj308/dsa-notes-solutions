// 70 climbing stairs
class Solution { // TLE
public:
    int dfs(int c,int n){
        if(c==n) return 1;
        if(c>n) return 0;
        int ans =0;
        ans+=dfs(c+1,n);
        ans+=dfs(c+2,n);
        return ans;
    }
    int climbStairs(int n) {
        return dfs(0,n);
    }
};
// dp below by me 
class Solution {
public:
    int climbStairs(int n) {
        vector<vector<int>> dp(n+2,vector<int>(n+1,0));
        // i , j -> c,n
        for(int i=n+1;i>=0;i--){
            for(int j=0;j<n+1;j++){
                if(i==j) dp[i][j]=1;
                else if(i>j) dp[i][j]=0;
                else dp[i][j] = dp[i+1][n]+dp[i+2][n];
            }
        }
       
        return dp[0][n];
    }
};


// coin change
// 322 medium
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1,amount+1);
    dp[0]=0;
    for(int amt=1;amt<=amount;amt++){
        for(auto coin : coins){
            if(amt>=coin){
                dp[amt]=min(dp[amt],dp[amt-coin]+1);
            }
        }
    }
    if(dp[amount]==amount+1) return -1;
    return dp[amount];
}