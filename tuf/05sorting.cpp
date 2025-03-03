#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int n){
    int min;

    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[min]) min=j;
        }
        swap(arr[min],arr[i]);
        // int temp = arr[j];
        // arr[j]=arr[j+1];
        // arr[j+1]=temp;
    }
}

void bubbleSort(int arr[],int n){

    for(int i=n-1;i>0;i--){
        int didSwap=0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }
        }
        if(didSwap==0){
            break;
        }
    }
}

void insertionSort(int arr[],int n){

    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
        
    }
}

void merge(vector<int>& arr,int low,int mid,int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    
    while(left<=mid && right<=high){
        if(arr[left]>=arr[right]){
            temp.push_back(arr[right]);
            right++;
        }else{
            temp.push_back(arr[left]);
            left++;
        }
    }
    
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }   
}
    
void mergeSort(vector<int>& arr, int low, int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int>& arr, int low, int high) {
    if(low < high){
        int pIndex = partition(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}


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

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    // selction sort

    //  int n;
    //  cin >> n;
    //  int arr[n];
    //  for(int i=0;i<n;i++) cin >> arr[i];
    //  selectionSort(arr,n);
    //average/worst case/best case - O(n^2) - n((n-1)/2)

    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    // int n;
    // cin >> n;
    // int arr[n];
    // for(int i=0;i<n;i++) cin >> arr[i];

    // bubbleSort(arr,n);
     
    //  // best case - O(n) - it array is sorted
    // //average/worst case - O(n^2)
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }


    // int n;
    // cin >> n;
    // int arr[n];
    // for(int i=0;i<n;i++) cin >> arr[i];

    // insertionSort(arr,n);
     
    //  // best case - O(n) - it array is sorted
    // //average/worst case - O(n^2)
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++) cin >> arr[i];

    // mergeSort(arr,0,n-1);
    // // best/worst/avg case - O(nlog n) 
    // // space worst - O(n)
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    // quick sort
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for(int i=0;i<n;i++) cin >> arr[i];
   
    // quickSort(arr,0,n-1);
    // // time -  O(nlog n) 
    // // space - O(1) 
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    vector<int> arr = {0,7,8 ,9,2 ,3};
    int n = arr.size();
    int max = largestElement(arr,n);
    cout << max << endl;
    // counting sort

    countingSort(arr,n);

    for(int i=1;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}