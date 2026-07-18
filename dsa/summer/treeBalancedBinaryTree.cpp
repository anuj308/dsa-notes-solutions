// https://leetcode.com/problems/balanced-binary-tree/description/
// Tc - O(n), Sc-O(n) used to run the algo - auxiliary space

int height(TreeNode* root){
    if(!root) return -1;
    int left = height(root->left);
    int right = height(root->right);
    if(left==-2 || right==-2) return -2;
    if(abs(right-left)>1) return -2;
    return max(left,right)+1;
}
bool isBalanced(TreeNode* root) {
    if(!root) return true;
    if(height(root)==(-2)) return false;

    return true;
}