// https://leetcode.com/problems/longest-palindromic-substring/
// tc - O(n^2) Sc-O(1)

string longestPalindrome(string s) {
    int n = s.length();
    int ans = 0;
    string str = "";
    for(int i=0;i<n;i++){
        int left = i;
        int right = i;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        if((right-left-1)>ans){
            ans=right-left-1;
            str = s.substr(left+1,ans);
        } 
        left=i;
        right=i+1;
        while(left>=0 && right<n && s[left]==s[right]){
            left--;
            right++;
        }
        if((right-left-1)>ans){
            ans=right-left-1;
            str = s.substr(left+1,ans);
        }
    }
    return str;
}
