#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> mergeOverlappingIntervalsBruteForce(vector<vector<int>> &arr){
    // tc - O(2N) + O(NLog N) , sc O(N)
    sort(arr.begin(),arr.end());
    int n = arr.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=arr[i][0];
        int end=arr[i][1];
        
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(end>=arr[j][0]){
                end = max(end,arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<arr[i][0]){
                ans.push_back(arr[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // tc - O(N) sc - O(N)
    vector<int> newArr(m+n);
    for(int i=0;i<m;i++){
        newArr[i]=nums1[i];
    }
    int i=0;
    int j=0;
    int c=0;
    while(i<m && j<n){
        if(newArr[i]<nums2[j]){
            nums1[c]=newArr[i];
            i++;
            c++;
        }else{
            nums1[c]=nums2[j];
            j++;
            c++;
        }
    }

    for(int k=i;k<m;k++){
        nums1[c]=newArr[i];
        i++;
        c++;
    }

    for(int y=j;y<n;y++){
        nums1[c]=nums2[j];
        j++;
        c++;
    }
}

vector<int> findMissingRepeatingNumbersMe(vector < int > a) {
    // tc - O(N Log N) sc - O(N) - by me
    map<int,int> mpp; // number, count

    for(int i=0;i<a.size();i++){
        mpp[a[i]]++;
    }
    int q=-1,p=-1;
    int ind=1;
    for(auto it : mpp){
        if(it.second==2) p = it.first;
        if(it.first!=ind && q==-1) q = ind;
        // cout << ind << " " << it.first << endl;
        ind++;
    }
    if(q==-1) q = ind;
    return {p,q};
}
vector<int> findMissingRepeatingNumbersBetter(vector < int > a) {
    // tc - O(N) sc - O(N)
    int missing=-1;
    int repeating=-1;
    int n = a.size();
    int arr[n+1]={0};
    for(int i=0;i<n;i++){
        arr[a[i]]+=1;
    }
    for(int i=1;i<n+1;i++){
        if(arr[i]==0) missing = i;
        if(arr[i]==2) repeating = i;
        if(missing!=-1 && repeating!=-1){
            break;
        }
    }
    return {repeating,missing};
}

// #include <bits/stdc++.h>
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    // tc - O(N) sc - O(1)
    // x is repeating, y is missing
    // e1 -- sum of arr - sum of 1 to n - x - y
    // e2 -- sum of square of arr - sum of square of 1 to n -- x^2 - y^2
    long long n = a.size();
    long long sn1 = n*(n+1)/2;
    long long sn2 = (n*(n+1)*(2*n+1))/6;
    long long s1=0,s2=0;
    for(int i=0;i<n;i++){
        s1+=a[i];
        s2+=(long long)a[i]*(long long)a[i];
    }
    long long val1 = s1 - sn1; // x - y
    long long val2 = s2 - sn2; // (x - y)(x + y)
    val2 = val2/val1; // x + y
    long long x = (val1+val2)/2; // [(x - y) + (x + y)]/2 -- 2x/2
    long long y = x - val1;
    return {(int)x,(int)y};
}
int inversionCountBruteForce(vector<int> &arr) {
    // tc - O(N^2) sc - O(1) by me
    int n = arr.size();
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(i<j && arr[i]>arr[j]){
                count++;
            }
        }
    }
    return count;
}
int merge(vector<int>& arr,int low,int mid,int high){
    int cnt=0;      
    int n1 = mid - low +1;
    int n2 = high - mid;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<n1;i++){
        arr1.push_back(arr[low + i]);
    }
    for(int i=0;i<n2;i++){
        arr2.push_back(arr[mid + 1 + i]);
    }
    int i=0,j=0,k=low;
    
    while(i < n1 && j < n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            k++;
            i++;
        }else{
            arr[k]=arr2[j];
            k++;
            j++;
            cnt+=(mid-(low+i)+1); // add all the element right of arr1[i]
            // as they are greater
        }
    }
    while(i < n1){
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while(j< n2){
        arr[k]=arr2[j];
        k++;
        j++;
    }
    return cnt;
}
int mergeSort(vector<int>& arr,int low,int high){
    int cnt=0;
    if(high>low){
        int mid = (high+low)/2;
        cnt+=mergeSort(arr,low,mid);
        cnt+=mergeSort(arr,mid+1,high);
        cnt+=merge(arr,low,mid,high);
    }
    return cnt;
}
int inversionCount(vector<int> &arr) {
    // tc - O(N log N) sc - O(N)
    int n = arr.size();
    return mergeSort(arr,0,n-1);
}

int teamBruteForce(vector <int> & skill, int n)
{
   // tc - O(N^2), sc -O(1)
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((long long)skill[i]>(long long)2*skill[j]){
                ans++;
            }
        }
    }
    return ans;
}

void mergeProduct(vector<int>& arr,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    int c=0;
    for(int i=low;i<=high;i++){
        arr[i]=temp[c];
        c++;
    }
    // cout << low << " " << mid << " " << high  << " " << cnt << endl;
}

int countPairs(vector<int>& arr,int low, int mid,int high){
    int right = mid + 1;
    int cnt=0;
    for(int left=low;left<=mid;left++){
        while(right<=high && arr[left]>2*arr[right]){
            right++;
        }
        cnt+=( right - (mid + 1));
    }
    return cnt;
}

int mergeSortProduct(vector<int>& arr,int low,int high){
    int cnt=0;
    if(high>low){
        int mid = (high+low)/2;
        cnt+=mergeSortProduct(arr,low,mid);
        cnt+=mergeSortProduct(arr,mid+1,high);
        cnt+=countPairs(arr,low,mid,high);
        mergeProduct(arr,low,mid,high);
    }
    return cnt;
}

int team(vector <int> & skill, int n)
{
   // tc - O(2*NLog N), sc -O(N)
       
    return mergeSortProduct(skill,0,n-1);
}

int subarrayWithMaxProductbetter(vector<int> &arr){
    // tc - O(N^2), sc -O(1);
    int n = arr.size();
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        int sum=1;
        for(int j=i;j<n;j++){
            sum*=arr[j];
            maxi=max(maxi,sum);
        }
    }
    return maxi;
}
int subarrayWithMaxProduct(vector<int> &nums){
    // tc - O(N), sc -O(1);
    
    int n = nums.size();
    int ans=INT_MIN;
    int prefix=1;
    int suffix=1;

    for(int i=0;i<n;i++){
        if(suffix==0) suffix=1;
        if(prefix==0) prefix=1;

        prefix*=nums[i];
        suffix*=nums[n-1-i];
        ans=max(ans,max(suffix,prefix));
    }
    return ans;
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}