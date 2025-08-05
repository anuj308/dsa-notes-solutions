


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


// https://www.geeksforgeeks.org/problems/burning-tree/1    
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

void graph(TreeNode* root,TreeNode* parent,unordered_map<int,vector<int>>& mpp){
        if(!root) return;
        vector<int> temp;
        if(mpp.find(root->val)==mpp.end()) mpp[root->val]=temp;
        if(parent!=NULL) mpp[root->val].push_back(parent->val);
        if(root->left) mpp[root->val].push_back(root->left->val);
        if(root->right) mpp[root->val].push_back(root->right->val);
        graph(root->left,root,mpp);
        graph(root->right,root,mpp);
    }
    int dfs(int node,int parent,unordered_map<int,vector<int>>& mpp){
        bool run = false;
        int t = 0;
        for(auto it : mpp[node]){
            if(it!=parent){
                run=true;
                t=max(t,dfs(it,node,mpp));
            }
        }
        if(run) return t+1;
        return t;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> mpp;
        graph(root,NULL,mpp);
        return dfs(start,INT_MAX,mpp);
    }

    // morris  inorder transversal 
     vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                // inorder predecessor
                TreeNode* ip = curr->left;
                while(ip->right!=NULL && ip->right!=curr){
                    ip=ip->right;
                }
                if(ip->right==NULL){
                    ip->right=curr;// created thread
                    curr=curr->left;
                }else{
                    ip->right=NULL; // delete thread
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }

    // preorder
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }else{
                TreeNode* pp = curr->left;
                while(pp->right!=NULL && pp->right!=curr){
                    pp=pp->right;
                }
                if(pp->right==NULL){
                    ans.push_back(curr->val);
                    pp->right=curr; // create thread
                    curr=curr->left;
                }else{
                    pp->right=NULL; // delete thread
                    curr=curr->right;
                }
            }
        }
        return ans;


    // https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
       if(root==NULL) return;
       flatten(root->right);
       flatten(root->left);

       root->left=NULL;
       root->right=nextRight;
       nextRight = root;
    }