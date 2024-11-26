// // Single File Programming Question
// Problem Statement



// Virat is given a group of individuals, and he wants to identify if there is an influential individual within the group. An influential individual is defined as someone who is followed by more people than they follow.



// He is provided with a list of follow-up relationships among the individuals in the form of a matrix. Your task is to help Virat determine if there is an influential individual and, if so, find their index within the group.



// Write a program to solve this problem using Warshall's Algorithm. 

// Input format :
// The first line of input consists of an integer N, representing the number of individuals in the group.

// The following N lines will contain N space-separated integers, representing the following relationship matrix for the individuals.

// Output format :
// If an influential individual is found, print "Influential Individual: X," where X is the index (0-based) of the influential individual.

// Otherwise, print "There is no influential individual in the group".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The test cases will fall under the following constraints:

// 1 ≤ N ≤ 10

// Each element of the relationship matrix is either 0 or 1.

// Sample test cases :
// Input 1 :
// 4
// 0 1 1 0
// 0 0 1 0
// 0 0 0 0
// 0 0 1 0
// Output 1 :
// Influential Individual: 2
// Input 2 :
// 5
// 0 1 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 0 0 0 0 1
// 0 0 0 0 0
// Output 2 :
// There is no influential individual in the group
// Input 3 :
// 3
// 0 1 1
// 0 0 0
// 0 1 0
// Output 3 :
// Influential Individual: 1
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output w

// 2 case did not pass as i can't unserdstand  testcase the question  
    // You are using GCC
    int findInfluentialIndividual(int acquaintances[MAX_N][MAX_N], int n) {
        
        int following[n]={0};
        int followers[n]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(acquaintances[i][j]==1){
                    following[i]++;
                    followers[j]++;
                }
            }
        }

        for(int i=0;i<n;i++){

            if(followers[i]>following[i]){
                return i;
            }
        }
     
        return -1;
    }
    
    int main() {
    int n;
    cin >> n;
    
    int acquaintances[MAX_N][MAX_N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> acquaintances[i][j];
        }
    }

    int influentialIndividualIndex = findInfluentialIndividual(acquaintances, n);

    if (influentialIndividualIndex != -1) {
        cout << "Influential Individual: " << influentialIndividualIndex;
    } else {
        cout << "There is no influential individual in the group";
    }

    return 0;
}