// 3 leetcode

// brute force , tc - O(N^2) sc - O(1) as hash Map is of 26 size;
class Solution {
public:
    int countUnique(string s,int start){
        unordered_map<char,int> mpp;
        int c = 0 ; // count
        int n = s.length();
        for(int i=start;i<n;i++){
            mpp[s[i]]++;
            if(mpp[s[i]]==2){
                return c;
            }
            c++; // count increment
        }
        return c;
    }
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            ans = max(ans,countUnique(s,i));
        }

        return ans;
    }
};

// optimal 1 , tc -  O(n) = O(2n) -- outer loop o(n) and inner while can max go to O(n) so 
//  total is O(2n) means O(n);

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int ans = 0;
        int n = s.length();
        unordered_map<char,int> mpp;
        int c = 0 ; // count
        int left = 0;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
            if(mpp[s[i]]==2){
                ans = max(ans,c);
                while(s[left]!=s[i]){
                    mpp[s[left]]--;
                    c--;
                    left++;
                }
                mpp[s[left]]--;
                c--;
                left++;
            }
            c++; // count increment
        }
        
        ans = max(ans,c);
        return ans;
    }
};

// Approach
// we have a mpp for storeing frequency of character
// we have left pointer or variable set to 0.
// we have c for count , ans for final answer.
// now we start for loop iterate over s string, storeing char in mpp.
// When we found duplicate char we look for that duplicate char s[i] from left in while loop and side by side decrementing the count and decrementing freq of those char in our mpp and incrementing left till we found that s[i] or duplicate char from left.

// when duplicate was found we updated our ans with c value if maximum

// In end we are also updating ans with c if maximum than previous as in for loop ans only get updated when found a duplicate so what if we don't found so that case we are doing it here.

// Thank you for Reading.

// written by me in solution for leetcode short explaination .