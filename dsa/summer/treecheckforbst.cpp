// https://www.geeksforgeeks.org/problems/check-for-bst/1


bool ans(Node* root, int low,int high){
    if(!root) return true;
    if(root->data<=low || root->data>=high) return false;
    return ans(root->left,low,root->data) && ans(root->right,root->data,high);
}
bool isBST(Node* root) {
    // code here
    
    return ans(root,INT_MIN,INT_MAX);
}