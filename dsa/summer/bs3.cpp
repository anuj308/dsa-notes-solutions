// https://codeforces.com/contest/1873/problem/E

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool pos(ll x,vector<ll>& coral,ll w){
    ll c = 0;
    for(auto it : coral){
        if(it<x){
            if(c > w-(x-it)) return false;
            c+=(x-it);
        }
    }
    return true;
}
int main(){
    int t; // testcase
    cin >> t;
    for(int i=0;i<t;i++){
        ll n,w;
        cin >> n >> w;
        vector<ll> coral(n,0);
        ll low = 1;
        ll high = LLONG_MAX;
        for(ll j=0;j<n;j++){
            cin >> coral[j];
        }
        ll ans = 1;
        while(low<=high){
            ll mid = low - (low-high)/2;
            if(pos(mid,coral,w)){
                ans = max(ans,mid);
                low = mid + 1;
            }else high = mid - 1;
        }
        cout << ans << endl;
    }


    return 0;
}