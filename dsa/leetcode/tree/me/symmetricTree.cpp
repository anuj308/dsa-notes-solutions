// https://leetcode.com/problems/symmetric-tree/submissions/1458186665/?envType=problem-list-v2&envId=depth-first-search

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
    void check(TreeNode* rootleft,TreeNode* rootright, bool &ans){
        if(!rootleft && !rootright){
            return;
        }
        if(!rootleft || !rootright){
            ans = 0;
            return;
        }
        if(rootleft->val != rootright->val){
            ans = 0;
            return;
        }
        check(rootleft->left,rootright->right,ans);
        check(rootleft->right,rootright->left,ans);
    }
    bool isSymmetric(TreeNode* root) {
        bool ans = 1;
        check(root->left,root->right,ans);
        return ans;
    }
};