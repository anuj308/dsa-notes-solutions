#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin >> n >> x;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first;
        arr[i].second=i;
    }
    
    sort(arr.begin(),arr.end());
    
    bool f = false;
    for(int i=0;i<n;i++){
        
        int low = i+1;
        int high = n-1;
        while(low<high){
            int sum = arr[i].first + arr[low].first + arr[high].first;
            if(sum>x){
                high--;
            }else if(sum<x){
                low++;
            }else{
                vector<int> ans = {arr[i].second+1,arr[low].second+1,arr[high].second+1};
                sort(ans.begin(),ans.end());
               cout << ans[0] << " " << ans[1]  << " "  << ans[2] << endl;
               f=true;
               break;
            }
        }
        if(f) break;
    }
    if(!f) cout << "IMPOSSIBLE" << endl;
    return 0;
}
