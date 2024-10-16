// Single File Programming Question
// Problem Statement



// Dhaya is building a playlist manager for your favourite movies using a circular header linked list. Each node in the list represents a movie, and the playlist loops back to the beginning after the last movie. 



// The playlist manager should allow you to perform operations such as adding movies at the front and end, removing movies from the front and end, and displaying the current playlist.



// Company Tags: TCS interview.

// Input format :
// The first line of input consists of an integer N, representing the number of movies to insert at the front of the playlist.

// The next N lines consist of the movies' titles to be inserted at the front.

// The following line consists of an integer M, representing the number of movies to insert at the end of the playlist.

// The next M lines consist of the titles of the movies to be inserted at the end.

// Output format :
// The output consists of the following parts:

// The current playlist is displayed as a circular header-linked list.

// The number of nodes (movies) in the playlist.

// If a movie is deleted from the front and end, the deleted element is displayed.

// The updated playlist after deletion.

// The number of nodes (movies) in the playlist.



// Refer to the sample output for specifications.

// Code constraints :
// The movie titles will be alphanumeric strings of a maximum length of 100 characters.

// The maximum number of movies in the playlist is 100.

// Sample test cases :
// Input 1 :
// 4
// Movie 1
// Movie 2
// Movie 3
// Movie 4
// 2
// Movie 5
// Movie 6
// Output 1 :
// |Movie 4| --> |Movie 3| --> |Movie 2| --> |Movie 1| --> |Movie 5| --> |Movie 6| --> 
// No of nodes in the CLL is 6
// Deleted element: Movie 4
// Deleted element: Movie 6
// |Movie 3| --> |Movie 2| --> |Movie 1| --> |Movie 5| --> 
// No of nodes in the CLL is 4
// Input 2 :
// 3
// The Avengers
// Iron Man
// Thor
// 1
// Spiderman: Far from home
// Output 2 :
// |Thor| --> |Iron Man| --> |The Avengers| --> |Spiderman: Far from home| --> 
// No of nodes in the CLL is 4
// Deleted element: Thor
// Deleted element: Spiderman: Far from home
// |Iron Man| --> |The Avengers| --> 
// No of nodes in the CLL is 2
// Input 3 :
// 1
// Spiderman: Homecoming
// 4
// Harry Potter and the Prisoner of Azkaban
// Harry Potter and the Goblet of Fire
// Harry Potter and the Order of the Phoenix
// Harry Potter and the Half-Blood Prince
// Output 3 :
// |Spiderman: Homecoming| --> |Harry Potter and the Prisoner of Azkaban| --> |Harry Potter and the Goblet of Fire| --> |Harry Potter and the Order of the Phoenix| --> |Harry Potter and the Half-Blood Prince| --> 
// No of nodes in the CLL is 5
// Deleted element: Spiderman: Homecoming
// Deleted element: Harry Potter and the Half-Blood Prince
// |Harry Potter and the Prisoner of Azkaban| --> |Harry Potter and the Goblet of Fire| --> |Harry Potter and the Order of the Phoenix| --> 
// No of nodes in the CLL is 3


#include <iostream>
#include <string>

class Node {
public:
    std::string title;
    Node* next;

    Node(const std::string& title) : title(title), next(nullptr) {}
};

class CircularLinkedList {
private:
    Node* head;
    int count;

public:
    CircularLinkedList() : head(nullptr), count(0) {}

    void insertAtFront(const std::string& title) {
        Node* newNode = new Node(title);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        count++;
    }

    void insertAtEnd(const std::string& title) {
        Node* newNode = new Node(title);
        if (!head) {
            head = newNode;
            newNode->next = head; // Point to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        count++;
    }

    std::string removeFromFront() {
        if (!head) return ""; // List is empty
        Node* toDelete = head;
        std::string title = head->title;

        if (head->next == head) {
            head = nullptr; // List becomes empty
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head; // Update last node's next
        }
        delete toDelete;
        count--;
        return title;
    }

    std::string removeFromEnd() {
        if (!head) return ""; // List is empty
        Node* temp = head;
        std::string title;

        if (head->next == head) {
            title = head->title;
            delete head;
            head = nullptr; // List becomes empty
        } else {
            while (temp->next->next != head) {
                temp = temp->next;
            }
            title = temp->next->title;
            delete temp->next;
            temp->next = head; // Update last node's next
        }
        count--;
        return title;
    }

    void display() {
        if (!head) {
            std::cout << "Playlist is empty." << std::endl;
            return;
        }
        Node* temp = head;
        do {
            std::cout << "|" << temp->title << "| --> ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }

    int size() const {
        return count;
    }

    ~CircularLinkedList() {
        while (head) {
            removeFromFront();
        }
    }
};

int main() {
    CircularLinkedList playlist;

    int N;
    std::cin >> N;
    std::cin.ignore(); // Clear the newline after reading N

    for (int i = 0; i < N; ++i) {
        std::string title;
        std::getline(std::cin, title);
        playlist.insertAtFront(title);
    }

    int M;
    std::cin >> M;
    std::cin.ignore(); // Clear the newline after reading M

    for (int i = 0; i < M; ++i) {
        std::string title;
        std::getline(std::cin, title);
        playlist.insertAtEnd(title);
    }

    // Display the current playlist
    playlist.display();
    std::cout << "No of nodes in the CLL is " << playlist.size() << std::endl;

    // Deleting from front and end
    std::cout << "Deleted element: " << playlist.removeFromFront() << std::endl;
    std::cout << "Deleted element: " << playlist.removeFromEnd() << std::endl;

    // Display the updated playlist
    playlist.display();
    std::cout << "No of nodes in the CLL is " << playlist.size() << std::endl;

    return 0;
}
