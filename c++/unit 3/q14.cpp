// Single File Programming Question
// Problem Statement



// Krish is working on a C++ program to manage an array of integers. His approach is as follows: Prompt the user to input an integer n, followed by n integer values. Store these values in a binary file named "numbers.dat" separated by spaces. Then, read the contents of "numbers.dat" and print them to the console.

// Input format :
// The first line consists of an integer n.

// The second line consists of n space-separated integers.

// Output format :
// The program displays the integers stored in the binary file, each separated by a space.

// If n < 0 or n > 100, the output prints "Invalid entry".

// Code constraints :
// 1 <= n <= 100

// Sample test cases :
// Input 1 :
// -1
// Output 1 :
// Invalid entry
// Input 2 :
// 200
// 893 267 142 5 686 743 517 506 21 493 671 22 304 540 788 116 484 505 810 318 340 755 599 66 775 793 884 306 140 692 435 680 273 136 349 229 964 32 960 300 726 277 958 500 525 565 363 918 628 667 678 453 393 129 569 627 888 252 467 332 683 54 436 934 339 494 224 729 190 222 837 598 180 417 396 554 429 376 414 197 985 477 877 489 102 71 236 836 65 740 718 582 817 365 778 112 7 178 564 699 590 584 991 44 186 465 439 244 430 925 103 682 219 130 732 470 191 479 241 503 736 629 246 911 796 425 571 324 557 196 386 316 488 617 491 373 381 73 819 445 711 892 643 251 968 509 128 860 745 679 80 928 606 504 501 560 413 938 710 468 204 294 717 87 357 423 358 105 371 933 398 833 639 859 645 207 721 61 741 872 424 157 961 416 869 940 122 48 158 549 223 462 422 551 994 151 317 360 174 183
// Output 2 :
// Invalid entry
// Input 3 :
// 5
// -71 278 3 425 50
// Output 3 :
// -71 278 3 425 50 


#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    if(n<1 || n>100){
        cout << "Invalid entry";
        return 0;
    }
    ofstream file("numbers.dat");
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
        file << arr[i] << " ";
    }
    file.close();
    
    ifstream inpFile("numbers.dat");
    string line;
    while(getline(inpFile,line)){
        cout << line << endl;
    }
    inpFile.close();
    return 0;
}