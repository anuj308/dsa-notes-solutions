// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// tc - O(nlogn) , sc- O(n)

vector<int> topView(Node *root) {
    
    map<int,int> mpp;
    queue<pair<int,Node*>> q;
    q.push({0,root});
    while(!q.empty()){
        int nq = q.size();
        for(int i=0;i<nq;i++){
            int level = q.front().first;
            Node* temp = q.front().second;
            q.pop();
            if(mpp.find(level)==mpp.end()){
                mpp[level]=temp->data;
            }
            if(temp->left) q.push({level-1,temp->left});
            if(temp->right) q.push({level+1,temp->right});
        }
    }
    vector<int> ans;
    for(auto it : mpp) ans.push_back(it.second);
    return ans;
}