// Single File Programming Question
// Problem Statement



// Audi, a luxury car manufacturer, offers customers the opportunity to book test drives for their latest car models. To streamline the test drive booking process, Audi wants to implement a custom function that takes customer details and preferred test drive dates as input. 



// The function should check for the availability of test drive slots on the given date and book the test drive for the customer if a slot is available. 



// It should also handle any clashes or boundary conditions during the booking process. 

// Input format :
// The input starts with a single integer N, representing the number of test drive slots.

// Then, there are N lines, each containing a date in the format "yyyy-mm-dd" followed by a space and a binary value (0 or 1), representing the availability status of the test drive slot.

// Output format :
// The output will be either "Test Drive Booked Successfully for {customerName} on {preferredDate}" if the test drive slot is available and booked successfully, or "Test Drive Slot not available for {customerName} on {preferredDate}" if the slot is not available. The {customerName} and {preferredDate} will be replaced with actual values based on the inputs provided during runtime.

// Code constraints :
// The code should handle up to 10^5 test drive slots efficiently.

// The date string should be limited to a practical length (e.g., 10 characters for "YYYY-MM-DD" format).

// The boolean isAvailable can have two possible values: 0 (false) or 1 (true).

// Sample test cases :
// Input 1 :
// 3
// 2023-07-25 1
// 2023-07-26 1
// 2023-07-27 0
// 2023-07-27 
// Output 1 :
// Test Drive Slot not available on 2023-07-27
// Input 2 :
// 3
// 2023-07-25 1
// 2023-07-26 1
// 2023-07-27 1
// 2023-07-27 
// Output 2 :
// Test Drive Booked Successfully on 2023-07-27
// Code Size : 1024 kb
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// // Extra spaces and new line characters in the program output will result in the failure of the test case.


// You are using GCC
#include <iostream>
#include <string>

struct TestDriveSlot {
    std::string date;
    bool isAvailable;
};

template <typename T>
bool bookTestDrive(const std::string& preferredDate, T* testDriveSlots, size_t size) {
    // write code here
    for(int i=0;i<size;i++){
        // std::cout <<testDriveSlots[i].date << testDriveSlots[i].isAvailable << std::endl;
        if(testDriveSlots[i].date == preferredDate && testDriveSlots[i].isAvailable == 1){
            return true;
        }
    }
    return false;
}

int main() {
    size_t numSlots;
    std::cin >> numSlots;

    TestDriveSlot* testDriveSlots = new TestDriveSlot[numSlots];
    for (size_t i = 0; i < numSlots; ++i) {
        std::cin >> testDriveSlots[i].date;
        std::cin >> testDriveSlots[i].isAvailable;
    }

    std::string preferredDate;
    std::cin >> preferredDate;

    bool isBookingSuccessful = bookTestDrive(preferredDate, testDriveSlots, numSlots);

    if (isBookingSuccessful) {
        std::cout << "Test Drive Booked Successfully on " << preferredDate;
    } else {
        std::cout << "Test Drive Slot not available on " << preferredDate;
    }

    delete[] testDriveSlots;
    return 0;
}