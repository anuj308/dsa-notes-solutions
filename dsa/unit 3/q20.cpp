// Single File Programming Question
// Problem Statement



// Design a system for an emergency room where patients arrive with varying medical conditions, each assigned a severity score. Create a priority queue to manage patient treatment based on severity, ensuring those with higher scores are treated first. 



// Patients are dequeued in order of severity for treatment.

// Input format :
// The first line of input consists of an integer N, representing the number of patients in the emergency room.

// The next N lines consist of two space-separated values each:

// A string representing the patient's name.
// An integer value representing the severity score.
// Output format :
// For each patient being treated, the output displays a line: "Treating patient: X (Severity: Y)" where X is the patient's name and Y is the severity score.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ severity score ≤ 20

// Patient names are strings with a maximum length of 50 characters.

// Sample test cases :
// Input 1 :
// 6
// Frank 8
// Grace 1
// Hank 4
// Ivy 2
// Jack 6
// Karen 5
// Output 1 :
// Treating patient: Frank (Severity: 8)
// Treating patient: Jack (Severity: 6)
// Treating patient: Karen (Severity: 5)
// Treating patient: Hank (Severity: 4)
// Treating patient: Ivy (Severity: 2)
// Treating patient: Grace (Severity: 1)
// Input 2 :
// 5
// Alice 4
// Bob 6
// Carol 3
// David 7
// Eve 5
// Output 2 :
// Treating patient: David (Severity: 7)
// Treating patient: Bob (Severity: 6)
// Treating patient: Eve (Severity: 5)
// Treating patient: Alice (Severity: 4)
// Treating patient: Carol (Severity: 3)
// Input 3 :
// 7
// Liam 7
// Mia 5
// Noah 6
// Olivia 3
// Penelope 8
// Quinn 2
// Riley 4
// Output 3 :
// Treating patient: Penelope (Severity: 8)
// Treating patient: Liam (Severity: 7)
// Treating patient: Noah (Severity: 6)
// Treating patient: Mia (Severity: 5)
// Treating patient: Riley (Severity: 4)
// Treating patient: Olivia (Severity: 3)
// Treating patient: Quinn (Severity: 2)
// Note :