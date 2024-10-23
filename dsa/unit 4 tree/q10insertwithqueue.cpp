// Single File Programming Question
// Problem Statement 



// In a binary tree where each node contains a single character, you need to build the tree by inserting characters in the order provided. After constructing the tree, perform a post-order traversal to print the characters. Ensure to manage memory properly by freeing the tree after traversal.

// Input format :
// The first line contains an integer n representing the number of characters to be inserted into the binary tree.

// The second line contains n characters where each character is inserted into the tree in the given order.

// Output format :
// The output should be a single line with characters printed in the post-order traversal of the tree.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 26

// Sample test cases :
// Input 1 :
// 6
// a f d e c b
// Output 1 :
// e c f b d a 
// Input 2 :
// 5
// a b c d e
// Output 2 :
// d e b c a 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, char data) {
    TreeNode* newNode = new TreeNode(data);
    if(root == nullptr){
        return newNode;        
    }
    
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        
        if(current->left == nullptr){
            current->left = newNode;
            return root;
        }else{
            q.push(current->left);
        }
        
        if(current->right == nullptr){
            current->right = newNode;
            return root;
        } else{
            q.push(current->right);
        }
    }
    
    return root;
}

void freeTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

void postOrder(TreeNode* root) {
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
    
}

int main() {
    TreeNode* root = nullptr;
    int n;
    char data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    postOrder(root);
    cout << endl;

    freeTree(root);

    return 0;
}