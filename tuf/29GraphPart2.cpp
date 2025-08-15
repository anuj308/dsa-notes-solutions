

// Problem: Is Graph Biparite (785)
// URL: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium

// ==================== C++ SOLUTION ====================
// m is edges
// TC: O(n+m), SC: O(n)
bool dfs(int g, int toColored, vector<int> &col, vector<vector<int>> &graph)
{
    col[g] = toColored;
    if (toColored == 1)
        toColored = 2;
    else
        toColored = 1; // change color
    for (auto v : graph[g])
    {
        if (col[v] == 0)
        {
            if (!dfs(v, toColored, col, graph))
                return false;
        }
        else if (col[g] == col[v])
            return false;
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> col(n, 0);
    // 0 - not visited
    // 1 - color 1 visted
    // 2 - color 2 visited
    for (int g = 0; g < n; g++)
    {
        if (col[g] == 0)
        {
            if (!dfs(g, 1, col, graph))
                return false;
        }
    }
    return true;
}

/* ==================== PYTHON SOLUTION ====================
// m is edges
# TC: O(n+m), SC: O(n)
def dfs(self,g,toColored,col,graph):
        col[g]=toColored
        toColored = 2 if toColored==1 else 1
        for v in graph[g]:
            if col[v]==0:
                if not self.dfs(v,toColored,col,graph):
                    return False
            elif col[v]==col[g]:
                return False
        return True

def isBipartite(self, graph):
    n = len(graph)
    col = [0] * n
    # 0 not viisted, 1 - color 1, 2 - color 2
    for g in range(0,n):
        if col[g]==0:
            if not self.dfs(g,1,col,graph):
                return False
    return True
*/

/* ==================== JAVA SOLUTION ====================
class Solution {
    public boolean dfs(int g,int toColored,int[] col,int[][] graph){
        col[g]=toColored;
        toColored = (toColored==1) ? 2 : 1;
        for(int v : graph[g]){
            if(col[v]==0){
                if(!dfs(v,toColored,col,graph)) return false;
            }else if(col[g]==col[v]) return false;
        }
        return true;
    }
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] col = new int[n];
        for(int g=0;g<n;g++){
            if(col[g]==0){
                if(!dfs(g,1,col,graph)) return false;
            }
        }
        return true;
    }
}
*/