
// https://www.geeksforgeeks.org/problems/preorder-traversal/1
void preFunc(Node* root,vector<int>& ans){
        
    if(!root) return;
    ans.push_back(root->data);
    preFunc(root->left,ans);
    preFunc(root->right,ans);
}
vector<int> preOrder(Node* root) {
    // code here
    vector<int> ans;
    
    preFunc(root,ans);
    
    return ans;
}