// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// tc - O(n) , Sc- O(n)
vector<int> rightView(Node *root) {
    //  code here
    vector<int> ans;
    if(!root) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int nq = q.size();
        for(int i=0;i<nq;i++){
            Node* temp = q.front();
            q.pop();
            if(i==(nq-1)) ans.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
    return ans;
}