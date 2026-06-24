#include <bits/stdc++.h>
using namespace std;

bool pos(long long h,vector<int>& arr,int k){
    long long c = 0;
    for(auto it : arr){
        c+=(arr[i]/h);
    }
    if(c>=k) return true;
    return false;
}
int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    long long sum = 0;
    for(auto it : arr) {
        sum+=it;
    }
    long long low = 1;
    long long high = sum;
    long long ans = 0;
    while(low<=high){
        long long mid = low - (low-high)/2;
        if(pos(mid,arr,k)){
            ans = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
    cout << ans << endl;
    return 0;
}