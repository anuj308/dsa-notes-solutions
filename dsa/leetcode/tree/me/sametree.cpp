// https://leetcode.com/problems/same-tree/submissions/1458176718/?envType=problem-list-v2&envId=depth-first-search

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
    void check(TreeNode* p,TreeNode* q,bool &ans){
        if(!p && !q){
            return;
        }
        if(!p || !q){
            ans = 0;
            return;
        }
        if(p->val != q->val){
            ans = 0;
            return;
        }
        check(p->left,q->left,ans);
        check(p->right,q->right,ans);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans = 1;
        check(p,q,ans);
        return ans;
    }
};