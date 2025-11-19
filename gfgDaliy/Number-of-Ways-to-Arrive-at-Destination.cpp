
// link: https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
// Difficulty: Medium
// date : 19-11-19

// Tc- O(E log V)
// sc - O(3n)
// c++
class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>> adj[V];
        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        minHeap.push({0,0}); // dis, node
        vector<int> dis(V,INT_MAX);
        vector<int> ways(V,0);
        ways[0]=1;
        dis[0]=0;
        unordered_map<int,int> ans;
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            int d = minHeap.top().first;
            
            minHeap.pop();
            if(d>dis[node]) continue;
            
            for(auto e : adj[node]){
                int v = e.first;
                int w = e.second;
                int nxtDis = dis[node]+w;
                if(dis[v]>nxtDis){
                    dis[v]=nxtDis;
                    ways[v]=ways[node];
                    minHeap.push({nxtDis,v});
                }else if(nxtDis==dis[v]){
                    ways[v]+=ways[node];
                }
            }
        }
        return ways[V-1];
    }
};