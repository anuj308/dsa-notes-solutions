#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    int n;
    cin >> n;
    int arrn[n];
    int arrk[n];
    int arrp[n];

    for(int i=0;i<n;i++){
        cin >> arrn[i];
        cin >> arrk[i];
        cin >> arrp[i];
    }
    
    //   for(int i=0;i<n;i++){
    //     cout << arrn[i] << " " << arrk[i] << " " <<  arrp[i] << endl;
    // }

    for(int i=0;i<n;i++){
        double ans = ceil(abs(arrk[i])/(double)arrp[i]);
       
        if(ans>arrn[i]){
            cout << -1 << endl;
        }else{
            cout << (int)ans << endl;
        }
    }

    return 0;
}