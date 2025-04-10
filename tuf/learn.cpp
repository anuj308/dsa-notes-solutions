#include<iostream>
using namespace std;
bool isDistinct(vector<int>& nums, int low,int high){ // tc - O(N)
    unordered_map<int,int> mpp; // int , value
    for(int i=low;i<=high;i++){
        mpp[nums[i]]++;
        if(mpp[nums[i]]!=1) return false;
    }
    return true;
}
int minimumOperations(vector<int>& nums) {
    // tc - O(N^2) worst case , sc - O(N)
    int ans = 0;
    int low = 0;
    int high = nums.size() - 1;
    while(isDistinct(nums,low,high)==false){
        if(low>=high) break;
        low+=3;
        ans++;
    }
    return ans;
} // 3396
int main(){
    cout << " anuj " ;

    return 0;
}