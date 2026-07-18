// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// tc - O(n) , sc- O(n)
void reversePreOrder(Node* root,int level,vector<int>& ans){
    if(!root) return;
    if(ans.size()<level) ans.push_back(root->data);
    reversePreOrder(root->right,level+1,ans);
    reversePreOrder(root->left,level+1,ans);
}
vector<int> rightView(Node *root) {
    vector<int> ans;
    if(!root) return ans;
    
    reversePreOrder(root,1,ans);
    return ans;
}