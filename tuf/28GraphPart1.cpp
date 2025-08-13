// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
vector<int> bfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> ans;
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();
        ans.push_back(tmp);
        for (auto it : adj[tmp])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }
    return ans;
}

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
void dfss(vector<vector<int>> &adj, int node, vector<int> &ans, vector<int> &vis)
{
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            vis[it] = 1;
            ans.push_back(it);
            dfss(adj, it, ans, vis);
        }
    }
    return;
}
vector<int> dfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    vector<int> ans;
    vis[0] = 1;
    ans.push_back(0);
    dfss(adj, 0, ans, vis);

    return ans;
}

// https://leetcode.com/problems/number-of-provinces/
void dfs(vector<vector<int>> &isConnected, vector<int> &vis, int node, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (isConnected[node - 1][i] == 1 && !vis[i + 1])
        {
            vis[i + 1] = 1;
            dfs(isConnected, vis, i + 1, n);
        }
    }
    return;
} // Tc- O(N^2) , Sc-O(n)
int findCircleNum(vector<vector<int>> &isConnected)
{
    int ans = 0;
    int n = isConnected.size(); // no of cities
    vector<int> vis(n + 1, 0);  // 1 based

    for (int i = 0; i < n; i++)
    { // all nodes
        if (!vis[i + 1])
        {
            vis[i + 1] = 1;
            dfs(isConnected, vis, i + 1, n);
            ans++;
        }
    }
    return ans;
}

// https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
void dfs(int vertex, vector<int> adj[], vector<int> &vis, vector<int> &temp)
{
    for (auto v : adj[vertex])
    {
        if (!vis[v])
        {
            vis[v] = 1;
            temp.push_back(v);
            dfs(v, adj, vis, temp);
        }
    }
    return;
}
vector<vector<int>> getComponents(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    vector<vector<int>> ans;
    vector<int> vis(V, 0);
    for (int v = 0; v < V; v++)
    {
        if (!vis[v])
        {
            vector<int> temp;
            temp.push_back(v);
            vis[v] = 1;
            dfs(v, adj, vis, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}

//https://leetcode.com/problems/count-the-number-of-complete-components/
// found it while searching for other
void dfs(int node, vector<int> &vis, vector<int> adj[], int &ne, int &nn)
{
    for (auto v : adj[node])
    {
        ne++;
        if (!vis[v])
        {
            nn++;
            vis[v] = 1;
            dfs(v, vis, adj, ne, nn);
        }
    }
    return;
}
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    vector<int> vis(n, 0);
    vector<int> adj[n];
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    int ans = 0;
    for (int v = 0; v < n; v++)
    {
        if (!vis[v])
        {
            vis[v] = 1;
            int ne = 0; // no of edges
            int nn = 1; // no of nodes
            dfs(v, vis, adj, ne, nn);
            ne /= 2; // as counted from every node
            if (ne == (nn * (nn - 1) / 2))
                ans++;
        }
    }
    return ans;
}


// https://leetcode.com/problems/rotting-oranges/description/