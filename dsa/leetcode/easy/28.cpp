// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    int strStr(string haystack, string needle) {
    int ans = -1;
    int c =0;
    int n = needle.length();
    if(haystack.length()<n){
        return -1; // not possible
    }
    for(int p =0;p<haystack.length();p++){
        if(haystack[p]==needle[0]){
            cout << "matched loop starting at index" << p << endl ;
            c=0;
            ans=-1;
            for(int a =p;a<haystack.length();a++){
                if(haystack[a]==needle[c]){
                    if(c==0){
                        ans=a;
                        cout << " first match " << p << a << endl;
                    }
                    c++;
                    cout << "it matched " << p << a<< "c ="<<c << endl;
                    if(c==n){
                        cout << " we got the answer" << endl;
                        return ans;
                    }
                }else{
                    break;
                    // if(c>0){
                    //     c=0;
                    //     ans=-1;
                    //     cout << "matching breaked" << ans << endl;
                    // }
                    // cout << "not matched" << endl;
                }
                cout << "one loop" << endl;
            }
        }
    }
    
    return -1;
}
};