
// https://leetcode.com/problems/sort-characters-by-frequency/

// tc = o(nlogn), Sc-O(n)

static bool cmp(pair<char,int>& p1,pair<char,int>& p2){
    return p1.second > p2.second;
}
string frequencySort(string s) {
    int n = s.length();
    unordered_map<char,int> mpp;
    for(auto it : s) mpp[it]++;
    vector<pair<char,int>> vec(mpp.begin(),mpp.end());
    sort(vec.begin(),vec.end(),cmp);
    string ans = "";
    for(auto it : vec){
        for(int i=0;i<it.second;i++) ans+=it.first;
    }
    return ans;
}