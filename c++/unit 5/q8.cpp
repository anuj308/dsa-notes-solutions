// Single File Programming Question
// Problem statement



// Raj is managing a small grocery store and wants to keep track of the items he sells, along with their prices. To do this, he creates a Shop class that allows him to set the price of items using the virtual function setPrice().



// He then defines a ConcreteShop class that inherits from Shop to handle the specifics of his store. By inputting the number of items and their respective IDs and prices, Raj can store this information efficiently. After adding all the items, he can display the list of item IDs with their prices, along with the total price of all items in the store.

// Input format :
// The first line contains an integer n, the number of items.

// The next n lines each contain two space-separated integers: the item ID and the item price.

// Output format :
// The output consists of n lines, each formatted as: "ID: <itemId> Price: <itemPrice>".

// The last line should display the total price of all items, formatted as: "Total Price: <totalPrice>".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 100

// Each item ID is unique and within the range of 1 to 1000.

// Each item's price is a non-negative integer within the range of 0 to 10000.

// Sample test cases :
// Input 1 :
// 3
// 1 100
// 2 200
// 3 300
// Output 1 :
// ID: 1 Price: 100
// ID: 2 Price: 200
// ID: 3 Price: 300
// Total Price: 600
// Input 2 :
// 4
// 11 25
// 22 54
// 33 72
// 44 90
// Output 2 :
// ID: 11 Price: 25
// ID: 22 Price: 54
// ID: 33 Price: 72
// ID: 44 Price: 90
// Total Price: 241
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
// You are using GCC
#include <iostream>
using namespace std;

class Shop
{
protected:
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    Shop() { counter = 0; } 
    virtual void setPrice(){}
};

class ConcreteShop : public Shop
{
public:
    void setPrice(int i,int p){
        cout << "ID: " << i << " Price: " << p << endl;
        counter +=p;
    }
    void displayPrice(int n){
        cout << "Total Price: " << counter << endl; 
    }
};

int main()
{
    ConcreteShop dukaan;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int id, price;
        cin >> id >> price; 
        dukaan.setPrice(id, price);
    }

    dukaan.displayPrice(n);

    return 0;
}