// Single File Programming Question
// Problem Statement



// John, a computer science student, is learning about binary search trees (BST) and their properties. He decides to write a program to create a BST, display it in post-order traversal, and find the minimum value present in the tree.



// Help him by implementing the program.

// Input format :
// The first line of input consists of an integer N, representing the number of elements to insert into the BST.

// The second line consists of N space-separated integers data, which is the data to be inserted into the BST.

// Output format :
// The first line of output prints the space-separated elements of the BST in post-order traversal.

// The second line prints the minimum value found in the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ data ≤ 1000

// Sample test cases :
// Input 1 :
// 3
// 5 10 15
// Output 1 :
// 15 10 5 
// The minimum value in the BST is: 5
// Input 2 :
// 10
// 10 5 15 3 7 12 18 20 25 30
// Output 2 :
// 3 7 5 12 30 25 20 18 15 10 
// The minimum value in the BST is: 3
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

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void displayTreePostOrder(Node* root) {
    if(root == NULL) return;
    displayTreePostOrder(root->left);
    displayTreePostOrder(root->right);
    cout << root->data << " ";
    
}

int findMinValue(Node* root) {
    
    while(root && root->left != NULL){
        root = root->left;
    }
    return root->data;
}

int main() {
    Node* root = nullptr;
    int n, data;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insert(root, data);
    }

    displayTreePostOrder(root);
    cout << endl;

    int minValue = findMinValue(root);
    cout << "The minimum value in the BST is: " << minValue;

    return 0;
}