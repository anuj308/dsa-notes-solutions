Single File Programming Question
Problem Statement



In a grocery store, customers join a single queue to check out. Implement a system using a linked list to manage this queue. When displaying, the order should be reversed, so the first customer to join appears last. The program should allow customers to join the queue and display the reversed queue.

Input format :
The first line of input consists of an integer n, representing the number of customers in the queue.

The next line consists of n space-separated integers, representing the customer positions.

Output format :
If the queue is not empty: Display the customer positions in reverse order.

If the queue is empty: A message stating that the queue is empty.



Refer to the sample output for the exact text and format.

Code constraints :
0 ≤ n ≤ 20

1 ≤ customer positions ≤ 1000

Sample test cases :
Input 1 :
3
5 10 15
Output 1 :
Queue: 15 10 5 
Input 2 :
6
10 15 20 25 30 35
Output 2 :
Queue: 35 30 25 20 15 10 
Input 3 :
0
Output 3 :
Queue is empty.
Note :
The program will be evaluated only after the “Submit Code” is clicked.
Extra spaces and new line characters in the program output will result in the failure of the test case.