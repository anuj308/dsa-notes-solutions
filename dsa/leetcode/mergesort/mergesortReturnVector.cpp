// https://leetcode.com/problems/sort-an-array/description/
// not the best code as it beat only 34 %

class Solution {
public:
    void merge(vector<int>& nums, int low,int mid,int high){
        int i,j,k;
        int Lsize = mid - low + 1;
        int Rsize = high - mid;
        vector<int>L(Lsize);
        vector<int>R(Rsize);
        for(int i=0;i<Lsize;i++){
            L[i]=nums[low+i];
        }
        for(int j=0;j<Rsize;j++){
            R[j]=nums[mid+j+1];
        }
        i=0,j=0,k=low;
        while(i<Lsize && j<Rsize){
            if(L[i]<=R[j]){
                nums[k]=L[i];
                i++;
            }else{
                nums[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<Lsize){
            nums[k]=L[i];
            i++;
            k++;
        }
        while(j<Rsize){
            nums[k]=R[j];
            j++;
            k++;
        }
    }
    void mergeSort(vector<int>& nums,int low,int high){
        if(low < high){
            int mid = (high+low)/2;
            mergeSort(nums,low,mid);
            mergeSort(nums,mid+1,high);
            merge(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int high = nums.size();
        mergeSort(nums,0,high-1);
        return nums;
    }
};