
// Problem: shortest-path-in-undirected-graph-having-unit-distance ()
// URL: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class Solution {
    public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<int> ans(n,INT_MAX); // dis
        vector<bool> vis(n,false);
        queue<int> q; // node , distance
        ans[src]=0;
        vis[src]=true;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto e : adj[node]){
                if(!vis[e]){
                    ans[e]=ans[node]+1;
                    vis[e]=true;
                    q.push(e);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX) ans[i]=-1;
        }
        return ans;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================




// Problem: shortest-path-in-undirected-graph ()
// URL: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(n), SC: O(n)
class Solution {
    public:
    void topoSort(int node,vector<vector<pair<int,int>>>& adj,vector<bool>& vis,stack<int>& st){
        vis[node]=true;
        for(auto e : adj[node]){
            if(!vis[e.first]){
                topoSort(e.first,adj,vis,st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V); //V
        for(auto e : edges){
            //   u               v     edges weight
            adj[e[0]].push_back({e[1],e[2]});
        }
        // topp sort
        vector<bool> vis(V,false);
        stack<int> st;
        for(int i=0;i<V;i++){ // O(V+E)
            if(!vis[i]){
                topoSort(i,adj,vis,st); 
            }
        }
        
        //  take node from stack and update the distance
        vector<int> dis(V,INT_MAX);
        dis[0]=0;
        while(!st.empty()){ // O(V+E)
            int node = st.top();
            st.pop();
            if(dis[node]!=INT_MAX){
                for(auto e : adj[node]){
                    dis[e.first]=min(dis[e.first],dis[node]+e.second);
                }
            }
        }
        for(int i=0;i<V;i++){ //V
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================





// Problem: implementing-dijkstra-set-1-adjacency-matrix ()
// URL: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O((V+E) log V), SC: O(2n)

// not work in negative weight and negative cycle
// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        minHeap.push({0,src});
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            int dis = minHeap.top().first;
            minHeap.pop();
            for(auto e : adj[node]){
                int edgeWeight = e.second;
                int edgeNode = e.first;
                if(dist[node]+edgeWeight<dist[edgeNode]){
                    dist[edgeNode]= dist[node]+edgeWeight;
                    minHeap.push({dist[edgeNode],edgeNode});
                }
            }
        }
        return dist;
    }
};

//  by using set we can erase path with more distance in set for node which we get a shorter path so
// save Tc by not doing more iteration, but Tc is not more than proirity queue as earse take logarithm Tc
// by using queue we will travel all paths but by being greedy we can choose the minium path so we can save lot of travel
// which might happen from by going with not minimum path first.

// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto e : edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        set<pair<int,int>> s;
        vector<int> dist(V,INT_MAX);
        dist[src]=0;
        s.insert({0,src});
        while(!s.empty()){
            auto it = *(s.begin());
            int node = it.second;
            int dis = it.first;
            s.erase(it);
            for(auto e : adj[node]){
                int edgeWeight = e.second;
                int adjNode = e.first;
                if(dist[node]+edgeWeight<dist[adjNode]){
                    if(dist[adjNode]!=INT_MAX){
                        s.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]= dist[node]+edgeWeight;
                    s.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
    // ==================== Java SOLUTION ====================
    // ==================== Python SOLUTION ====================

// Problem: shortest-path-in-binary-matrix (1091)
// URL: https://leetcode.com/problems/shortest-path-in-binary-matrix/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(N^2 log n), SC: O(n^2)
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        int n = grid.size(); 
        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        dis[0][0]=1;
        minHeap.push({1,{0,0}});
        while(!minHeap.empty()){
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            int d = minHeap.top().first;
            minHeap.pop();
            vector<pair<int,int>> direction = {{1,0},{-1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
            for(int i=0;i<8;i++){
                int nrow = row + direction[i].first;
                int ncol = col + direction[i].second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 && d+1<dis[nrow][ncol]){
                    dis[nrow][ncol]=d+1;
                    minHeap.push({d+1,{nrow,ncol}});
                }
            }
        }
        if(dis[n-1][n-1]==INT_MAX) return -1;
        return dis[n-1][n-1];
    }
};
// ==================== Java SOLUTION ====================
    // ==================== Python SOLUTION ====================

// Problem: part with minumum effort (1631)
// URL: https://leetcode.com/problems/path-with-minimum-effort/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(E log v), SC: O(n^2)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        dis[0][0]=0;
        minHeap.push({0,{0,0}});
        while(!minHeap.empty()){
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            int d = minHeap.top().first;
            minHeap.pop();
            vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto dir : direction){
                int nrow = row + dir.first;
                int ncol = col + dir.second;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int diff = abs(heights[row][col]-heights[nrow][ncol]);
                    if(max(d,diff)<dis[nrow][ncol]){
                        dis[nrow][ncol]=max(d,diff);
                        minHeap.push({max(d,diff),{nrow,ncol}});
                    }
                }
            } 
        }

        return dis[n-1][m-1];
    }
};
// ==================== Java SOLUTION ====================
    // ==================== Python SOLUTION ====================





// Problem: cheapest-flights-within-k-stops (787)
// URL: https://leetcode.com/problems/cheapest-flights-within-k-stops/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(N), SC: O(n)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        dis[src]=0;
        q.push({0,{src,k}});
        while(!q.empty()){
            int price = q.front().first;
            int currNode = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();
            for(auto a : adj[currNode]){
                int node = a.first;
                int cost = a.second;
                if(stops>=0 && price+cost<dis[node]){
                    dis[node] = price+cost;
                    q.push({price+cost,{node,stops-1}});
                }
            }
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================

// Problem: netwrok delay time (743)
// URL: https://leetcode.com/problems/network-delay-time/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// TC: O(E log v), SC: O(n)
//  v is vertex = n
//  E is edges
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto t : times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        priority_queue<int,vector<int>,greater<int>> minHeap;
        dis[k]=0;
        minHeap.push(k);
        while(!minHeap.empty()){
            int currNode = minHeap.top();
            minHeap.pop(); // log n
            for(auto a : adj[currNode]){
                int node = a.first;
                int time = a.second;
                if(dis[currNode]+time<dis[node]){
                    dis[node]=dis[currNode]+time;
                    minHeap.push(node);
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};
// ==================== Java SOLUTION ====================
// ==================== Python SOLUTION ====================


// link:-  https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
// 1976. Number of Ways to Arrive at Destination
// c++
// Tc- O((V+E )log V)
class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &ed : roads){
            adj[ed[0]].push_back({ed[1],ed[2]});
            adj[ed[1]].push_back({ed[0],ed[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> minHeap;
        vector<long long> dis(n,LLONG_MAX);
        vector<long long> ways(n,0);
        dis[0]=0;
        ways[0]=1;
        minHeap.push({0,0});
        while(!minHeap.empty()){
            long long node = minHeap.top().second;
            long long d = minHeap.top().first;
            minHeap.pop();
            if(d!=dis[node]) continue;
            for(auto &[adjNode,time] : adj[node]){
                long long newDis = dis[node]+time;
                if(newDis<dis[adjNode]){
                    ways[adjNode]=ways[node];
                    dis[adjNode]=newDis;
                    minHeap.push({newDis,adjNode});
                }else if(newDis==dis[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])% mod;
                }
            }
        }
       
        return ways[n-1] % mod;
    }
};





// link:-  https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
// 1976. Minimum Multiplications to reach End
// c++
// Tc- O(100000*n)
// sc- O(100000)

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        int n = arr.size();
        queue<pair<int,int>> minHeap;
        vector<int> dis(100000,INT_MAX);
        minHeap.push({0,start});
        while(!minHeap.empty()){
            int steps = minHeap.front().first;
            int value = minHeap.front().second;
            minHeap.pop();
            for(auto v : arr){
                int newVal = (value*v) % 100000;
                if(steps+1<dis[newVal]){
                    if(newVal==end) return steps+1;
                    dis[newVal]=steps+1;
                    minHeap.push({steps+1,newVal});
                }
            }
        }
        return -1;
    }
};


//  bellman ford
// relax n-1 times

// Tc- O(v*E), Sc-O(V)

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dis(V,1e8);
        dis[src]=0;
        for(int i=0;i<V-1;i++){
            for(auto e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
                if(dis[u]!=1e8 && dis[u]+w<dis[v]){
                    dis[v]=dis[u]+w;
                }
            }
        }
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2]; 
            if(dis[u]!=1e8 && dis[u]+w<dis[v]){
               return {-1};
            }
        }
        return dis;
    }
};


// Floyd Warshal Algorithm
// link : -https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Difficulty: medium
//  tc - O(V^3), Sc-O(1)

//  C++
// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        for(int k=0;k<n;k++){ // all node
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){ 
                    // update distance for each cell from k node
                    if(dist[i][k]==1e8 || dist[k][j]==1e8) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
};


// link https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
// difficulty : medium
// name : 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

// Tc-O(N^2logN), SC-O(n+E)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> ans(n,0);
        for(int v=0;v<n;v++){
            vector<int> dis(n,INT_MAX);
            dis[v]=0;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
            q.push({0,v});
            while(!q.empty()){
                int node = q.top().second;
                int d = q.top().first;
                q.pop();
                for(auto t : adj[node]){
                    int a = t.first;
                    int b = t.second;
                    if(dis[node]+b <= distanceThreshold && dis[node]+b<dis[a]){
                        dis[a] = dis[node]+b;
                        q.push({dis[a],a});
                    }
                }
            }
            for(auto di : dis) if(di<=distanceThreshold) ans[v]++;
            ans[v]--;
        }
        int ans1 = INT_MAX;
        int city = 0;
        for(int i=0;i<n;i++){
            if(ans[i]<=ans1){
                ans1=ans[i];
                city = i;
            }
        }
        return city;
    }
};

// floyd warshall
//  Tc-O(n^3), Sc-O(N^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMatrix(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            adjMatrix[i][i]=0;
        }
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adjMatrix[u][v]=w;
            adjMatrix[v][u]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adjMatrix[i][k]==INT_MAX || adjMatrix[k][j]==INT_MAX) continue;
                    adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
                }
            }
        }
        int ans = INT_MAX;
        int city = INT_MAX;
        for(int i=0;i<n;i++){
            int c = 0;
            for(int j=0;j<n;j++){
                if(adjMatrix[i][j]<=distanceThreshold) c++;
            }
            c--;
            if(c<=city){
                city = c;
                ans = i;
            }
        }
        return ans;
    }
};

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
// Prim's Algorithm
// minimum spaning tree
// greedy - intuition
//  TC - O(E log E), Sc-O(V+E)
//  ElogE + E log E
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> vis(V,0);
        
        int sum = 0;
        minHeap.push({0,0});
        while(!minHeap.empty()){ //E
            auto it = minHeap.top(); 
            minHeap.pop(); // log E
            int wt = it.first;
            int node = it.second;
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            for(auto ed : adj[node]){  // E
                int adjNode = ed.first;
                int adjWt = ed.second;
                if(!vis[adjNode]){
                    minHeap.push({adjWt,adjNode}); // log E
                }
            }
        }
        return sum;
        
    }
};