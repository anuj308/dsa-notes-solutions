// https://www.geeksforgeeks.org/problems/search-a-node-in-bst/1

bool search(Node* root, int key) {
    // code here
    while(root){
        if(root->data == key) return true;
        if(key<root->data) root=root=root->left;
        else root=root->right;
    }
    
    
    return false;
}