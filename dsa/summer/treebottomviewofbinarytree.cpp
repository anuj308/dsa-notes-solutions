// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

// Tc - O(n log n) sc -O(n)
vector<int> bottomView(Node *root) {
    // code here
    map<int,int> mpp;
    
    queue<pair<int,Node*>> q;
    q.push({0,root});
    while(!q.empty()){
        int nq = q.size();
        for(int i=0;i<nq;i++){
            int level = q.front().first;
            Node* temp = q.front().second;
            q.pop();
            mpp[level]=temp->data;
            if(temp->left) q.push({level-1,temp->left});
            if(temp->right) q.push({level+1,temp->right});
        }
    }
    vector<int> ans;
    for(auto it : mpp) ans.push_back(it.second);
    return ans;
}