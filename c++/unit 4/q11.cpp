// Single File Programming Question
// Problem Statement



// Write a program that manages details of items in a store, including their original price and discount percentage. Each item has an item number, name, and price. The program should calculate the discounted price for each item and display all the details. 



// Additionally, it should calculate and display the total price of all items and the total discount applied across all items. Implement this using multiple inheritance where DiscountedItem inherits from ItemDetails and DiscountDetails.

// Input format :
// The input consists of the number of items, N.

// For each item, input:

// item_name (a string of up to 50 characters)
// item_no (an integer)
// item_price (a double value representing the price of the item)
// discount_percent (an integer representing the discount percentage)
// Output format :
// For each item, display the details in the following order:

// Item Name (string)
// Item No. (integer)
// Item Price (as a double value rounded to one decimal place)
// Discount Percent (integer)
// Discounted Price (as a double value rounded to one decimal place)


// Finally:

// Display the total price of all items before the discount, as a double value rounded to one decimal place.

// Display the total discount applied to all items as a double value rounded to one decimal place.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ N ≤ 10

// Sample test cases :
// Input 1 :
// 2
// Pen
// 012
// 120.0
// 2
// Book
// 023
// 560.0
// 5
// Output 1 :
// Details of item 1 :
// 1. Item Name: Pen
// 2. Item No.: 12
// 3. Item Price: 120.0
// 4. Discount Percent: 2
// 5. Discounted Price: 117.6

// Details of item 2 :
// 1. Item Name: Book
// 2. Item No.: 23
// 3. Item Price: 560.0
// 4. Discount Percent: 5
// 5. Discounted Price: 532.0

// Total Price: 680.0
// Total Discount: 30.4
// Input 2 :
// 3
// NoteBook
// 012
// 60.0
// 2
// Eraser
// 101
// 12.7
// 0
// Box
// 034
// 360.0
// 2
// Output 2 :
// Details of item 1 :
// 1. Item Name: NoteBook
// 2. Item No.: 12
// 3. Item Price: 60.0
// 4. Discount Percent: 2
// 5. Discounted Price: 58.8

// Details of item 2 :
// 1. Item Name: Eraser
// 2. Item No.: 101
// 3. Item Price: 12.7
// 4. Discount Percent: 0
// 5. Discounted Price: 12.7

// Details of item 3 :
// 1. Item Name: Box
// 2. Item No.: 34
// 3. Item Price: 360.0
// 4. Discount Percent: 2
// 5. Discounted Price: 352.8

// Total Price: 432.7
// Total Discount: 8.4
// Note :
// You are using GCC
#include <iostream>
#include <iomanip>

using namespace std;

class DiscountDetails {
public:
    int discount_percent;
    double discounted_price;
};

class ItemDetails {
public:
    int item_no;
    char item_name[50];
    double item_price;
};

class DiscountedItem : public ItemDetails, public DiscountDetails {
public:
    void accept_details() {
        cin >> item_name;
        cin >> item_no;
        cin >> item_price;
        cin >> discount_percent;
        discounted_price = item_price - item_price * discount_percent / 100;
    }

    void display_details() {
        cout << "1. Item Name: " << item_name << endl;
        cout << "2. Item No.: " << item_no << endl;
        cout << "3. Item Price: " << fixed << setprecision(1) << item_price << endl;
        cout << "4. Discount Percent: " << discount_percent << endl;
        cout << "5. Discounted Price: " << discounted_price << endl;
    }
};

int main() {
    int i, cnt;
    double discount = 0.0, price = 0.0,temp=0.0;
    DiscountedItem dt[100];
    cin >> cnt;
    for (i = 1; i <= cnt; i++) {
        dt[i].accept_details();
    }
    for (i = 1; i <= cnt; i++) {
        cout << "Details of item " << i << " :\n";
        dt[i].display_details();
        price+=dt[i].item_price;
        temp+=dt[i].discounted_price;
    }
    discount = price - temp;
    
    cout << fixed << setprecision(1) << endl;
    cout << "Total Price: " << price << endl;
    cout << "Total Discount: " << discount;
    return 0;
}