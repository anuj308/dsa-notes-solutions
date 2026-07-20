// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

vector<int> zigZagTraversal(Node* root) {
    // code here
    vector<int> ans;
    int d = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int nq = q.size();
        vector<int> tvec;
        for(int i=0;i<nq;i++){
            Node* temp = q.front();
            q.pop();
            tvec.push_back(temp->data);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(d==1) reverse(tvec.begin(),tvec.end());
        if(d==0) d=1;
        else d=0;
        ans.insert(ans.end(),tvec.begin(),tvec.end());
    }
    return ans;
}

// Tc - O(n) , sc - O(n)

vector<int> zigZagTraversal(Node* root) {
    // code here
    vector<int> ans;
    int d = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int nq = q.size();
        vector<int> tvec(nq);
        for(int i=0;i<nq;i++){
            Node* temp = q.front();
            q.pop();
            int idx = d==1 ? (sz-1-i) : i;
            tvec[idx]=temp->data;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(d==0) d=1;
        else d=0;
        ans.insert(ans.end(),tvec.begin(),tvec.end());
    }
    return ans;
}