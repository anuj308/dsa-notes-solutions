#include <bits/stdc++.h>
using namespace std;
// ---------------------------------
int lowerBound(vector<int>& arr,int m,int val){
    int low = 0;
    int high = m-1;
    int ans =m;
    while(high>=low){
        int mid = (high+low)/2;
        if(arr[mid]>=val){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix) {
     // tc - O(N)
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;
    int count = -1;
    for(int i=0;i<n;i++){
        int c = m - lowerBound(matrix[i],m,1); 
        // cout << c << lowerBound(matrix[i],m,1) << endl;
        if(c > count){
            count = c;
            ans = i;
        }
    }
    return ans;
}
// ------------------------------- tc below  - O(N) + O(log N)
 bool search(vector<int>& arr,int n,int val){
    int low = 0;
    int high = n-1;
    while(high>=low){
        int mid = (high+low)/2;
        if(arr[mid]==val) return true;
        if(arr[mid]<val){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // tc - O(N)
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = 0;
    int count = -1;
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=target && matrix[i][m - 1]>=target){
            if(search(matrix[i],m,target)){
                return true;
            }
        }   
    }
    return false;
}
    // ----------------------------
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    int r = 0;
    int c = cols - 1; // top right
    while(r < rows && c>=0){
        if(matrix[r][c] == target){
            return true;
        }
        if(matrix[r][c]>target){
            c--;
        }else{
            r++;
        }
    }

    return false;
}

int median(vector<vector<int>> &mat) { // brute force 
    // code here
    int n = mat.size();
    int m = mat[0].size();
    vector<int> arr;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr.push_back(mat[i][j]);
        }
    }
    sort(arr.begin(),arr.end());
    return arr[(n*m)/2];
}
int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}