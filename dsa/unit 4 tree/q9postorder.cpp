// Single File Programming Question
// Problem Statement



// Emily is given a binary tree where each node contains an integer value. She needs to construct the tree using a post-order traversal input, where -1 denotes a NULL node. After building the tree, compute and display the sum of all nodes and print the nodes in post-order traversal.



// Can you help Emily with the tree creation?

// Input format :
// The input consists of a series of positive integers provided in a separate line.

// To build the binary tree, enter its value first for each node. If a node has no left or right child, enter -1.

// Output format :
// The first line of the output displays the postorder traversal sequence of the binary tree.

// The second line of the output displays the sum of all the nodes.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 0 ≤ Value of the node ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// -1
// -1
// Output 1 :
// Postorder Traversal: 5 
// Sum of all nodes: 5
// Input 2 :
// 70
// 25
// -1
// -1
// -1
// Output 2 :
// Postorder Traversal: 25 70 
// Sum of all nodes: 95
// Input 3 :
// 5
// 2
// -1
// -1
// 7
// -1
// -1
// Output 3 :
// Postorder Traversal: 2 7 5 
// Sum of all nodes: 14
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

    void fun(TreeNode* newNode)
{
    int l,r;
    cin >> l;
    if(l==-1){
        newNode->left = NULL;
    }else{
    newNode->left = new TreeNode(l);
    fun(newNode->left);
    }
    cin >> r;
    if(r==-1){
        newNode->right= NULL;
    }else{
    newNode->right = new TreeNode(r);
    fun(newNode->right);
}
}
TreeNode* buildTree() {
    int n;
    cin >> n;
    struct TreeNode* newNode = new struct TreeNode(n);
    fun(newNode);
    return newNode;
}

int sumOfNodes(TreeNode* root) {
    if(root == NULL) return 0;
    int sum = root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
    return sum;
    
}

void postorderTraversal(TreeNode* root) {
    if(root == NULL ) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << " ";
}

int main() {
    
    TreeNode* root = buildTree();

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    int sum = sumOfNodes(root);
    cout << "Sum of all nodes: " << sum;

    return 0;
}