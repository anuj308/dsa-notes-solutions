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
// https://leetcode.com/problems/01-matrix/
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q; // row,col,steps
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int nq = q.size();
        for (int i = 0; i < nq; i++)
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dis[row][col] = step;
            vector<vector<int>> dir = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};
            for (auto it : dir)
            {
                int nrow = row + it[0];
                int ncol = col + it[1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, step + 1});
                }
            }
        }
    }
    return dis;
}
// https://leetcode.com/problems/surrounded-regions/
// https://leetcode.com/problems/surrounded-regions/solutions/7080118/c-bfs-tc-o3n-by-anuj308-ipfw
// Tc-O(3n), Sc-O(n)
void solve(vector<vector<char>> &board)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i >= 1 && i < n - 1) && (j >= 1 && j < m - 1))
                continue;
            if (board[i][j] == 'O')
            {
                vis[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        int nq = q.size();
        for (int i = 0; i < nq; i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<vector<int>> dir = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
            for (auto it : dir)
            {
                int nrow = row + it[0];
                int ncol = col + it[1];
                if (nrow >= 1 && nrow < n - 1 && ncol >= 1 && ncol < m - 1 && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (board[i][j] == 'O' && !vis[i][j])
            {
                board[i][j] = 'X';
            }
        }
    }
}

// https://leetcode.com/problems/number-of-enclaves/
// same as above pattern
int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0)); // 1 - can walk of to boundary
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
        if (grid[0][i] == 1)
        {
            q.push({0, i});
            vis[0][i] = 1;
        } // top line
    for (int i = 0; i < m; i++)
        if (grid[n - 1][i] == 1)
        {
            q.push({n - 1, i});
            vis[n - 1][i] = 1;
        } // bottom line
    for (int i = 0; i < n; i++)
        if (grid[i][0] == 1)
        {
            q.push({i, 0});
            vis[i][0] = 1;
        } // left side line
    for (int i = 0; i < n; i++)
        if (grid[i][m - 1] == 1)
        {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        } // right side line
    while (!q.empty())
    {
        int nq = q.size();
        for (int i = 0; i < nq; i++)
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<vector<int>> direct = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
            for (auto it : direct)
            {
                int nrow = row + it[0];
                int ncol = col + it[1];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    } // till now we marked all land(1) which are connected to boundary
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
                ans++;
        }
    }
    return ans;
}
// https://leetcode.com/problems/word-ladder/
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int n = wordList.size();
    int nw = beginWord.length();
    unordered_set<string> words(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty())
    {
        int nq = q.size();
        for (int i = 0; i < nq; i++)
        {
            string w = q.front().first;
            int step = q.front().second;
            if (w == endWord)
                return step;
            q.pop();
            words.erase(w);
            for (int a = 0; a < nw; a++)
            {
                string wor = w;
                for (char d = 'a'; d <= 'z'; d++)
                {
                    wor[a] = d;
                    if (words.count(wor))
                        q.push({wor, step + 1});
                }
            }
        }
    }
    return 0;
}