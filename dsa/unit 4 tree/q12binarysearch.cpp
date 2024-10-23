// Single File Programming Question
// Problem Statement



// Ragul wants to build a binary search tree (BST) and perform a key search operation on it. He needs your help to accomplish this. Write a program that helps Ragul create a BST and search for a specific key within it.



// Company Tags: Wipro

// Input format :
// The first line of input consists of the number of nodes n.

// The second line of input consists of n unique values for nodes, separated by a space.

// The third line of input consists of the key to be searched.

// Output format :
// The output displays one of the following messages based on whether the key is found in the binary search tree or not in the following format:



// If the key is found in the binary search tree, print "The key <<key value>> is found in the binary search tree"
// If the key is not found in the binary search tree, print "The key <<key value>> is not found in the binary search tree"


// Refer to the sample output for the exact format.

// Code constraints :
// 1 ≤ n ≤ 10

// Each node value is a unique integer.

// 1 <= key <= 1000

// Sample test cases :
// Input 1 :
// 7
// 101 102 103 105 106 108 110
// 102
// Output 1 :
// The key 102 is found in the binary search tree
// Input 2 :
// 7
// 101 102 103 105 106 108 110
// 115
// Output 2 :
// The key 115 is not found in the binary search tree
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

Node* createNode(int value) {
   
    Node* newNode = new Node();
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}

Node* insertNode(Node* root, int value) {
 
    if(root == NULL)
        return createNode(value);
    
    Node *current = root;
    if(current->data < value)
        current->right = insertNode(current->right,value);
    else
        current->left = insertNode(current->left,value);
    
    return root;
}

bool searchKey(Node* root, int key) {
    if(root == NULL) return 0;
    else if(root->data == key)
        return 1;
    else if(root->data < key)
        searchKey(root->right,key);
    else
        searchKey(root->left,key);
}

int main() {
    Node* root = NULL;
    int numNodes, value, key;

    cin >> numNodes;

    for (int i = 0; i < numNodes; i++) {
        cin >> value;
        root = insertNode(root, value);
    }

    cin >> key;

    bool found = searchKey(root, key);
    if (found) {
        cout << "The key " << key << " is found in the binary search tree";
    } else {
        cout << "The key " << key << " is not found in the binary search tree";
    }

    return 0;
}