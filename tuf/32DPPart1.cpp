// dp
// overlapping sub problem - so we store the value of sub problem in map/table - memorization.

// void f(int n,vector<int>& dp){
//     if(n<=1) return n;

//     if(dp[n]!=-1) return dp[n];
//     return dp = f(n-1,dp) + f(n-2,dp);
// }
// int main(){
//     int n = 4;
//     vector<int> dp(n+1,-1);
//     cout << f(n,dp) << endl; 
//     return 0;
// }

// Tabulation is a ‘bottom-up’ approach where we start from the base case and reach the final answer that we want.

// Steps to convert Recursive Solution to Tabulation one.

// Declare a dp[] array of size n+1.
// First initialize the base condition values, i.e i=0 and i=1 of the dp array as 0 and 1 respectively.
// Set an iterative loop that traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2]. 


//   int n=5;
//   vector<int> dp(n+1,-1);
  
//   dp[0]= 0;
//   dp[1]= 1;
  
//   for(int i=2; i<=n; i++){
//       dp[i] = dp[i-1]+ dp[i-2];
//   }
//   cout<<dp[n];
// int n=5;
  
//   int prev2 = 0;
//   int prev = 1;
  
//   for(int i=2; i<=n; i++){
//       int cur_i = prev2+ prev;
//       prev2 = prev;
//       prev= cur_i;
//   }
//   cout<<prev;

// understand a dp problem
// count the total number of ways, min,max, try all possiable ways
// first recursion then dp

// shortcut
// 1) try to represent the problem in terms of index
// 2) do all possiable stuffs on that end in according to problem
// 3) sum of all stuffs -> count all ways, min (of all the suffs) ->find min

// 1D dp
// recursion to dp - memorization(top down) - store sub problems - tabulation(bottom up)

// memorization(top down)
class Solution {
  public:
    int f(vector<int>& height,int i){
        if(i==0) return 0;
        
        int left = f(height,i-1) + abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(i>1) right = f(height,i-2) + abs(height[i]-height[i-2]);
        return min(left,right);
    }
    int minCost(vector<int>& height) {
        int n = height.size();
        
        return f(height,n-1);
    }
};

//  store sub problems 
class Solution {
  public:
    int f(vector<int>& height,int i,vector<int>& dp){
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int left = f(height,i-1,dp) + abs(height[i]-height[i-1]);
        int right = INT_MAX;
        if(i>1) right = f(height,i-2,dp) + abs(height[i]-height[i-2]);
        return dp[i] = min(left,right);
    }
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n,-1);
        return f(height,n-1,dp);
    }
};

// tabulation(bottom up)
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n,-1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int one = INT_MAX;
            int two = INT_MAX;
            if(i>=1) one = dp[i-1] + abs(height[i]-height[i-1]);
            if(i>=2) two = dp[i-2] + abs(height[i]-height[i-2]);
            dp[i]=min(one,two);
        }
        return dp[n-1];
    }
};

// space optimization 
class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        int prev = 0;
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int one = INT_MAX;
            int two = INT_MAX;
            if(i>=1) one = prev + abs(height[i]-height[i-1]);
            if(i>=2) two = prev2 + abs(height[i]-height[i-2]);
            int cur =min(one,two);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};