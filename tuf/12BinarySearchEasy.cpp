#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    // tc -O(log N) , sc -O(1)
    int n = nums.size();
    int high = n - 1;
    int low = 0;
    while(high>=low){
        int mid = (high+low)/2;
        if(nums[mid]==target) return mid;
        if(nums[mid]<target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int findFloor(vector<int>& arr, int x) {
    // O(log N) , sc -O(1)
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        if(arr[mid]<=x) {
            ans=mid;
            low = mid + 1;
        }
        if(arr[mid]>x) high = mid - 1;
        else low = mid + 1;
    }
    return ans;
    
}
vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    // tc - O(N Log N)
    int floorVal = -1;
    int ceilVal = INT_MAX;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(high>=low){
        int mid = (high+low)/2;
        if(arr[mid]>=x){
            ceilVal=min(ceilVal,arr[mid]);
        }
        if(arr[mid]<=x){
            floorVal=arr[mid];
            low = mid + 1;
        } 
        else{
            high = mid - 1;
        }
    }
    if(ceilVal==INT_MAX) ceilVal = -1;
    return {floorVal,ceilVal};
}
int upperBound(vector<int> &arr, int x, int n){
    
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while(high>=low){
        int mid = (high+low)/2;
        if(high==low && arr[mid]<=x) return mid + 1; // n=1 x = 10, [7] or n=5 x = 10 [1,2,5,6,10]
        if(arr[mid]>x){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int searchInsert(vector<int>& nums, int target) {
   int left = 0;
    int right = nums.size() - 1;
    while(left<=right){
        int mid = (left+right)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]<target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return left;
}
vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = INT_MAX;
        int last = -1;
        int low = 0;
        int high = n - 1;
        while(high>=low){
            int mid = (high+low)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target){
                    first=min(first,mid);
                }
                high = mid - 1; 
            }else{
                low = mid + 1;
            }
        }
        low = 0;
        high = n - 1;
        while(high>=low){
            int mid = (high+low)/2;
            if(nums[mid]>target){
                high = mid - 1; 
            }else{
                if(nums[mid]==target){
                    last=max(last,mid);
                }
                low = mid + 1;
            }
        }
        if(first==INT_MAX) first=-1;
        return {first,last};
    }
int search(vector<int>& arr, int target) {
    //  tc - O(log n)
    int n = arr.size();
    int low = 0;
    int high = n - 1;

    while(high>=low){
        int mid = (high+low)/2;
        if(arr[mid]==target) return mid;
        if(arr[low]<=arr[mid]){
            // sorted
            if(arr[low]<=target && target<=arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{ // not sorted
            if(arr[mid]<=target && target<=arr[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return -1;
}
int findMin(vector<int>& nums) {
    int n = nums.size();
    
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;
    while(high>=low){
        int mid = (high+low)/2;
        if(nums[low]<=nums[mid]){
            // left is sorted
            ans = min(ans,nums[low]);
            low = mid + 1;
        }else{
            // right part is sorted
            ans = min(ans,nums[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
int findKRotation(vector<int> &arr) {
    int n = arr.size();
    int low = 0;
    int index = INT_MAX;
    int ans = INT_MAX;
    int high = n - 1;
    
    while(high>=low){
        int mid = (high+low)/2;
        if(arr[low]<=arr[mid]){
            // left part is sorted
            if(arr[low] < ans){
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }else{
            // right part is sorted
            if(arr[mid] < ans){
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low = 1;
    int high = n - 2;
    while(high>=low){
        int mid = (high+low)/2;
        if(nums[mid - 1]!=nums[mid] && nums[mid]!=nums[mid + 1]){
            return nums[mid];
        }
        // even odd - same - eliminate left - target at right
        // odd even - same - eliminate right - target at left
        if( (mid%2!=0 && nums[mid - 1]==nums[mid]) || (mid%2==0 && nums[mid]==nums[mid + 1]) ){  // even odd
            low = mid + 1;
        }else{ // odd even - same
            high = mid - 1;
        }
    }
    return -1;
}
int findPeakElement(vector<int>& nums) {
    int n = nums.size();

    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1; // all this to not write etc edge cases in below

    int low = 1;
    int high = n - 2;
    while(high>=low){
        int mid = (high+low)/2;
        if(nums[mid - 1]<nums[mid] && nums[mid]>nums[mid + 1]){
            return mid;
        }
        if(nums[mid]<nums[mid+1]){
            low = mid + 1;
        }else{
            high = mid - 1;   
        }
    }
    return -1;
}
int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}