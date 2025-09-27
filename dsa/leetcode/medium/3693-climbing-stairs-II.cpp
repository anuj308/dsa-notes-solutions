
//  problem link :- https://leetcode.com/problems/climbing-stairs-ii/description/
//  name := 3693. Climbing Stairs II
//  dificulty : - medium
//  with dijiksta algo
// Tc- O(nlogn) . Sc-O(n)
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        queue<pair<int,int>> q;
        vector<int> dis(n+1,INT_MAX);
        dis[0]=0;
        q.push({0,0});
        while(!q.empty()){
            int cost = q.front().first;
            int node = q.front().second;
            q.pop();
            for(int i=1;i<=3;i++){
                if(node+i>n) break;
                int nextCost = costs[node+i-1] + (i)*(i) + dis[node];
                if(nextCost<dis[node+i]){
                    dis[node+i]=nextCost;
                    q.push({nextCost,node+i});
                }
            }
        }
        return dis[n];
    }
};