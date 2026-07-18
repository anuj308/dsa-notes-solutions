// https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1

// tc - O(2^n) , sc- O(n) for answer
vector<string> binstr(int n) {
    long long total = 1LL << n; // 2 ^ n
    
    vector<string> ans;
    for(int i=0;i<total;i++){
        
        string s = "";
        for(int bit = n-1;bit>=0;bit--){
            s+=((i & (1LL << bit )) ? "1" : "0");
        }
        ans.push_back(s);
    }
    return ans;
}