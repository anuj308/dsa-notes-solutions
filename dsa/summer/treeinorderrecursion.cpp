void inFunc(Node* root,vector<int>& ans){
    if(!root) return;
    inFunc(root->left,ans);
    ans.push_back(root->data);
    inFunc(root->right,ans);
}
vector<int> inOrder(Node* root) {
    // code here
    if(!root) return {};
    vector<int> ans;
    inFunc(root,ans);
    return ans;
}

// https://www.geeksforgeeks.org/problems/inorder-traversal/1