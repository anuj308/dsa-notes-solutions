// https://cses.fi/problemset/task/1073

#include <bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> t;

    for(int i=0;i<n;i++){
        if(t.empty()){
            t.push_back(arr[i]);
        }else{
            auto it = upper_bound(t.begin(),t.end(),arr[i]);
            int ind = it - t.begin();
            int n1 = t.size();
            if(ind==n1) t.push_back(arr[i]);
            else t[ind]=arr[i];
        }
    }
    cout << t.size() << endl;
    return 0;
}


// brute force - tle
// https://cses.fi/problemset/task/1073

// #include <bits/stdc++.h>
// using namespace std;


// int main(){

//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     vector<int> t;

//     for(int i=0;i<n;i++){
//         if(t.empty()){
//             t.push_back(arr[i]);
//         }else{
//             int miniDiff = INT_MAX;
//             int ind = -1;
//             int n1 = t.size();
//             for(int j=0;j<n1;j++){
//                 if(arr[i] < t[j] && ((t[j]-arr[i]) < miniDiff)){
//                     miniDiff = t[j]-arr[i];
//                     ind = j;
//                 }
//             }
//             if(miniDiff!=INT_MAX) t[ind]=arr[i];
//             else t.push_back(arr[i]);
//         }
//     }
//     cout << t.size() << endl;
//     return 0;
// }