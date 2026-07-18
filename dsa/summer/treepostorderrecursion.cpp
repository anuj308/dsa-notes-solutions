

// https://www.geeksforgeeks.org/problems/postorder-traversal/1
void postFunc(Node* root,vector<int>& ans){
    if(!root) return;
    postFunc(root->left,ans);
    postFunc(root->right,ans);
    ans.push_back(root->data);
}
vector<int> postOrder(Node* root) {
    // code here
    vector<int> ans;
    postFunc(root,ans);
    return ans;
}