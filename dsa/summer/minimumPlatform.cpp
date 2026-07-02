// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// 1114 825 357 1415 54
// 1740 1110 2238 1535 2323

// 54   357   825   1114  1415
// 2323 2238  1110  1740  1535


// 2323

// 0 , add 2323
// priority_queue  2323
//  1, add 2238
// priority_queue  2238 2323
// 2 add 1110 as 825 < minHeap top
// priority_queue  1110 2238 2323
// 3 1114 as it greater than 1110 we remove 1110 and added 1740 dep
// priority_queue  1740 2238 2323
// 4 1415 as it less than 1740 add it to minHeap
// priority_queue  1535 1740 2238 2323
//  ans is max of minHeap or pq size at each step

// 4 ans

#include <bits/stdc++.h>
using namespace std;
// Tc - O(nlogn), Sc- O(n)
int minPlatform(vector<int>& arr, vector<int>& dep) {
    
    int ans = 1;
    int n = arr.size();
    vector<pair<int,int>> t;
    for(int i=0;i<n;i++){
        t.push_back({arr[i],dep[i]});
    }
    sort(t.begin(),t.end());
    int last = -1;
    int p = 0;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i=0;i<n;i++){
        if(minHeap.size()==0){
            int depTime = t[i].second;
            minHeap.push(depTime); // dep time
        }else {
            int arrTime = t[i].first;
            int depTime = t[i].second;
            if(minHeap.top()<arrTime){
                minHeap.pop();
                minHeap.push(depTime);
            }else minHeap.push(depTime);
        }
        if(minHeap.size() > ans) ans = minHeap.size();

    }
    
    return ans;
}



int main(){


    return 0;
}