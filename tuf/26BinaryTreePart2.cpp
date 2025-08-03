


// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
vector<int> topView(Node *root) {
            // code here
            queue<pair<Node*,int>> q;
            q.push({root,0});
            map<int,int> ans;
            
            while(!q.empty()){
                int n = q.size();
                for(int i=0;i<n;i++){
                    Node* mover = q.front().first;
                    int line = q.front().second;
                    if(ans.find(line)==ans.end()){
                        ans[line]=mover->data;
                    }
                    q.pop();
                    if(mover->left) q.push({mover->left,line-1});
                    if(mover->right) q.push({mover->right,line+1});
                    
                }
                
            }
            vector<int> rans;
            for(auto it : ans){
                rans.push_back(it.second);
            }
            return rans;
        }
https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
vector<int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>> q;
        q.push({root,0});
        map<int,int> ans;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* mover = q.front().first;
                int line = q.front().second;
                q.pop();
                ans[line]=mover->data;
                if(mover->left) q.push({mover->left,line-1});
                if(mover->right) q.push({mover->right,line+1});
            }
        }
        
        vector<int> nans;
        for(auto it : ans){
            nans.push_back(it.second);
        }
        return nans;
    }
// https://leetcode.com/problems/binary-tree-paths/
    void ans(TreeNode* root,vector<string>& ansv,string path){
        if(!root) return;
        string val = to_string(root->val);
        if(path.length()==0) path+=val;
        else path+= "->" + val;
        if(!root->left && !root->right) ansv.push_back(path);
        ans(root->left,ansv,path);
        ans(root->right,ansv,path);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ansv;
        string path = "";
        ans(root,ansv,path);
        return ansv;
    }

//  Children Sum Property
bool isParentSum(Node *root){
    if(!root) return true;
    if(!root->left && !root->right) return true;
    int val = 0;
    if(root->left) val+=root->left->data;
    if(root->right) val+=root->right->data;
    if(root->data!=val) return false;
    return isParentSum(root->left) && isParentSum(root->right);
}