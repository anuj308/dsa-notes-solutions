// https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
int height(Node* root) {
    // code here
    if(!root) return 0;
    if(!root->left && !root->right) return 0;
    return max(height(root->left),height(root->right)) + 1;
}

int height(Node* root) {
    // code here
    if(!root) return -1;
    return max(height(root->left),height(root->right)) + 1;
}