// 3445

//  brute force highest optimised but gives tle
int maxDifference(string s, int k) {
    int ans = INT_MIN;
    int n = s.size();
    for(int i=0;i<=n-k;i++){
        unordered_map<char,int> mpp;
        for(int j=i;j<n;j++){
            mpp[s[j]]++;
            int maxOdd = -1;
            int minEven = INT_MAX;
            if((j-i+1)>=k){
                for(auto it : mpp){
                    if(it.second%2==0){
                        minEven = min(minEven,it.second);
                    }else{
                        maxOdd = max(maxOdd,it.second);
                    }
                }
                ans = max(ans,maxOdd - minEven);
            }
        }
    }
    return ans;
}