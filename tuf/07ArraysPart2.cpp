#include <bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int>& arr, int n) {
    int temp = arr[0];

    for(int i=1;i<n;i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
    return arr;
}

vector<int> rotateArrayk(vector<int>arr, int k) {
    // Write your code here.
    int n = arr.size();
    // k = n%k;
   
    vector<int>temp (k,0);
    for(int i=0;i<k;i++){
        temp[i]=arr[i];
    }
    for(int i=k;i<n;i++){
        arr[i-k]=arr[i];
    }
    for(int i=n-k;i<n;i++){
        arr[i]=temp[i - (n-k)];
    }
    return arr;
}

void rotateArrayRightK(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n){
            k=k%n;
        }
        vector<int> temp(k,0);
        for(int i=n-k;i<n;i++){
            temp[i-(n-k)]=nums[i];
        }
        for(int i=n-1;i>=k;i--){
            nums[i]=nums[i-k];
        }
        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }

vector<int> moveZeros(int n, vector<int> arr) {
    // optimal  
    int z =0;
    for(int i=0;i<n;i++){

        if(arr[i]!=0){
            arr[z]=arr[i];
            z++;
        }
    }
    for(int i=n-1;i>=n-(n-z);i--){
        arr[i]=0;
    }
    return arr;
}

vector < int > unionSortedArrayBruteForce(vector < int > a, vector < int > b) {
   int n1 = a.size();
    int n2 = b.size();
    set<int> unionAns;
    for(auto it : a){
        unionAns.insert(it);
    }
    for(auto it : b){
        unionAns.insert(it);
    }
    vector<int> ans;
    for(auto it : unionAns){
        ans.push_back(it);
    }
    return ans;
}

vector < int > unionSortedArray(vector < int > a, vector < int > b) {
    // optimal
    int n1 = a.size();
    int n2 = b.size();

    vector<int> unionAns;
    int i=0;
    int j=0;
    while(i< n1 && j< n2){
        if(a[i]<=b[j]){
            if(unionAns.size()==0 || unionAns.back() != a[i]){
               unionAns.push_back(a[i]);
            }
               i++;
        }else{
            if(unionAns.size()==0 || unionAns.back() != b[j]){
                unionAns.push_back(b[j]);
            }
                j++;
        }
    }
    while(i<n1){
        if(unionAns.size()==0 || unionAns.back() != a[i]){
            unionAns.push_back(a[i]);
        }
            i++;
    }
    while(j<n2){
        if(unionAns.size()==0 || unionAns.back() != b[j]){
            unionAns.push_back(b[j]);
        }
            j++;
    }


    return unionAns;
}

vector<int> findArrayIntersectionBruteForce(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    vector<int> vis(m,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr1[i]==arr2[j] && vis[j]==0){
                vis[j]=1;
                ans.push_back(arr1[i]);
                break;
            }
            if(arr2[j]>arr1[i]){
                break;
            }
        }
    }

    return ans;
}

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    vector<int> ans;
    int i=0;
    int j=0;
    while(i<n && j<m){
        if(arr1[i]<arr2[j]){
            i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }
        else{
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return ans;
}
int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    vector<int> arr = {1 ,3 ,6 ,11 ,12 ,17};
    vector<int> arr1 = {11 ,12 ,17};
    // vector<int> ans = rotateArrayk(arr,2); //O(n)

    // for(int i=0;i<ans.size();i++){
    //     cout << ans[i] << " ";
    // }
    // rotateArrayRightK(arr,3); // O(n)
    // for(int i=0;i<arr.size();i++){
    //     cout << arr[i] << " ";
    // }

    vector<int> ans1 = moveZeros(arr.size(),arr);

    vector<int> ans2 =unionSortedArrayBruteForce(arr,arr1); // O(n1 + n2 + n1logn + n2logn) sc - O(n1+n2) + O(n1+n2)
    vector<int> ans3 =unionSortedArray(arr,arr1); // O(n1+n2) sc -  O(n1+n2)

    int n = arr.size();
    int m = arr1.size();
    vector<int> ans4 = findArrayIntersectionBruteForce(arr,n,arr1,m); // O (n1*n2) , sc - O(n2)
    vector<int> ans5 = findArrayIntersection(arr,n,arr1,m); // tc - O(n1+n2) , sc -O(n1+n2) 
    for(auto it : ans4){
        cout << it << " ";
    }
    return 0;
}