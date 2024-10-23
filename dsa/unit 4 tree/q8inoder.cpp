// Single File Programming Question
// Problem Statement



// A company is designing an organizational structure to manage employees hierarchically. Each employee is represented as a node in a binary tree, where each node (positive integer) contains the employee's ID. The organization uses a level-order approach to insert employees into the tree. Each new employee is added to the next available position in the current level of the binary tree.



// The system needs to:



// Insert new employee's ID positive integers into the organizational structure following a level-order traversal.
// Print out the IDs of employees in the organization using an in-order traversal.


// Example



// Input

// 1 2 3 0

// Output

// 2 1 3

// Explanation

// 1 is the root of the Binary tree. 2 is the left child of 1, and 3 is the right child of 1. Hence the in-order traversal is 2 1 3, which follows the rule Left Root Right.

// Input format :
// The input consists of a sequence of positive integers, where each integer represents an employee ID.

// The sequence ends with a non-positive integer (e.g., 0 or -1), which indicates the end of input.

// Output format :
// The output displays the sequence of integers representing the employee IDs in the in-order traversal of the binary tree.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= employee ID <= 100

// Sample test cases :
// Input 1 :
// 1 2 3 0
// Output 1 :
// 2 1 3 
// Input 2 :
// 1 2 3 4 5 6 7 -8
// Output 2 :
// 4 2 5 1 6 3 7

// You are using GCC
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

struct BinaryTree {
    Node* root;
};

void insert(BinaryTree* binaryTree, int data, Node** queue, int* front, int* rear) {
    Node* temp = createNode(data);

    if (binaryTree->root == nullptr) {
        binaryTree->root = temp;
        *front = 0;
        *rear = 0;
        queue[*rear] = binaryTree->root;
        return;
    }

    Node* current = queue[*front];

    if (current->left == nullptr) {
        current->left = temp;
    } else if (current->right == nullptr) {
        current->right = temp;
        (*front)++;
    }

    (*rear)++;
    queue[*rear] = temp;
}

void inOrder(Node* root) 
{
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    BinaryTree binaryTree;
    binaryTree.root = nullptr;
    Node* queue[100]; 
    int front = 0, rear = -1;

    int i;
    while (true) {
        cin >> i;
        if (i < 1)
            break;
        insert(&binaryTree, i, queue, &front, &rear);
    }

    inOrder(binaryTree.root);
    return 0;
}