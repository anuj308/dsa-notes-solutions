// 144
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preOrderFunc(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preOrderFunc(root->left,ans);
        preOrderFunc(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preOrderFunc(root,v);
        return v;
    }
};
// 94
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inOrderFunc(TreeNode *root, vector<int>& ans){
        if(root == NULL) return;
        inOrderFunc(root->left,ans);
        ans.push_back(root->val);
        inOrderFunc(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inOrderFunc(root,v);

        return v;
    }
};

// 145
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void postOrderFunc(TreeNode* root,vector<int>& ans){
        if(root == NULL ) return;
        postOrderFunc(root->left,ans);
        postOrderFunc(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        postOrderFunc(root,v);
        return v;
    }
};

// 102
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        int i = 1;
        int c = 0;
        int n = 0;
        while(!q.empty()){
            TreeNode* mover = q.front();
            q.pop();
            if(mover->left!=NULL) q.push(mover->left);
            else n++;
            if(mover->right!=NULL) q.push(mover->right);
            else n++;
            c++;
            temp.push_back(mover->val);
            if(c==i){
                ans.push_back(temp);
                temp.clear();
                i=(2*c)-n;
                n=0;
                c=0;
            }
        }
        if(temp.size()!=0) ans.push_back(temp);
        return ans;
    }
};

// 104
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void ans(TreeNode* root)
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left,right) + 1;
    }
};

// 110
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        int left = height(root->left);
        int right = height(root->right);
        if(left==-1 || right==-1) return -1;
        if(abs(left-right)>1) return -1;
        return max(left,right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};

// 543
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dia(TreeNode* root,int &ans){
        if(!root) return 0;
        int left = dia(root->left,ans);
        int right = dia(root->right,ans);
        ans=max(ans,left+right);
        return max(left,right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int s = dia(root,ans);
        return ans;
    }
};

// 124
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int path(TreeNode* root,int& ans){
        if(!root) return 0;
        int left = path(root->left,ans);
        int right = path(root->right,ans);
        ans=max(ans,root->val);
        ans=max(ans,root->val+left);
        ans=max(ans,root->val+right);
        ans=max(ans,left+root->val+right);
        if(max(left,right)<0) return root->val;
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int s = path(root,ans);
        return ans;
    }
};

// 100
    class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
};

//103
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> temp;
        int n = 0;
        int c = 0;
        int l = 1;
        int i = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* mover = q.front();
            q.pop();
            if(mover->left!=NULL) q.push(mover->left);
            else n++;
            if(mover->right!=NULL) q.push(mover->right);
            else n++;
            temp.push_back(mover->val);
            c++;
            if(c==l){
                if(i%2!=0) reverse(temp.begin(),temp.end());
                i++;
                ans.push_back(temp);
                temp.clear();
                l=2*c-n;
                n = 0;
                c = 0;
            }
        }
        return ans;
    }
};

//987
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        if(p1.first==p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    }
    void func(TreeNode* root,int row,int col,map<int,vector<pair<int,int>>>& mpp){
        if(!root) return;
        if(mpp.find(col)==mpp.end()) mpp[col]={{row,root->val}};
        else mpp[col].push_back({row,root->val});
        func(root->left,row+1,col-1,mpp);
        func(root->right,row+1,col+1,mpp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,vector<pair<int,int>>> mpp; // col -> row,val
        func(root,0,0,mpp);
        for(auto it : mpp){
            sort(it.second.begin(),it.second.end(),comp);
            vector<int> temp;
            for(auto i : it.second) temp.push_back(i.second);
            ans.push_back(temp);
        }
        return ans;
    }
};//video also

//199
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return v;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == s - 1){
                    v.push_back(node->val);
                }
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        return v;
    }
};


//101
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* left,TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val!=right->val) return false;
        return check(left->left,right->right) && check(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return check(root->left,root->right);
    }
};