// https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {    
        if(st.empty()) return false;
        return true;
    }
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
};