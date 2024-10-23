// Single File Programming Question
// Problem Statement



// Revi is fascinated by binary search trees (BSTs) and wants to perform some operations on them. He wishes to construct a binary search tree from a series of positive integers and calculate the sum of all the nodes in the BST.



// Write a program to help Revi implement these operations using the BST concept.

// Input format :
// The input consists of a series of positive integers (greater than zero) separated by a space.

// The input ends when -1 is entered.

// The integers represent the elements to be inserted into the binary search tree.

// Output format :
// The output displays an integer value, which represents the sum of all the nodes in the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The input integers will be positive and greater than zero.

// The number of elements in the binary search tree will be at most 100.

// Sample test cases :
// Input 1 :
// 5
// 3
// 7
// 2
// 4
// 9
// -1
// Output 1 :
// Sum of all nodes in the BST is 30
// Input 2 :
// 6
// 3
// 1
// 4
// 2
// -1
// Output 2 :
// Sum of all nodes in the BST is 16
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// You are using GCC
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

struct node* createNode(int d)
{
    struct node* newnode = new node;
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    
    return newnode;
}

struct node* insert(struct node *root, int value)
{
   if(root == NULL) {
        return createNode(value);
   }
   
   struct node *temp = root;
       if(temp->data < value){
           temp->right = insert(temp->right,value);
       }else{
           temp->left = insert(temp->left,value);
       }
       
   return root;
}

int addBST(struct node* root)
{
    if (root == NULL)
        return 0;

    return (root->data + addBST(root->left) + addBST(root->right));
}

int main()
{
    node* root = nullptr;
    int d;
    do
    {
        cin >> d;
        if (d > 0) root = insert(root, d);
    } while (d != -1);

    int sum = addBST(root);
    cout << "Sum of all nodes in the BST is " << sum;

    return 0;
}