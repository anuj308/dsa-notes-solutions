// Single File Programming Question
// Problem Statement



// In a futuristic city where time was everything, a brilliant scientist named Dr. Smith created a unique Time class capable of decrementing time by a minute with the overloaded -- operator.



// One day, a young time traveler named Max stumbled upon Dr. Smith's invention and decided to test its capabilities. Max entered a specific time into the console, and the Time class worked its magic, beautifully displaying the time before and after the decrement.



// As the clock ticked back, Max marveled at the power of operator overloading, realizing the immense potential it held for their future time-traveling adventures.



// Note:

// The time format should always have two digits for hours and two digits for minutes, with leading zeros if required (e.g., 01:05, 10:09).



// The program should handle edge cases correctly, such as decrementing 00:00, which should display an error message indicating that the time cannot be decremented further.

// Input format :
// The input consists of a single line containing two space-separated integers H and M, where H represents the hours (0 to 23) and M represents the minutes (0 to 59).

// Output format :
// The output displays two lines:



// The first line should contain the original time in the format HH:MM.

// The second line should contain the updated time after decrementing one minute in the format HH:MM.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 0 ≤ H ≤ 23

// 0 ≤ M ≤ 59

// Sample test cases :
// Input 1 :
// 12 57
// Output 1 :
// Time before decrement: 12:57
// Time after decrement: 12:56
// Input 2 :
// 00 00
// Output 2 :
// Time before decrement: 0:00
// Cannot decrement further. Time is already at 00:00.
// Time after decrement: 0:00
// Input 3 :
// 01 23
// Output 3 :
// Time before decrement: 1:23
// Time after decrement: 1:22
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.
#include <bits/stdc++.h>
using namespace std;

class Time{
    public:
        int h = 00;
        int m = 00;
        Time(int h1,int m1){
            h = h1;
            m = m1;
        }
    void operator--(){
        if(m<10){
            cout << "Time before decrement: "<< h << ":0" << m << endl;
        }else{
            cout << "Time before decrement: " << fixed << setprecision(2) << h << ":" << m << endl;
        }

        if(h==00 && m==00){
            cout << "Cannot decrement further. Time is already at 00:00." << endl;
        }else{
            if(m==0){
                h--;
                m=59;
            }else{
                m--;
            }
        }
        
        if(m<10){
            cout << "Time after decrement: "<< h << ":0" << m << endl;
        }else{
            cout << "Time after decrement: " << h << ":" << m << endl;
        }
        
    }; 
};

int main(){
    
    int h,m;
    cin >> h;
    cin >> m;
    Time t1(h,m);
    --t1;
    
    return 0;
}