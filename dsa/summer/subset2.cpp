// https://leetcode.com/problems/subsets-ii/

//  tc - O(n^2) , sc = O(n)
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int> path;
    backtrack(0,n,nums,path,ans);
    return ans;
}
void backtrack(int start,int& n,vector<int>& nums,vector<int>& path,vector<vector<int>>& ans){
    ans.push_back(path);
    for(int i=start;i<n;i++){
        if(i>start && nums[i-1]==nums[i]) continue;
        path.push_back(nums[i]);
        backtrack(i+1,n,nums,path,ans);
        path.pop_back();
    }
}