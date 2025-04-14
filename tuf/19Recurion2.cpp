#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) { 
    double ans = 1.0;
    long long nu = n;
    if(nu<0) nu = -1*nu;
    while(nu){
        if(nu%2==0) {
            x = x*x;
            nu = nu/2;
        }else{
            ans = ans*x;
            nu = nu - 1;
        }
    }
    if(n<0) ans = (double) 1.0/(double) ans;
    return ans;
}
int main(){
    return 0;
}