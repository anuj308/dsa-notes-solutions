
// https://leetcode.com/problems/palindromic-substrings/
// tc - O(n^2) Sc-O(1)
int countSubstrings(string s) {
    int n = s.length();
    int ans = 0;
    for(int i=0;i<n;i++){
        int left = i;
        int right = i;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
            ans++;
        }
        left = i;
        right = i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
            ans++;
        }
    }
    return ans;
}