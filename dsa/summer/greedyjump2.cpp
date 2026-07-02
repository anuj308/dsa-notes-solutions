// https://leetcode.com/problems/jump-game-ii/
#include <bits/stdc++.h>
using namespace std;

// Tc- O(n) , Sc- O(1)
int jump(vector<int>& nums) {
    int n = nums.size();
    int jump = 0;
    int currEnd = 0;
    int farthest = 0;

    for(int i=0;i<n-1;i++){
        farthest = max(farthest,nums[i]+i);

        if(i==currEnd){
            jump++;
            currEnd= farthest;
        }
    }
    return jump;
}

int main(){


    return 0;
}