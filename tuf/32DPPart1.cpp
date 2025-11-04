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
