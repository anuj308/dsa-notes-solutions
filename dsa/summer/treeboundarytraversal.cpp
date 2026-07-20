
// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

// Tc - O(n) , sc-O(n)
void inOrder(Node* root,vector<int>& ans){
    if(!root) return;
    inOrder(root->left,ans);
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    inOrder(root->right,ans);
}
vector<int> boundaryTraversal(Node *root) {
    // code here
    vector<int> ans;

    // root
    if(!(root->left==NULL && root->right==NULL)) 
        ans.push_back(root->data);
        
    Node* temp = root->left;
    while(temp){
        if(!(temp->left==NULL && temp->right==NULL)){
            ans.push_back(temp->data);
        }
        
        if(temp->left) temp=temp->left;
        else temp=temp->right;
    }
    
    temp = root;
    
    inOrder(root,ans);
    
    stack<int> st;
    temp=root->right;
    while(temp){
        if(!(temp->left==NULL && temp->right==NULL))
            st.push(temp->data);
        if(temp->right) temp=temp->right;
        else temp=temp->left;
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}