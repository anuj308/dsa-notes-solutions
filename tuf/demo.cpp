#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr, int n) {
    int ans =0;
    for(int i=0;i<n;i++){
        if(arr[i]>ans){
            ans = arr[i];
        }
    }
    return ans;
}


int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    vector<int> arr = {7,8 ,9,2 ,3};
    int n = arr.size();
    cout << largestElement(arr,n);
    return 0;
}