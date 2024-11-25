// https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=problem-list-v2&envId=depth-first-search
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void ans(TreeNode* root)
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};

// class Solution {
//   public:
//     void dfs(int node,vector<vector <int>> &adj, int vis[]){
//         vis[node] = 1;
//         for(auto it : adj[node]){
//             if(!vis[it]){
//                 dfs(it,adj,vis);
//             }
//         }
        
//     }
//     int numProvinces(vector<vector<int>> adj, int V) {
//         int vis[n+1] = {0};
        
//         for(auto it : vis){
//             if(!vis[it]){
//                 dfs(it,adj,vis);
//             }
//         }
//     }
// };