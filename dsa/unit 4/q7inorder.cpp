// Single File Programming Question
// Problem Statement



// Dev is learning about binary trees and their traversals. He is particularly interested in the in-order traversal of a binary tree. 



// He decides to write a program to perform an in-order traversal of a binary tree.



// Write a program to help Dev that takes as input a set of integers and constructs a binary tree. Then, perform an in-order traversal of the tree and print the values of the nodes.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes in the binary tree.

// The second line consists of N integers, representing the values of the nodes in the tree.

// Output format :
// The output prints the in-order traversal of the tree.

// Sample test cases :
// Input 1 :
// 4 
// 17 23 65 24
// Output 1 :
// 17 23 24 65 
// Input 2 :
// 6
// 78 22 30 12 34 27
// Output 2 :
// 12 22 27 30 34 78 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = new struct Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct Node* root) 
{
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }
    inorderTraversal(root);
    return 0;
}