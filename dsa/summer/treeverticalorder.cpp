//  https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

// tc - O(nlogn), sc- O(n)

vector<vector<int>> verticalOrder(Node *root) {
    // code here
    
    map<int,vector<int>> mpp;
    queue<pair<int,Node*>> q;
    q.push({0,root});
    while(!q.empty()){
        int nq = q.size();
        for(int i=0;i<nq;i++){
            int level = q.front().first;
            Node* temp = q.front().second;
            q.pop();
            mpp[level].push_back(temp->data);
            if(temp->left) q.push({level-1,temp->left});
            if(temp->right) q.push({level+1,temp->right});
        }
    }
    vector<vector<int>> ans;
    for(auto it : mpp) ans.push_back(it.second);
    return ans;
}