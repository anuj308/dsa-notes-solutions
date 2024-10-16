// Single File Programming Question
// Problem Statement



// Sarah keeps a two-way linked list of her favorite recipes, each represented by an integer code. She wants to traverse the list to review all recipes, insert a new recipe at the end, and remove a recipe based on its code. Write a program to assist Sarah with these tasks.

// Input format :
// The first line of input consists of an integer N, the number of recipes in the list.

// The second line contains N integers, each representing a recipe code.

// The third line contains an integer M, the code of the new recipe to be inserted at the end of the list.

// The fourth line contains an integer R, the code of the recipe to be removed from the list.

// Output format :
// The first line of output prints the list of recipe codes after inserting the new recipe at the end.

// The second line prints the list of recipe codes after removing the specified recipe code.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 10

// 100 ≤ recipe code ≤ 1000

// R is present in the list.

// Sample test cases :
// Input 1 :
// 5
// 101 202 303 404 505
// 606
// 303
// Output 1 :
// 101 202 303 404 505 606 
// 101 202 404 505 606 
// Input 2 :
// 5
// 101 102 103 104 105
// 106
// 101
// Output 2 :
// 101 102 103 104 105 106 
// 102 103 104 105 106 


#include <iostream>

using namespace std;

class Node {
public:
    int recipeCode;
    Node* next;
    Node* prev;

    Node(int recipeCode) {
        this->recipeCode = recipeCode;
        next = nullptr;
        prev = nullptr;
    }
};

class RecipeList {
public:
    Node* head;
    Node* tail;

    RecipeList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertRecipe(int recipeCode) {
        Node* newNode = new Node(recipeCode);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void removeRecipe(int recipeCode) {
        Node* current = head;
        while (current != nullptr && current->recipeCode != recipeCode) {
            current = current->next;
        }
        if (current != nullptr) {
            if (current->prev != nullptr) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != nullptr) {
                current->next->prev = current->prev;
            } else {
                tail = current->prev;
            }
            delete current;
        }
    }

    void printRecipeList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->recipeCode << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    RecipeList recipeList;
    for (int i = 0; i < n; i++) {
        int recipeCode;
        cin >> recipeCode;
        recipeList.insertRecipe(recipeCode);
    }
    int m, r;
    cin >> m >> r;
    recipeList.insertRecipe(m);
    recipeList.printRecipeList();
    recipeList.removeRecipe(r);
    recipeList.printRecipeList();
    return 0;
}