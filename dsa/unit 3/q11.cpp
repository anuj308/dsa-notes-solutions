// Single File Programming Question
// Problem Statement



// You are tasked with developing a simple inventory management system for a bookstore. The system should allow the bookstore staff to manage the inventory of books, prioritize restocking, and efficiently handle restocking operations.



// The program uses a priority queue to manage the inventory. Each book in the inventory is represented by its title, the current quantity available, and a restock priority. The book is restocked using restock priority. The restock priority is a value between 1 and 5, a low value indicating a higher priority. In the order of priority, 1 has high priority, the level gets reduced as the priority value increases, and 5 has low priority.



// Include the following options:

// 1 - Add book to inventory

// 2 - Restock book

// 3 - View the next book to restock

// 4 - Exit

// Input format :
// The input consists of integers representing the choice from the menu.



// For choice 1 (Add book to inventory), the following lines of input consists of:

// Book title (string with spaces allowed)
// Current quantity (integer)
// Restock priority (integer between 1 and 5, inclusive)


// For choices 2 (Restock book) and 3 (View next book to restock), no additional input is required.



// For choice 4 (Exit), no additional input is required.

// Output format :
// For choice 1, the program prints: "Book added to the inventory"

// For choice 2, the program prints: "Restocked book: [Book Title]"

// For choice 3, the program prints after restocking the book: "Next book to restock: [Book Title]"

// For choice 4, the program prints: "Exiting the application"



// If the choices are not 1, 2, 3, or 4:

// For invalid choices, the program prints: "Invalid choice. Please enter a valid option"



// For choice 3:

// When there are no books in the inventory, the program prints: "No books in the inventory."



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ restock priority ≤ 5

// The book title can include spaces and should be non-empty.

// The choice entered by the user should be an integer corresponding to the available menu options.

// Sample test cases :
// Input 1 :
// 1
// Wings of Fire
// 5
// 4
// 1
// Harry Potter and the Sorcerer's Stone
// 7
// 2
// 2
// 3
// 4
// Output 1 :
// Book added to the inventory
// Book added to the inventory
// Restocked book: Harry Potter and the Sorcerer's Stone
// Next book to restock: Wings of Fire
// Exiting the application
// Input 2 :
// 1
// The Great Mocking Bird
// 3
// 4
// 2
// 3
// 4
// Output 2 :
// Book added to the inventory
// Restocked book: The Great Mocking Bird
// No books in the inventory
// Exiting the application
// Input 3 :
// 6
// 4
// Output 3 :
// Invalid choice. Please enter a valid option
// Exiting the application
// Input 4 :
// 2
// 4
// Output 4 :
// No books in the inventory.
// Exiting the application


// sample code

// You are using GCC
// #include <iostream>
// #include <string>

// const int MAX_SIZE = 100;

// struct Book {
//     std::string title;
//     int quantity;
//     int restockPriority;
// };

// struct PriorityQueue {
//     Book arr[MAX_SIZE];
//     int size;

//     PriorityQueue() : size(0) {}

//     bool isEmpty() {
//         return size == 0;
//     }

//     void push(const Book& book,title,quantity,priority) {
//         struct book *temp;
//         temp.title = title;
//         temp.quatity = quantity;
        
//         arr
        
    
//     }

//     void pop() {
//         //Type your code here
    
//     }

//     Book top() {
//         if (isEmpty()) {
//             std::cout << "No books in the inventory\n";
//             return {"", 0, 0};
//         }
//         return arr[0];
//     }
// };

// int main() {
//     PriorityQueue inventory;

//     int choice;
//     do {
        
//         std::cin >> choice;
//         std::cin.ignore(); // Clear the newline character from the previous input

//         switch (choice) {
//             case 1: {
//                 std::string title;
//                 int quantity, priority;
//                 std::getline(std::cin, title);
//                 std::cin >> quantity;
//                 std::cin >> priority;
//                 if (priority < 1) priority = 1;
//                 if (priority > 5) priority = 5;
//                 inventory.push({title, quantity, priority});
//                 std::cout << "Book added to the inventory\n";
//                 break;
//             }
//             case 2:
//                 if (!inventory.isEmpty()) {
//                     std::cout << "Restocked book: " << inventory.top().title << "\n";
//                     inventory.pop();
//                 } else {
//                     std::cout << "No books in the inventory.\n";
//                 }
//                 break;
//             case 3:
//                 if (!inventory.isEmpty()) {
//                     std::cout << "Next book to restock: " << inventory.top().title << "\n";
//                 } else {
//                     std::cout << "No books in the inventory\n";
//                 }
//                 break;
//             case 4:
//                 std::cout << "Exiting the application";
//                 break;
//             default:
//                 std::cout << "Invalid choice. Please enter a valid option\n";
//                 break;
//         }
//     } while (choice != 4);

//     return 0;
// }