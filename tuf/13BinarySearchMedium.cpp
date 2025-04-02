#include <bits/stdc++.h>
using namespace std;


int floorSqrt(int n) {
    int low = 1;
    int high = n;
    int ans = 1;
    
    while(high>=low){
        int mid = (high+low)/2;
        if(mid*mid<=n){
            ans=mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}
int funMul(int mid,int n){
    int ans=1;
    while(n--){
        ans*=mid;
    }
    return ans;
}
int nthRoot(int n, int m) {
    // Code here.
    int ans = -1;
    int low = 1;
    int high = m;
    while(high>=low){
        int mid = (high+low)/2;
        if(funMul(mid,n)==m) return mid;
        if(funMul(mid,n)<m){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}
// ----------------------------------------------------------------------
int maxArr(vector<int>& arr){
    int n = arr.size();
    int ans = -1;
    while(n--){
        ans=max(ans,arr[n]);
    }
    return ans;
}
long long totalTimeForEatting(vector<int>& arr,int k){
    int n = arr.size();
    long long ans = 0;
    while(n--){
        ans+=ceil((double)arr[n]/k);
        // cout << ans << " " << n << " " << k << "in fun" << endl;
    }
    return ans;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1;
    int high = maxArr(piles);
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        long long time =totalTimeForEatting(piles,mid);
        // cout << high << " " << time << " " << mid << endl;
        if(time<=h){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
// -0------------------------------------------------------------------------
int maxDay(vector<int>& bloomDay,int n){
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,bloomDay[i]);
    }
    return ans;
}
int minDay(vector<int>& bloomDay,int n){
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        ans=min(ans,bloomDay[i]);
    }
    return ans;
}
int flowerForkAdjacent(vector<int>& bloomDay,int adj,int day,int n){
    int ans = 0;
    int count = 0;
    int prev = -1;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            count++;
            if(i != (prev + 1)){
                count=1;
            }
            prev=i;
            if(count==adj){
                count=0;
                ans++;
            }
        }
    }
    return ans;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    
    int n = bloomDay.size();
    int low = minDay(bloomDay,n);
    int high = maxDay(bloomDay,n);
    // cout << low << " " << high << endl;
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        int a = flowerForkAdjacent(bloomDay,k,mid,n);
        // cout << a << " " << mid << " "
        if(a>=m){
            ans=mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
// ------------------------------------------------------------------------
int maxArrD(vector<int>& nums,int n){
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,nums[i]);
    }
    return ans;
}
int sumOfDivide(vector<int>& nums,int divisor,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+= ceil((double)nums[i]/divisor);
        // cout << ans << " " << nums[i] << divisor << endl;
    }
    return ans;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    int low = 1;
    int high = maxArrD(nums,n);
    int ans=-1;
    while(high>=low){
        int mid = (high+low)/2;
        int a = sumOfDivide(nums,mid,n);
        if(a<=threshold){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int capacityShipDays(vector<int>& weights,int capacity,int n){
    int days = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(weights[i]>capacity) return n+1; // as it not possible to ship
        count+=weights[i];
        if(count>capacity){
            count=weights[i];
            days++;
        }
    }
    if(count>0) return days + 1;
    return days;
}
int shipWithinDays(vector<int>& weights, int days) {
    int n = weights.size();
    int low = 1;
    int high = 25000000;
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        int a = capacityShipDays(weights,mid,n);
        if(a<=days){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int findKthPositive(vector<int>& arr, int k) {
    // https://leetcode.com/problems/kth-missing-positive-number/
    // brute force
    int n = arr.size();
    int count = 0;
    int ele=1;
    for(int i=0;i<n;i++){
        while(ele!=arr[i]){
            count++;
            if(count==k){
                return ele;
            }
            ele++;
        }
        ele++;
    } 
    while(count!=k){
        count++;
        if(count==k){
            return ele;
        }
        ele++;
    } 
    return -1;
}
bool possiableNDistance(vector<int>& stalls,int n,int dis,int cows){
    int cow = 1; // first cows at 0 index
    int prev = stalls[0];
    for(int i=1;i<n;i++){
        if((stalls[i] - prev )>= dis){
            prev = stalls[i];
            cow++;
        }
        if(cow==cows){
            break;
        }
    }
    if(cow==cows){
        return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int low = 1;
    int high = stalls[n-1] - stalls[0];
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        // cout << mid << " " << possiableNDistance(stalls,n,mid,k) << endl;
        if(possiableNDistance(stalls,n,mid,k)){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

// ------------ optimal
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // tc - O(log n)
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;
    int high = n*m - 1;
    while(high>=low){
        int mid = (high+low)/2;
        int i = mid/m;
        int j = mid%m;
        // cout << i << " " << j << " " << mid << endl;
        if(matrix[i][j]==target) return true;
        if(matrix[i][j]<target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }       
    return false; 
}
// ---------------------------- optimal
int arrMax(vector<int>& arr,int n){
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,arr[i]);
    }
    return ans;
}
int possiableNPage(vector<int> arr,int n, int page){
    int allocatedStudent = 1;
    int prev = arr[0];
    for(int i=1;i<n;i++){
        if((arr[i]+ prev )<=page){
            prev+=arr[i];
        }else{
           allocatedStudent++;
           prev=arr[i]; 
        }
    }
    return allocatedStudent;
}

int arrSum(vector<int>& arr,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=arr[i];
    }
    return ans;
}
int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int ans = INT_MAX;
    int low = arrMax(arr,n);
    int high = arrSum(arr,n);
    while(high>=low){
        int mid = (high+low)/2;
        // cout << low << " " <<  high << " " << mid << " " << possiableNPage(arr,n,mid) << endl;
        // cout << ans << endl;
        int p = possiableNPage(arr,n,mid);
        if(p<=m){
            ans = min(ans,mid);
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if(ans==INT_MAX) return -1;
    return ans;
}
// --------------
int maxArr(vector<int> nums,int n){
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,nums[i]);
    }
    return ans;
}
int sumArr(vector<int> nums,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=nums[i];
    }
    return ans;
}
int splitArrByNumber(vector<int> nums,int n,int splitNumber){
    int splitArr = 1;
    int prev = nums[0];
    for(int i=1;i<n;i++){
        if( (prev + nums[i]) <= splitNumber){
            prev += nums[i];
        }else{
            splitArr++;
            prev=nums[i];
        }
    }
    return splitArr;
}
int splitArray(vector<int>& nums, int k) {
    int n = nums.size();
    int low = maxArr(nums,n);
    int high = sumArr(nums,n);
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        int s = splitArrByNumber(nums,n,mid);
        if(s<=k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
// ------------------
int maxArr(vector<int> arr,int n){
    int ans = INT_MIN;
    for(int i=0;i<n;i++){
        ans = max(ans,arr[i]);
    }
    return ans;
}
int sumArr(vector<int> arr,int n){
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=arr[i];
    }
    return ans;
}
int paintPMax(vector<int> boards,int n,int paintPerMax){
    int painter = 1;
    int prev = boards[0];
    for(int i=1;i<n;i++){
        if( (prev + boards[i]) <= paintPerMax){
            prev+=boards[i];
        }else{
            painter++;
            prev=boards[i];
        }
    }
    return painter;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n = boards.size();
    int low = maxArr(boards,n);
    int high = sumArr(boards,n);
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        int p = paintPMax(boards,n,mid);
        if(p<=k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
// -----------------
int gasStation(vector<int> &arr, int n, double dis) {
    int gas = 0;
    double prev = arr[0];
    
    for (int i = 1; i < n; i++) {
        while ((prev + dis) < arr[i]) {
            gas++;
            prev += dis;
        }
        prev = arr[i];
    }
    
    return gas;
}

double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    double low = 1e-6, high = arr[n-1] - arr[0], ans = high;

    while ((high - low) > 1e-6) {  // Precision-based stopping condition
        double mid = (low + high) / 2.0;
        int requiredGasStations = gasStation(arr, n, mid);

        if (requiredGasStations <= k) {
            ans = mid; 
            high = mid;
        } else {
            low = mid; 
        }
    }
    return ans;
}
// ----------------- below better
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();

    int m1 =(n1+n2)/2; // odd , even m2
    int m2 = m1 - 1; // m1
    int i = 0;
    int j = 0;
    int c = 0;
    int m1el= -1;
    int m2el = -1;
    // cout << m1 << m2 << endl;
    while(i< n1 && j < n2){
        if(nums1[i]<=nums2[j]){
            if(c==m2){
                m2el = nums1[i];
            }
            if(c==m1){
                m1el = nums1[i];
            }
            i++;
        }else{
            if(c==m2){
                m2el = nums2[j];
            }
            if(c==m1){
                m1el = nums2[j];
            }
            j++;
        }
        c++;
    }

    while(i < n1){
        if(c==m2){
            m2el = nums1[i];
        }
        if(c==m1){
            m1el = nums1[i];
        }
        i++;
        c++;
    }
    while(j < n2){
        if(c==m2){
            m2el = nums2[j];
        }
        if(c==m1){
            m1el = nums2[j];
        }
        j++;
        c++;
    }
    // cout << m1el << " " << m2el << endl;
    if((n1+n2)%2==0){
        return (m1el+m2el)/2.0;
    }else{
        return (double)m1el;
    }
}


// ------------  better below
int kthElement(vector<int>& nums1, vector<int>& nums2, int k) {
    // code here
    int n1 = nums1.size();
    int n2 = nums2.size();

    int i = 0;
    int j = 0;
    int c = 1;

    while(i< n1 && j < n2){
        if(nums1[i]<=nums2[j]){
           if(c==k){
               return nums1[i];
           }
            i++;
        }else{
            if(c==k){
               return nums2[j];
           }
            j++;
        }
        c++;
    }

    while(i < n1){
       if(c==k){
           return nums1[i];
       }
        i++;
        c++;
    }
    while(j < n2){
       if(c==k){
           return nums2[j];
       }
        j++;
        c++;
    }
    return -1;
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}