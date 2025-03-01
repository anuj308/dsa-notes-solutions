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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
   
    quickSort(arr,0,n-1);
    // time -  O(nlog n) 
    // space - O(1) 
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}