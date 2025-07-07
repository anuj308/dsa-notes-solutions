vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int n = nums.size();
    temp.push_back(nums[0]);
    for(int i=1;i<n;i++){
        if((nums[i]-nums[i-1])<=k && (i+1)%3!=0){
            temp.push_back(nums[i]);
        }
        if((i+1)%3==0){
            if((nums[i]-nums[i-1])<=k && (nums[i]-nums[i-2])<=k){
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }else{
                break;
            }
            temp.clear();
            i++;
            temp.push_back(nums[i]);
        }
    }
    if(ans.size()==n/3) return ans;
    vector<vector<int>> ans1;
    return ans1;
}