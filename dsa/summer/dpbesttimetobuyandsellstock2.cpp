// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// tc - O(2^n), sc-O(1)
// recursion
int findAns(int idx,int buy,vector<int>& prices){
    if(idx==prices.size()) return 0;
    if(buy==1){
        int by=-prices[idx]+findAns(idx+1,0,prices);
        int notby=findAns(idx+1,1,prices);
        return max(by,notby);
    }else{
        int sell=prices[idx]+findAns(idx+1,1,prices);
        int notsell=findAns(idx+1,0,prices);
        return max(sell,notsell);
    }
}
int maxProfit(vector<int>& prices) {
    
    return findAns(0,1,prices);
}


// tc - O(n), sc-O(1)
// memorization
int findAns(int idx,int buy,vector<int>& prices,vector<vector<int>>& dp){
    if(idx==prices.size()) return 0;
    if(dp[idx][buy]!=-1) return dp[idx][buy];
    if(buy==1){
        int by=-prices[idx]+findAns(idx+1,0,prices,dp);
        int notby=findAns(idx+1,1,prices,dp);
        return dp[idx][buy]=max(by,notby);
    }else{
        int sell=prices[idx]+findAns(idx+1,1,prices,dp);
        int notsell=findAns(idx+1,0,prices,dp);
        return dp[idx][buy]=max(sell,notsell);
    }
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return findAns(0,1,prices,dp);
}

// tabulation
// tc - O(n*2), sc- O(n*2)

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<2;buy++){
            if(buy==1){
                int by = -prices[idx]+dp[idx+1][0];
                int notby=dp[idx+1][1];
                dp[idx][buy]=max(by,notby);
            }
            else{
                int sell = prices[idx]+dp[idx+1][1];
                int notsell= dp[idx+1][0];
                dp[idx][buy]=max(sell,notsell);
            }
        }
    }
    return dp[0][1];
}

// space optimise
// tc - O(n*2), sc- O(1)

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2,0);
    vector<int> curr(2,0);
    for(int idx=n-1;idx>=0;idx--){
        for(int buy=0;buy<2;buy++){
            if(buy==1){
                int by = -prices[idx]+ahead[0];
                int notby=ahead[1];
                curr[buy]=max(by,notby);
            }
            else{
                int sell = prices[idx]+ahead[1];
                int notsell= ahead[0];
                curr[buy]=max(sell,notsell);
            }
        }
        ahead=curr;
    }
    return ahead[1];
}