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

// https://leetcode.com/problems/count-the-number-of-complete-components/
//  found it while searching for other
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
int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    int freshOranges = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
                freshOranges++;
            if (grid[i][j] == 2)
                q.push({i, j});
        }
    }
    if (freshOranges == 0)
        return 0;
    while (!q.empty())
    { // contain rotten oranges
        int nq = q.size();
        for (int i = 0; i < nq; i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int x = -1; x <= 1; x++)
            { // in four direction oranges will rote
                int nrow = row + x;
                int ncol = col + x;
                if (nrow >= 0 && nrow < n && col >= 0 && col < m && grid[nrow][col] == 1)
                {
                    freshOranges--;
                    grid[nrow][col] = 2; // rotten
                    q.push({nrow, col});
                }
                if (row >= 0 && row < n && ncol >= 0 && ncol < m && grid[row][ncol] == 1)
                {
                    freshOranges--;
                    grid[row][ncol] = 2; // rotten
                    q.push({row, ncol});
                }
            }
        }
        ans++;
    }

    if (freshOranges != 0)
        return -1;
    return ans - 1;
}
// https://leetcode.com/problems/flood-fill/
void dfs(int row, int col, vector<vector<int>> &image, int &from, int &color, int &n, int &m)
{
    for (int x = -1; x <= 1; x++)
    {
        int nrow = row + x;
        int ncol = col + x;
        if (nrow >= 0 && nrow < n && col >= 0 && col < m && image[nrow][col] == from)
        {
            image[nrow][col] = color;
            dfs(nrow, col, image, from, color, n, m);
        }
        if (row >= 0 && row < n && ncol >= 0 && ncol < m && image[row][ncol] == from)
        {
            image[row][ncol] = color;
            dfs(row, ncol, image, from, color, n, m);
        }
    }
    return;
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    int from = image[sr][sc]; // change from to color
    if (from == color)
        return image;
    dfs(sr, sc, image, from, color, n, m);
    return image;
}

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
void dfs(bool &ans, int v, vector<int> adj[], vector<bool> &vis, int prev)
{
    for (auto vertex : adj[v])
    {
        if (!vis[vertex])
        {
            vis[vertex] = true;
            dfs(ans, vertex, adj, vis, v);
        }
        else if (vertex != prev)
        {
            ans = true;
            return;
        }
    }
}
bool isCycle(int V, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    vector<bool> vis(V, false);
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    bool ans = false;
    for (int v = 0; v < V; v++)
    {
        if (!vis[v])
        {
            vis[v] = true;
            dfs(ans, v, adj, vis, -1);
            if (ans)
                return ans;
        }
    }
    return ans;
}