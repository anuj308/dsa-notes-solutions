https://leetcode.com/problems/validate-binary-search-tree/

// optimise code
class Solution {
public:
bool valid(TreeNode* root,long min,long max){
if(root==NULL) return true;
if(!(root->val > min && root->val < max)) return false;
return valid(root->left,min,root->val) && valid(root->right,root->val,max);
}
bool isValidBST(TreeNode* root) {
return valid(root,LONG_MIN,LONG_MAX);
}
};



//  brute force below
class Solution {
public:
void ans(TreeNode* root,TreeNode*& prev, bool& flag){
if(root == NULL) return;
ans(root->left,prev,flag);

if(prev!=NULL){
if(prev->val>=root->val){
flag = false;
return;
}
}
prev = root;
ans(root->right,prev,flag);
}

bool isValidBST(TreeNode* root) {
TreeNode* prev = NULL;
bool flag = true;
ans(root,prev,flag);
return flag;
}
};