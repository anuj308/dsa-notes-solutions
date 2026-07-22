// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

bool search(TreeNode* root,int rem,TreeNode* currNode){
    while(root){
        if(root!=currNode && root->val==rem) return true;
        if(root->val<rem) root=root->right;
        else root=root->left;
    }
    return false;
}
bool ans(TreeNode* root,int k,TreeNode* currNode){
    if(!currNode) return false;
    if(search(root,k-currNode->val,currNode)) return true;
    return ans(root,k,currNode->left) || ans(root,k,currNode->right);
}
bool findTarget(TreeNode* root, int k) {
    return ans(root,k,root);
    }