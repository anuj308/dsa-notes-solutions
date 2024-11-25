// Single File Programming Question
// Problem Statement



// You are tasked with developing a simple Food Ordering System for a restaurant. The system allows customers to add food items to their order, update the quantity of items, and calculate the total bill. The restaurant can handle up to 100 different food items.



// Implement the system using iterators to efficiently manage the orders.

// Input format :
// The input consists of the following format:



// The user is presented with a menu of options:

// Add Order: The user can add a new food item to the order by providing the following details:

// Food item name (a string)

// Quantity of the food item (an integer)

// Price of the food item (a floating-point number)

// Update Quantity: The user can update the quantity of an already ordered food item by providing the following details:

// Food item name (a string)

// New quantity of the food item (an integer)

// Calculate Total Bill: The user can calculate the total bill for the current order.

// Exit: The user can choose to exit the system, ending the program.

// Output format :
// The output displays the following format:



// When the user chooses options 1, 2, or 4, there is no specific output other than the appropriate status messages as per the user's actions.

// When the user chooses option 3 to calculate the total bill, the program should display the total bill for the current order in the format: "Total Bill: $<total_bill>".

// If the user chooses option 2 (Update Quantity) for an item that is not present in the order, the program should display the following message:

// Item not found in the order.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The food item's name will be a single word without any spaces.

// The quantity of a food item will be a positive integer.

// The price of a food item will be a positive floating-point number.

// Sample test cases :
// Input 1 :
// 1
// Pizza
// 2
// 12.5
// 1
// Coke
// 3
// 2.0
// 2
// Pizza
// 6
// 3
// 4
// Output 1 :
// Total Bill: $81
// Input 2 :
// 1
// Burger
// 1
// 8.0
// 2
// Pizza
// 2
// 3
// 7
// 4
// Output 2 :
// Item not found in the order.
// Total Bill: $8
// Invalid choice
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.


// one test case did not pass
#include <bits/stdc++.h>
using namespace std;


int main(){
    
    int n;
    string item;
    int qty;
    float price;
    unordered_map<string,pair<int,float>> cart;
    while(true){
        cin >> n;
        
        if(n==1){
            cin >> item;
            cin >> qty;
            cin >> price;
            cart[item].first = qty;
            cart[item].second = price;
        }else if(n==2){
            cin >> item;
            cin >> qty;
            if(cart.find(item) != cart.end()){
                cart[item].first = qty;
            }else{
                cout << "Item not found in the order." << endl;
            }
        }else if(n==3){
            int total =0;
            for(const auto c : cart){
                total+=c.second.first*c.second.second;
            }
            cout << "Total Bill: $" << total << endl;
        }else if(n==4){
            exit(0);
        }else{
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}