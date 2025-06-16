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


// 1004 leetcode
//  brute force

class Solution {
public:
int longestOnes(vector<int>& nums, int k) {
    // tc - O(N^2) sc - O(1)
    int ans = 0;
    int n = nums.size();
    int k1 = k;
    for(int i=0;i<n;i++){
        int c = 0;
        k1 = k;
        for(int j=i;j<n;j++){
            if(nums[j]==1){
                c++;
            }else if(k1>0){
                c++;
                k1--;
            }else{
                ans = max(ans,c);
                break;
            }
        }
        ans = max(ans,c);
    }
    return ans;
}
};
// In this we have two loop we are find the maximum lemgth from each index 0 to n-1.
// And updating in ans.
// The inner loop we have c counter we increment it when nums[j] is 1 and till k>0 , k is no of flip we can do to 0 to make it 1 and count it.
// in else if k1>0 (k1 = k) we are decrementing k1 so that we can count till k only times.
// and in else we are updating our answer and breaking the loop and before return also we are updating the ans.
// optimal

// the code for counting is same a brute force
// only in else if we are pushing or storeing the index of filp Element
// And in else if queue is not empty we are getting the first Flip Element from q.front() and removing it by q.pop()
// And we have a start pointer or variable that store the index of start of our maximum consecutive ones answer.
// so till that firstFlip i mention in code lastFlip we decrement our counter (c) and increment our start and after this we just pushed or stored current index as fliped Element in queue.
// ans in else part means queue is empty means k = 0 so we are just updating the countter to Zero (0). i think you can understand this part just dry run the code.
// Thank you for Reading. if you have any doubt comment it.

// by me 
// https://leetcode.com/problems/max-consecutive-ones-iii/solutions/6832126/tc-on-sc-ok-optimal-explained-step-by-st-be8c/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int ans = 0;
        int n = nums.size();
        int c = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c++;
            }else if(k>0){
                c++;
                k--;
                q.push(i);
            }else{
                ans = max(ans,c);
                if(!q.empty()){
                    int lastFlip = q.front();
                    q.pop();
                    while(start!=lastFlip){
                        start++;
                        c--;
                    }
                    start++;
                    c--;
                    q.push(i);
                    c++;
                }else{
                    c=0;
                }
            }
        }
        ans = max(ans,c);
        return ans;
    }
};


// 904 
//  tc - O(n^2)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            pair<int,int> a = {-1,0};
            pair<int,int> b = {-1,0};
            for(int j=i;j<n;j++){
                if(fruits[j]==a.first) a.second+=1;
                else if(fruits[j]==b.first) b.second+=1;
                else if(a.first==-1){ 
                    a.first = fruits[j];
                    a.second += 1;
                }
                else if(b.first==-1) {
                    b.first = fruits[j];
                    a.second +=1;
                }
                else break;
            }
            int c = 0; // count
            if(a.first!=-1) c += a.second;
            if(b.first!=-1) c += b.second;
            ans = max(ans,c);
        }
        return ans;
    }
}

// sliding window
//  tc - O(2n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = INT_MIN;
        unordered_map<int,int> mpp;
        int c = 0;
        int left = 0;
        for(int j=0;j<n;j++){
            mpp[fruits[j]]++;
            while(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0){
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans,j-left+1);
        }
        return ans;
    }
};

// 424 
// tc  - O(n) sc - (1)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = INT_MIN;
        int n = s.size();
        int k1 = k;
        for(char alp='A';alp<='Z';alp++){
            queue<int> q; // storeing index of char changed to uppercase
            int count = 0;
            int left = 0;
            k = k1;
            for(int right=0;right<n;right++){
                if((char)s[right]==(char)alp){
                    count++;
                }else if(k>0){
                    q.push(right);
                    k--;
                    count++;
                }else{
                    ans = max(ans,count);
                    if(!q.empty()){
                        int lastChanged = q.front();
                        q.pop();
                        while(left!=lastChanged){
                            left++;
                            count--;
                        }
                        left++;
                        count--;
                        q.push(right);
                        count++;
                    }else{
                        count = 0;
                    }
                }
            }
            ans = max(ans,count);   
        }
        return ans;
    }
};


// 930 leetcode

// brute force tc - O(n^2)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += nums[j];
            if(sum==goal){
                ans++;
            }
            if(sum>goal) break;
        }
    }
    return ans;
}


//  prefix sum 
// tc - O(n) sc - O(n)
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int,int> prefixCount;
        int sum = 0;
        int ans = 0;
        prefixCount[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(prefixCount.find(sum - goal)!=prefixCount.end()){
                ans += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }
        return ans;
    }
};

// 1248
// brute force - Tc - TLE - O(n^2)
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        int odd = 0;
        for(int j=i;j<n;j++){
            if(nums[j]%2!=0) odd++;
            if(odd==k){
                ans++;
            }
        }
    }
    return ans;
}
//  tc - o(n), sc - o(n)
int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    int left = 0;
    int odd = 0;
    queue<int> q; // index
    for(int right=0;right<n;right++){
        if(nums[right]%2!=0){
            odd++;
            q.push(right);
        }
        if(odd==k){
            ans++;
            ans += q.front() - left;
        }
        if(odd>k){
            int ind = q.front();
            q.pop();
            odd--;
            left = ind+1;
            ans++;
            ans += q.front() - left;
        }
    }
    return ans;
}   

// https://drive.google.com/file/d/1-YyeDjQ0UCWTpAHiSf9TmulkqQX96Laa/view?usp=sharing
// 1358
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int left = 0;
        for(int right=0;right<n;right++){
            if(s[right]=='a') a++;
            else if(s[right]=='b') b++;
            else c++;
            while(a>=1 && b>=1 && c>=1){
                ans += (n - right);
                if(s[left]=='a') a--;
                else if(s[left]=='b') b--;
                else c--;
                left++;
            }
        }
        return ans;
    }
};

// for video visit leetcode solution or in drive 

// 1423 
// https://drive.google.com/file/d/1BAKr_iHhx7UpNPy3m-Uc4Y5QXj6UbHbx/view?usp=sharing
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); // tc,sc - O(n),
        int ans = 0;
        vector<int> s;
        int sum = 0;
        for(int i=0;i<n;i++){ // n
            sum += cardPoints[i];
            s.push_back(sum);
        }
        // only right side
        if(n==k) ans = s[n-1];
        else ans = s[n-1] - s[n-1-k];
        int k1 = k;
        for(int i=0;i<k1;i++){ // k
            int sum = 0;
            k = k1;
            k -= i+1;
            // left
            sum += s[i];
            // right
            sum += s[n-1] - s[n-1-k];
            ans = max(ans,sum);
        }
        return ans;
    }
};


// 76 brute force tle
class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int n = s.length();
        int m = t.length();
        unordered_map<char,int> tfreq;
        for(int i=0;i<m;i++){
            tfreq[t[i]]++;
        }
        for(int i=0;i<n;i++){
            unordered_map<char,int> subt = tfreq;
            string sub = "";
            for(int j=i;j<n;j++){
                sub+=s[j];
                if(subt.find(s[j])!=subt.end()){
                    subt[s[j]]--;
                }
                if(subt[s[j]]==0){
                    subt.erase(s[j]);
                }
                // cout << subt.size() << " " << sub << endl;
                if(subt.size()==0){
                    if(ans.length() == 0) ans = sub;
                    if(ans.length() > sub.length()) ans = sub;
                    break;
                }
            }
        }
        return ans;
    }
};
// by me  76 leetcode
string minWindow(string s, string t) {
    pair<int,int> ans = {-1,1}; // ans left right
    int n = s.length();
    int m = t.length();
    unordered_map<char,int> subt;
    unordered_map<char,int> tfreq;
    for(int i=0;i<m;i++){
        subt[t[i]]++;
        tfreq[t[i]]=0;
    }
    int left = 0;
    for(int right=0;right<n;right++){
        if(subt.find(s[right])!=subt.end()){
            tfreq[s[right]]++;
        }
        // validate
        int d = tfreq.size();
        for(auto it : subt){
            if(it.second <= tfreq[it.first]) d--;
            else break;
        }
        if(d==0){
            if(ans.second + ans.first == 0){
                ans.first = left;
                ans.second = right;
            }
            if(ans.second - ans.first + 1 > right-left+1) {
                ans.first = left;
                ans.second = right;
            }
            while(true){
                int wd = tfreq.size();
                for(auto it : subt){
                    if(it.second <= tfreq[it.first]) wd--;
                    else break;
                }
                if(wd!=0) break;
                // cout <<  "inside " << left<< " "<< right << " " << ans.first << " " << ans.second << endl;
                if(ans.second - ans.first + 1 > right-left+1) {
                    ans.first = left;
                    ans.second = right;
                }
                if(subt.find(s[left])!=subt.end()){
                    tfreq[s[left]]--;
                }
                left++;
            }
        }
        // cout << left<< " "<< right << " " << ans.first << " " << ans.second << endl;
    }
    if(ans.first==-1 && ans.second==1) return "";
    string ansStr = s.substr(ans.first,ans.second - ans.first + 1);
    return ansStr;
}