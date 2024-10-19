// Single File Programming Question
// Problem Statement

// ﻿

// Kishore is studying data structures, and he is currently working on implementing a binary search tree (BST) and exploring its basic operations. He wants to practice creating a BST, inserting elements into it, and performing a specific operation, which is deleting the minimum element from the tree.



// Write a program to help him perform the delete operation.

// Input format :
// The first line of input consists of an integer N, representing the number of elements Kishore wants to insert into the BST.

// The second line consists of N space-separated integers, where each integer represents an ﻿element to be inserted into the BST.

// Output format :
// The output prints the remaining elements of the BST in ascending order (in-order traversal) after deleting the minimum element.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 15

// 1 ≤ elements ≤ 1000

// All elements in the BST are unique.

// Sample test cases :
// Input 1 :
// 6
// 5 3 8 2 4 6
// Output 1 :
// 3 4 5 6 8 
// Input 2 :
// 3
// 14 85 17
// Output 2 :
// 17 85 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* insert(Node* root, int data) {
    if (root == nullptr)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

Node* minValueNode(Node* node) {
    if(node->left == NULL) return node;
    return minValueNode(node->left);
}

Node* deleteMin(Node* root) {
    if(root == NULL) return root;
    
    int deleteVal = minValueNode(root)->data; 
    
    Node *current = root;
    
   if(deleteVal < current->data){
       current->left = deleteMin(current->left);
   }else if(deleteVal > current->data){
       current->right = deleteMin(current->right);
   }else{
       if(current->left == NULL && current->right == NULL){
           root = NULL;
       }else if(root->left == NULL){
           root = root->right;
       }else if(root->right == NULL){
           root = root->left;
       }
   }
    
    return root;
}

void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    root = deleteMin(root);

    inOrderTraversal(root);
    return 0;
}