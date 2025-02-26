#include <bits/stdc++.h>
using namespace std;

void fun1(int i,int c){
    if(i>c){
        return;
    }
    cout << "anuj" << endl; 
    i++;
    fun1(i,c);
}

void fun2(int i,int n){
    if(i>n){
        return;
    }
    cout << i << endl;
    fun2(i+1,n);
}

void fun3(int n){
    if(n<1){
        return;
    }
    cout << n << endl;
    fun3(n-1);
}

void fun4(int i,int n){
    if(i<1){
        return;
    }
    fun4(i-1,n);
    cout << i;
}

void fun5(int i,int n){
    if(i>n){
        return;
    }
    fun5(i+1,n);
    cout << i  << endl;
}

void fun6(int sum,int i){
    if(i<1){
        cout << "sum: " << sum << endl;
        return;
    }
    fun6(sum+i,i-1);
}

int fun7(int n){
    if(n==0){
        return 0;
    }
    return n + fun7(n-1);
}

int fun8(int n){
    if(n==1){
        return 1;
    }
    return n * fun8(n-1);
}

void fun9(int arr[],int l,int r){
    if(l>=r){
        return;
    }
    swap(arr[l],arr[r]);
    fun9(arr,l+1,r-1);
}

void fun10(int i,int arr[],int n){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    fun10(i+1,arr,n);
}

bool fun11(string &s,int i){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]){
        return false;
    }
    return fun11(s,i+1);
}

int fun12(int n){// fibinacci
    if(n<=1){
        return n;
    }
    return fun12(n-1) + fun12(n-2);
}

bool recursion(string &s,int i){
    int n = s.size();
    if(i>=n/2) return true;
    if(s[i]!=s[n-i-1]) return false;
    return recursion(s,i+1);
}

bool isPalindrome(string s) {
    string newString;
    for(char c : s){
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
            newString+= tolower(c);
        }
    }
    cout << "the newString: " << newString << endl;
    return recursion(newString,0);
}

long long factorial(long long n){
    if(n==1) return 1;
    return n*factorial(n-1);
}  

vector<long long> factorialNumbers(long long n) {
    vector<long long> ans;
   for(int i=1;i<=n;i++){
       long long f = factorial(i);
       if(f <= n){
           ans.push_back(f);
       }else{
           break;
       }
   }
   return ans;
}

int sumOfSeries(int n) {
    if(n==1) return 1;
    return n*n*n + sumOfSeries(n-1);
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b

    // cout << "anuj";

    //recurison
    // print name n times with recursion
    // int c;
    // cin >> c;
    // fun1(1,c);

    // print 1 to n
    // int n;
    // cin >> n;
    // fun2(1,n);

    // print n to 1
    // int n;
    // cin >> n;
    // fun3(n);

    // print 1 to N but without i+1 - backtracking
    // int n;
    // cin >> n;
    // fun4(n,n);

    // print n to 1 by backtraking or without i-1
    // int n;
    // cin >> n;
    // fun5(1,n);

    // sumation of first n numbers
    // int n;
    // cin >> n;
    // with parameters
    // fun6(0,n);
    // without parameters
    // cout << "sum: " << fun7(n);

    // factorial of n
    // int n;
    // cin >> n;
    // cout << "factorial: " << fun8(n) << endl;

    // reverse an array 
    // int n;
    // cin >> n;
    // int arr[n];
    // for(int i=0;i<n;i++){ 
    //     cin >> arr[i];
    // }
    // fun9(arr,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // fun10(0,arr,n);
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    // check if a string is palindrome - string on reverse stays the same
    // string s = "madams";
    // cout << fun11(s,0);

    //  multipe recursion calls
    // int n;
    // cin >> n;
    // cout << "fibonacci of " << n << "th number: " << fun12(n) << endl;

    // 125. Valid Palindrome
    //A phrase is a palindrome if, after converting all uppercase letters into 
    //lowercase letters and removing all non-alphanumeric characters, it reads 
    // the same forward and backward. Alphanumeric characters include letters and numbers.

    //Given a string s, return true if it is a palindrome, or false otherwise.
    // string s ="A man, a plan, a canal: Panama";
    // cout << s << " is a isPalindrome " << isPalindrome(s);

    // Factorials Less than or Equal to n
    // int n;
    // cin >> n;
    // cout << "Factorials Less than or Equal to " << n << " are ";
    // vector<long long> arr = factorialNumbers(n);
    // for(long long n : arr){
    //     cout << n << " ";
    // }
    // cout << endl;

    // Sum of first n terms - Given an integer n, calculate the sum of series 13 + 23 + 33 + 43 + … till n-th term.
    // int n;
    // cin >> n;
    // cout << "Sum of first "  << n << " terms: " << sumOfSeries(n) << endl;  

    return 0;
}