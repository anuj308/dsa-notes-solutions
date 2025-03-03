#include <iostream>
#include <vector>
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

void countingSort(vector<int> &arr, int n){
    int max = largestElement(arr,n);
    // cout << max << endl;
    // counting sort

    // vector<int> arr = {7,8 ,9,2 ,3};
    // int n = arr.size();
    // n = max;
    vector<int> arr1(max+1,0);

     // for(int i=1;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    for(int i=1;i<n;i++){
        arr1[arr[i]]+=1;
    }

    // for(int i=1;i<max+1;i++){
    //     cout << arr1[i] << " ";
    // }
    
    // cout << endl;
    for(int i=1;i<max+1;i++){
        arr1[i]+=arr1[i-1];
    }
    // cout << endl;
    // for(int i=1;i<max+1;i++){
    //     cout << i << " " << arr1[i] << endl;
    // }
    // cout << endl;
    vector<int> arr2(max+1,0);

    for(int i=n-1;i>0;i--){
        int a = arr2[arr1[arr[i]]];
        if(a!=0){
            arr2[arr1[arr[i]]-1] = arr[i];
        }else{
            arr2[arr1[arr[i]]]=arr[i];
        }
    }

    for(int i=1;i<=n;i++){
        arr[i]=arr2[i];
    }
}

int secondLargest(int n, vector<int> a){
    int firstLargest = a[0];
    int secondLargest = -9999999;
   
    for(int i=1;i<a.size();i++){
        if(a[i]>firstLargest){
            secondLargest = firstLargest;
            firstLargest = a[i];
        }
        else if(a[i]<firstLargest && a[i]>secondLargest){
            secondLargest = a[i];
        }
    }
    return secondLargest;
}

int secondSmallest(int n, vector<int> a){
    int firstSmallest = a[0];
    int secondSmallest = 9999999;
   
    for(int i=1;i<a.size();i++){
        if(a[i]<firstSmallest){
            secondSmallest = firstSmallest;
            firstSmallest = a[i];
        }
        else if(a[i]>firstSmallest && a[i]<secondSmallest){
            secondSmallest = a[i];
        }
        
    }
    return secondSmallest;
}

vector<int> getSecondOrderElements(int n, vector<int> a) {
    int firstLargest = a[0];
    int secondLargest = -9999999;
    int firstSmallest = a[0];
    int secondSmallest = 9999999;
    vector<int> ans(2,0);
    for(int i=1;i<a.size();i++){
        if(a[i]>firstLargest){
            secondLargest = firstLargest;
            firstLargest = a[i];
        }
        else if(a[i]<firstLargest && a[i]>secondLargest){
            secondLargest = a[i];
        }
        if(a[i]<firstSmallest){
            secondSmallest = firstSmallest;
            firstSmallest = a[i];
        }
        else if(a[i]>firstSmallest && a[i]<secondSmallest){
            secondSmallest = a[i];
        }
    }
    ans[0]=secondLargest;
    ans[1]=secondSmallest;
    return ans;
}

int isSorted(int n, vector<int> a) {
    
    for(int i=1;i<a.size();i++){
        if(a[i]<a[i-1]){
            return false;
        }
    }
    return true;
}

int removeDuplicates(vector<int> &arr, int n) {
    // optimal or best solution
    int c= 0;
    for(int i=1;i<n;i++){
        if(arr[c]!=arr[i]){
            c++;
            arr[c]=arr[i];
        }
    }
    return c+1;
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    vector<int> arr = {0,7,8 ,9,2 ,3};
    int n = arr.size();
    int max = largestElement(arr,n);
    // cout << max << endl;
    
    vector<int> ans = getSecondOrderElements(n,arr);

    cout << "secondLargest: " << ans[0] << endl;
    cout << "secondSmallest: " << ans[1] << endl;

    int ans1 =isSorted(n,arr);
    cout << ans1 << endl;

    
    return 0;
}