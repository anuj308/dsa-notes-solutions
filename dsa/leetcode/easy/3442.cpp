class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mpp;

        for(auto it : s){
            mpp[it]++;
        }

        int oddMax = -1;
        int evenMin = INT_MAX;

        for(auto it : mpp){
            if(it.second%2==0){
                evenMin = min(evenMin,it.second);
            }else{
                oddMax = max(oddMax,it.second);
            }
        }
        return oddMax - evenMin;
    }
};