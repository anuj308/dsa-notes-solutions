class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            
            unordered_map<int,int> freq;
    
            for(int n : nums){
                freq[n]++;
            }
    
            for(auto p : freq){
                if(p.second==1){
                    return p.first;
                }
            }
    
    
          return -1;
        }
    };

    // https://leetcode.com/problems/single-number/