// https://leetcode.com/problems/minimum-depth-of-binary-tree/?envType=problem-list-v2&envId=depth-first-search

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
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        if(!root->left){
            return minDepth(root->right) + 1;
        }
        if(!root->right){
            return minDepth(root->left) + 1;
        }
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return min(left , right) + 1;
    }
};