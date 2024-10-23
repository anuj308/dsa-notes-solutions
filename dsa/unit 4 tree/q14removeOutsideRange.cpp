// Single File Programming Question
// Problem Statement



// Yogi is working on a program to manage a binary search tree (BST) containing integer values. He wants to implement a function that removes nodes from the tree that fall outside a specified range defined by a minimum and maximum value.



// Help Yogi by writing a function that achieves this.

// Input format :
// The first line of input consists of an integer N, representing the number of elements to be inserted into the BST.

// The second line consists of N space-separated integers, representing the elements to be inserted into the BST.

// The third line consists of two space-separated integers min and max, representing the minimum value and the maximum value of the range.

// Output format :
// The output prints the remaining elements of the BST in an in-order traversal, after removing nodes that fall outside the specified range.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases will fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ elements ≤ 1000

// 1 ≤ min, max ≤ 1000

// Sample test cases :
// Input 1 :
// 5
// 10 5 15 20 12
// 5 15
// Output 1 :
// 5 10 12 15 
// Input 2 :
// 7
// 10 5 15 20 12 18 8
// 8 18
// Output 2 :
// 8 10 12 15 18 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include <iostream>
using namespace std;
struct node {
    int key;
    node* left;
    node* right;
};

node* newNode(int num) {
    node* temp = (node*)malloc(sizeof(node));
    temp->key = num;
    temp->left = temp->right = nullptr;
    return temp;
}

node* insert(node* root, int key) {
    if (root == nullptr)
        return newNode(key);

    if (root->key > key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

node* deleteNode (node * todelete,int val){
    
    if(todelete == NULL) return todelete;
    
    node* current = todelete;
    if(val < current->key){
        todelete->left = deleteNode(current->left,val);
    }else if(val > current->key){ 
        todelete->right = deleteNode(current->right,val);
    }else{
        if(current->left == NULL){
            current = current->right;
            return todelete;
        }else if(current->right == NULL){
            current =  current->left;
            return todelete;
        }
        
        node* temp = todelete;
        
        while(temp && temp->left != NULL){
            temp= temp->left;
        }
        
        todelete->key = temp->key;
        
        todelete->right = deleteNode(todelete->right,temp->key);
    }
    return todelete;
}

node* removeOutsideRange(node* root, int min, int max) {
    node* current = root;
    
    if(current == NULL) return root;
    current->left = removeOutsideRange(current->left,min,max);
    current->right = removeOutsideRange(current->right,min,max);
    
    if(current->key < min  || current->key > max){
        if(current->left == NULL){
            current = current->right;
        }else if(current->right == NULL){
            current = current->left;
        }else{
        deleteNode(current,current->key);
        }
    }
    return current;
}

void inorderTraversal(node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    node* root = nullptr;
    int num, min, max;

    cin >> num;

    for (int i = 0; i < num; i++) {
        int key;
        cin >> key;
        root = insert(root, key);
    }

    cin >> min;
    cin >> max;

    root = removeOutsideRange(root, min, max);

    inorderTraversal(root);

    return 0;
}