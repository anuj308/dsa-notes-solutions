// Single File Programming Question
// Problem Statement



// Olivia is developing a secure user management system for her application, where she wants to allow users to create accounts with usernames and passwords. To enhance security, Olivia decides to encrypt the passwords using a simple character-shifting technique. She plans to implement a program that enables users to register with their usernames and passwords, storing the encrypted passwords in dynamically allocated memory.



// Additionally, she wants to allow users to retrieve their passwords by providing their usernames and decrypting the stored passwords before displaying them. Olivia needs your help to create this system, ensuring that it can handle up to 10 users and efficiently manage their encrypted credentials while utilizing dynamic memory allocation for username and password storage.

// Input format :
// The first line contains an integer representing the user's choice:

// 1 for user registration
// 2 for password retrieval
// 3 to exit the application


// If the user chooses 1, the next two lines should contain the username and password.

// If the user chooses 2, the next line should contain the username.

// If the user chooses 3, the application will terminate.

// Output format :
// If the user successfully registers, no output is needed.

// When retrieving a password, display: "Password for user '<username>' is: <decrypted_password>".

// If the username is not found, display: "User not found".

// If the maximum number of users is reached, display: "Maximum users reached".

// If the user enters an invalid choice, display: "Invalid choice".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The maximum number of users is 10.

// Usernames and passwords can contain any printable characters.

// No two users can have the same username.

// Sample test cases :
// Input 1 :
// 1
// JohnDoe
// P@ssw0rd
// 2
// JohnDoe
// 4
// 3
// Output 1 :
// Password for user 'JohnDoe' is: P@ssw0rd
// Invalid choice
// Input 2 :
// 1
// Alice
// MySecret
// 1
// Bob
// MyPassword
// 2
// Alice
// 2
// Bob
// 2
// John
// 3
// Output 2 :
// Password for user 'Alice' is: MySecret
// Password for user 'Bob' is: MyPassword
// User not found
// Input 3 :
// 1
// User1
// Password1
// 1
// User2
// Password2
// 1
// User3
// Password3
// 1
// User4
// Password4
// 1
// User5
// Password5
// 1
// User6
// Password6
// 1
// User7
// Password7
// 1
// User8
// Password8
// 1
// User9
// Password9
// 1
// User10
// Password10
// 2
// User10
// 2
// User8
// 1
// User11
// Password11
// 3
// Output 3 :
// Password for user 'User10' is: Password10
// Password for user 'User8' is: Password8
// Maximum users reached
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

#include <cstring>
#include <iostream>
using namespace std;

struct User{
    char* username;
    char* encryptedPassword;
};

char* encryptPassword(const char* password,int shift = 1){
    int len = strlen(password);
    char* encrypted = new char[len + 1];
    
    for(int i=0 ; i< len ; i++){
        encrypted[i] = password[i] + shift;
    }
    encrypted[len] = '\0';
    return encrypted;
}

char* decryptPassword(const char* encryptedPassword,int shift = 1){
    int len = strlen(encryptedPassword);
    char* decrypted = new char[len + 1];
    
    for(int i=0 ; i< len ; i++){
        decrypted[i] = encryptedPassword[i] - shift;
    }
    decrypted[len] = '\0';
    return decrypted;
}
int main(){
    User users[10];
    int userCount = 0;
    
    while(true){
        int choice;
        cin >> choice;
        
        if(choice==1){
            char username[100],password[100];
            cin.ignore();
            cin.getline(username,100);
            cin.getline(password,100);
            if(userCount >= 10){
                cout << "Maximum users reached" << endl;
                continue;
            }
        
            bool usernameExists = false;
            for(int i=0;i<userCount;i++){
                if(strcmp(users[i].username,username) == 0){
                    usernameExists = true;
                    break;
                }
            }
            
            if(usernameExists){
                cout << "User already exixts" << endl;
            }
            else{
                users[userCount].username = new char[strlen(username) + 1];
                strcpy(users[userCount].username,username);
                users[userCount].encryptedPassword = encryptPassword(password);
                userCount++;
            }
        }else if(choice==2){
            
            char username[100];
            cin.ignore();
            cin.getline(username,100);
            
            bool found = false;
            
            for(int i=0; i < userCount ; i++){
                if(strcmp(users[i].username, username) == 0){
                    char* decryptedPassword = decryptPassword(users[i].encryptedPassword);
                    cout << "Password for user '" << users[i].username << "' is: " << decryptedPassword <<endl;
                    delete [] decryptedPassword;
                    found = true;
                }
            }
            
            if(!found){
                cout << "User not found " << endl;
            }
        }else if(choice==3){
            
            break;
        }else{
            cout << "Invalid choice " << endl;
        }
    }
    
    for(int i=0;i<userCount; i++){
        delete [] users[i].username;
        delete [] users[i].encryptedPassword;
    }
    
    return 0;
}