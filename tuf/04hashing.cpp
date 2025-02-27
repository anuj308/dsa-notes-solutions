#include <bits/stdc++.h>
using namespace std;

vector<int> frequencyCount(vector<int>& arr) {
    int n = arr.size();
    vector<int> hash(n,0);
    
    for(int i=0;i<n;i++){
        hash[arr[i]-1]+=1;
    }
    return hash;
    
}

vector<int> getFrequencies(vector<int>& v) {
    
    map<int,int> mpp;
    for(int i=0;i<v.size();i++){
        mpp[v[i]]++;
    }
    vector<int> ans(2,0);
    int min = 999999999;
    int max = 0;
    for(auto it : mpp){
        if(it.second>max){
            ans[0]=it.first;
            max=it.second;
        }
        if(it.second<min){
            ans[1]=it.first;
            min=it.second;
        }
    }
    return ans;

}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    // hashing

    // int n;
    // cin >>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }

    // // precompute
    // int hash[12]={0};
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]+=1;
    // }

    // int q;
    // cin >> q;
    // while(q--){
    //     int v;
    //     cin >> v;
    //     // fetch
    //     cout << v << " is " << hash[v] << " times in the array" << endl;
    // }

    // if declare array global - max 10^7
    // if declare inside int main = max 10^6


    // Frequencies in a Limited Array - indexing from 1
    // vector<int> in={2,3,1,3,2,4,5,6,7};
    // vector<int> ans = frequencyCount(in);
    // for(int i=1;i<ans.size()+1;i++){
    //     cout << i << " " << ans[i-1] << endl;
    // }
  
    // charater array hashing ---------------
    // string s;
    // cin >> s;

    // precompute

    // int hash[256]={0};

    // for(int i=0;i<s.size();i++){
    //     hash[s[i]]++;
    // }

    // int q;
    // cin >> q;
    // while(q--){
    //     char c;
    //     cin >> c;
    //     cout << c << " is " << hash[c] << endl;
    // }

    // hashing with map so that - uses less space 
    // example if i have input of 1 3 6 9 in arr i have to take n=10 
    // but in map it will only take 4 space.
    // int n;
    // cin >>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }

    // // precompute
    // map<int,int> mpp;
    // for(int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    // }

    // // iterate in map - map always stores number in sorted manner
    // // but in unordered_map it will not store in sorted manner
    // for(auto it : mpp){
    //     cout << it.first << "->" << it.second << endl; 
    // }

    // int q;
    // cin >> q;
    // while(q--){
    //     int number;
    //     cin >> number;
    //     //fetch
    //     cout << number  << " is present " << mpp[number] << endl;
    // }


    //  Highest / Lowest Frequency Elements
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<int> ans = getFrequencies(arr);
    cout << "highest , lowest -> ";
    for(auto it : ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}