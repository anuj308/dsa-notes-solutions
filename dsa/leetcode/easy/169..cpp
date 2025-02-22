class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            unordered_map<int,int> st;
            for(auto n : nums){
                st[n]++;
            }
            int n1 = nums.size();
            for(auto n : st){
                // cout << n.second << n1/2 << endl;
                if(n.second>(n1/2) ){
                    return n.first;
                }
            }
            return -1;
        }
    };

    // https://leetcode.com/problems/majority-element/description/