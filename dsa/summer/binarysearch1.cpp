// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool pos(vector<int>& arr,ll tim,ll target){
    ll ans = 0;
    for(auto it : arr){
        ans+=(tim/it);
        if(ans>=target) return true;
    }
    if(ans>=target) return true;
    return false;
}
int main() {
    
    int n,t;
    cin >> n >> t;
    vector<int> arr(n,0);
    ll maxi = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        if(arr[i] > maxi) maxi = arr[i];
    }
    
    ll low = 1;
    ll high = maxi*t;
    ll ans = 0;
    while(low<=high){
        ll mid = low - (low-high)/2;
        if(pos(arr,mid,t)){
            ans = mid;
            high = mid - 1;
        }else low = mid + 1;
    }
    
    cout << ans << endl;
    return 0;
}