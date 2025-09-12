


// link https://leetcode.com/problems/minimum-operations-to-transform-string/
// tc - o(n), sc-O(1)
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        map<char,int> mpp;
        for(auto i : s){
            mpp[i]++;
        }
        int ans = 0;
        while(true){
            if(mpp.size()==1 && mpp.find('a')!=mpp.end()) break;
            for(auto it : mpp){
                if(it.first=='a') continue;
                else{
                    char nextChar = it.first+1;
                    if(it.first=='z') nextChar = 'a';
                    mpp[nextChar]+=mpp[it.first];
                    mpp.erase(it.first);
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};