#include <bits/stdc++.h>
using namespace std;
int countDigit(long long num){
    int c=0;
    while(num){ // for counting n digit
        c++;
        num/=10;
    }
    return c;
}
bool isKpalindromic(long long x,int k){
    string s = to_string(x);
    sort(s.begin(), s.end());
    do {
        if (s[0] == '0') continue; // Skip leading zeros
        long long num = stoll(s);
        if (num % k != 0) continue;
        // Check if palindrome
        string str = to_string(num);
        bool is_pali = true;
        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - 1 - i]) {
                is_pali = false;
                break;
            }
        }
        if (is_pali) {
            return true;
        }
    } while (next_permutation(s.begin(), s.end()));
    return false;
}

long long countGoodIntegers(int n, int k) {
    long long nstart = pow(10,n-1);
    long long nend = n;
    nend = pow(10,n) - 1; // if n = 1 - nend = 9 , n = 2 - nend = 99 ...
    long long goodCount = 0;
    // cout << nend << endl;
    for(long long x=nstart;x<=nend;x++){
        if(isKpalindromic(x,k)){
            // cout << x << endl;
            goodCount++;
        }
    }
    return goodCount;
}
int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    cout << countGoodIntegers(5,6);

    // cout << isKpalindromic(400,4);
    // cout << "Askda";
    // // int goodCount=0;
    //  int x = 110;
    // vector<int> arr;
    // int xc = 3; // count digit
    // int k = 2;
    // stringstream ss;
    // ss << x;
    // string s = ss.str();
    // unordered_map<long long,int> mpp;
    // for(long long i=0;i<xc;i++){
    //     if(s[i]=='0') continue;
    //     for(int j=0;j<xc;j++){
    //         string st = "";
    //         st += s[i];
    //         if(i!=j) st += s[j];
    //         for(int h=0;h<xc;h++){
    //             if(h!=i && h!=j){
    //                 st+=s[h];
    //             }   
    //         }
    //         long long num = stoll(st);
    //         if(mpp.find(num)!=mpp.end()){
    //             continue;
    //         }
    //         mpp[num]++;
    //         cout << num << " " << isKpalindromic(num,k) << endl;
    //     }
       
    // }
    // for(auto c : arr){
    //     cout << c << " ";
    // }

    return 0;
}