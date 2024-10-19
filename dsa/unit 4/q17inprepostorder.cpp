// Single File Programming Question
// Problem Statement



// John is organizing data in a binary search tree for quick retrieval. He needs a program that builds the tree and recursively performs inorder, preorder, and postorder traversals to display the elements in different orders. 



// Help him implement the solution by creating the tree and performing the required traversals.

// Input format :
// The input consists of integers representing the choice and the corresponding operation.

// If the choice is 1, enter the number of elements (n) and the elements to be inserted into the tree.

// If the choice is 2, print the in-order traversal.

// If the choice is 3, print the pre-order traversal.

// If the choice is 4, print the post-order traversal.

// If the choice is 5, exit.

// Output format :
// The output prints the results based on the choice.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 15

// 1 ≤ BST elements ≤ 1000

// Sample test cases :
// Input 1 :
// 1
// 5
// 12 78 96 34 59
// 2
// 3
// 4
// 5
// Output 1 :
// Inorder: 12 34 59 78 96 
// Preorder: 12 78 34 59 96 
// Postorder: 59 34 96 78 12 
// Input 2 :
// 1
// 9
// 7 9 6 3 2 1 4 5 8
// 2
// 4
// 5
// Output 2 :
// Inorder: 1 2 3 4 5 6 7 8 9 
// Postorder: 1 2 5 4 3 6 8 9 7 
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


// You are using GCC
#include <iostream>
#include<stdlib.h>

using namespace std;

struct tnode
{
    int data;
    struct tnode *right;
    struct tnode *left;
};

struct tnode *CreateBST(struct tnode *, int);
void Inorder(struct tnode *);
void Preorder(struct tnode *);
void Postorder(struct tnode *);

int main()
{
    struct tnode *root = NULL;
    int choice, item, n, i;
    do
    {
        cin>>choice;
        switch(choice)
        {
        case 1:
            root = NULL;
            cin>>n;
            for(i = 1; i <= n; i++)
            {
                cin>>item;
                root = CreateBST(root,item);
            }
            break;
        case 2:
            cout<<"Inorder: ";
            Inorder(root);
            cout<<"\n";
            break;
        case 3:
            cout<<"Preorder: ";
            Preorder(root);
            cout<<"\n";
            break;
        case 4:
            cout<<"Postorder: ";
            Postorder(root);
            cout<<"\n";
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    } while(1);
    return 0;
}

struct tnode *CreateBST(struct tnode *root, int item) {
    tnode* newnode = new tnode;
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    
    if(root == NULL) return newnode;
    
    if(item < root->data){
        root->left = CreateBST(root->left,item);
    }else{
        root->right = CreateBST(root->right,item);
    }
    
    return root;
}

void Inorder(struct tnode *root) {
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Preorder(struct tnode *root) {
    if(root == NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(struct tnode *root) {
    if(root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}