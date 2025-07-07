#include <bits/stdc++.h>
using namespace std;
int countDigit(long long num){
    int c=0;
    while(num){ // for counting n digit
        c++;
        num/=10;
    }
    return c;
}
bool isKpalindromic(long long x,int k){
    stringstream ss;
    ss << x;
    string s = ss.str();
    int xc = countDigit(x);
    for(long long i=0;i<xc;i++){
        if(s[i]=='0') continue;
        for(int j=0;j<xc;j++){
            string st = "";
            st += s[i];
            if(i!=j) st += s[j];
            for(int h=0;h<xc;h++){
                if(h!=i && h!=j){
                    st+=s[h];
                }   
            }
            if(stoll(st)%k==0){
                int n = st.length();
                int possiable = true;
                for(int i=0;i<n/2;i++){
                    if(st[i]!=st[n - i - 1]){
                        possiable=false;
                    }
                }
                
                if(possiable==true) {
                    cout << x  << " " << st << endl;
                    return true;
                }
            }         
        }
    }
    return false;
}

long long countGoodIntegers(int n, int k) {
    long long nstart = pow(10,n-1);
    long long nend = n;
    nend = pow(10,n) - 1; // if n = 1 - nend = 9 , n = 2 - nend = 99 ...
    long long goodCount = 0;
    // cout << nend << endl;
    for(long long x=nstart;x<=nend;x++){
        if(isKpalindromic(x,k)){
            // cout << x << endl;
            goodCount++;
        }

    }
    return goodCount;
}

 bool checkKthBit(int n, int k) {
        // Your code here
        // first change to binary
        string bi = "";
        int nu = n;
        while(nu){
            bi += (char)nu%2;
            nu/=2;
        }
        cout << bi;
        if(bi[k]=='1') return true;
        return false;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        map<vector<int>,int> mpp;
        long long ans=0;
        for(int i=0;i<=nums1.size()-3;i++){
            for(int j=i+1;j<nums1.size()-1;j++){
                for(int k=j+1;k<nums2.size();k++){
                    if(nums1[i]!=nums1[j] && nums1[j]!=nums1[k] && nums1[k]!=nums1[i]){
                        vector<int> vv = {nums1[i],nums1[j],nums1[k]};
                        mpp[vv]++;
                    }
                }
            }
        }
        for(int i=0;i<=nums2.size()-3;i++){
            for(int j=i+1;j<nums2.size()-1;j++){
                for(int k=j+1;k<nums2.size();k++){
                    vector<int> vv = {nums2[i],nums2[j],nums2[k]};
                    if(mpp.find(vv)!=mpp.end()){
                        ans++;
                    }
                }
            }
        }
        return ans;
    } /// time limit exceded - brute force - O(N^3 * N)
    int pair(vector<int>&nums,int low,int high,int n){
        int cnt = 0;
        for(int i=low;i<=high;i++){
            for(int j=i+1;j<=high;j++){
                if(i<j && nums[i]==nums[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                // cout << pair(nums,i,j,n) << " ";
                if(pair(nums,i,j,n)>=k) ans++;
            } 
        }
        return ans;
    } // time limit exceded O(N^4) 
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mpp;
        for(auto i : answers){
            if(mpp.find(i)!=mpp.end()){
                if(mpp[i]!=0) mpp[i]--;
                else mpp[i]=i;
            }else{
                mpp[i]=i;
            }
        }
        int ans = 0;
        ans+=answers.size();
        for(auto i : mpp){
            ans+=i.second;
        }
        return ans;
    } // tc - O(2N) sc -O(N)  
     int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ans = 0;
        // brutr force tc - O(n^2) , sc - O(1)
        for(int i=lower;i<=upper;i++){
            int val=i;
            bool pos=true;
            for(int j=0;j<differences.size();j++){
                val = val + differences[j];
                if(val < lower || val > upper){
                    pos=false;
                    break;
                }
            }
            if(pos){
                ans++;q
            }
        }
        return ans;
    }  
    bool possiable(vector<int>& differences,int value,int lower,int upper){ // O(differences) O(n)
        int val=value;
        bool pos=true;
        for(int j=0;j<differences.size();j++){
            val = val + differences[j];
            if(val < lower || val > upper){
                pos=false;
                break;
            }
        }
        if(pos) return true;
        return false;
    }
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int ans = 0;
        int first=INT_MIN; 
        int last=INT_MAX;
        for(int i=lower;i<=upper;i++){ // finding first possible 
            if(possiable(differences,i,lower,upper)){
                first = i;
                break;
            }
        }
        for(int i=upper;i>=lower;i--){ // finding last possiable
            if(possiable(differences,i,lower,upper)){
                last = i;
                break;
            }
        }
        // cout << first << last;
        if(first==INT_MIN && last==INT_MAX) return 0;
        return (last - first) + 1;
    } // tc - O((Upper−Lower+1)∗N)

    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((dominoes[i][0]== dominoes[j][0] && dominoes[i][1]==dominoes[j][1]) ||
                 (dominoes[i][0]==dominoes[j][1] && dominoes[i][1]==dominoes[j][0])){
                    ans++;
                }
            }
        } // tc = O(N^2) , sc - O(1);
        return ans;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int ans = 0;
        map<int,int> mpp;
        for(int i=0;i<n;i++){
            int a = dominoes[i][0];
            int b = dominoes[i][1];
            int v = (a<=b) ? a*10+b : b*10+a;
            mpp[v]++;
        }
        for(auto h : mpp){
            ans += h.second * (h.second - 1)/2;
        }

        return ans;
    }

     bool threeConsecutiveOdds(vector<int>& arr) {
        bool ans = false;
        int n = arr.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(c==3) return true;
            if(arr[i]%2!=0){
                c++;
            }else{
                c=0;
            }
        }
        if(c==3) return true;
        return false;
    }//https://leetcode.com/problems/three-consecutive-odds/

    int minDeletion(string s, int k) { //3545. Minimum Deletions for At Most K Distinct Characters
        int n = s.length();
        map<char,int> mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>> vec(mpp.begin(),mpp.end());
        
        sort(vec.begin(),vec.end(),[](const auto &a,const auto &b){
            return a.second < b.second;
        });
        
        // for(auto i : vec){
        //     cout << i.first << " " << i.second << endl;
        // }
        
        int dist = vec.size();
        int deleteCount = 0;
        int ind = 0;
        for(auto p : vec){
            if(dist==k) break;
            deleteCount += p.second;
            ind++;
            dist--; 
        }
            
        return deleteCount;
    }

     vector<int> findEvenNumbers(vector<int>& digits) {
        // tc - O(N^3) + O(log n) , sc = O(n)
        int n = digits.size();
        set<int> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && k!=i && digits[i]!=0 && digits[k]%2==0){
                        int num = digits[i];
                        num= num*10 + digits[j];
                        num= num*10 + digits[k];
                        ans.insert(num); // log n
                    }
                }
            }
        }
        vector<int> vec(ans.begin(),ans.end());
        return vec;
    }

    int lengthAfterTransformations(string s, int t) {
        string ans = "";
        for(int i=0;i<t;i++){
            for(auto c : s){
                if(c=='z'){
                    ans+="ab";
                }else{
                    ans+= (c+1);
                }
                // cout << ans << endl;
            }
            s = ans;
            ans = "";
        }
        // brute force tc - O(t*n) - O(10^10) - TLE
        // cout << s.length();
        return s.length() % (int)(1e9 + 7);
    }//   https://leetcode.com/problems/total-characters-in-string-after-transformations-i/
     const int mod = 1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++) freq[s[i]]++;
        // tc - O(n) , sc - O(1)
        for(int i=0;i<t;i++){
            int zfreq = freq['z'];
            freq['z']=0;
            for(char c='y'; c>='a'; c--){ // 26
                freq[c+1] += freq[c];
                freq[c]=0;
            }
            freq['a']+=zfreq;
            freq['a']%=mod; // as it increment exponentily
            freq['b']+=zfreq;
            freq['b']%=mod;
        }
        int ans=0;
        for(auto it : freq){
            ans+=it.second;
            ans %= mod;
        }
        return ans;
    } //https://www.youtube.com/watch?v=RFF_xGZ_Cmc

    class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<vector<string>> ans;
        int n = words.size();
        for(int i=0;i<n;i++){
            for(int t=i+1;t<n;t++){
            vector<string> temp;
            temp.push_back(words[i]);
            int last = i;
                for(int j=t;j<n;j++){

                if(groups[last]!=groups[j] && temp.back().length()==words[j].length()){
                    int unequalLetter = 0;
                    int l = words[j].length();
                    cout << temp.back() << " " << words[j] << endl;
                    for(int k=0;k<l;k++){
                        // cout << temp.back()[k] <<  " " << words[j][k] << endl;
                        if(temp.back()[k]!=words[j][k]){
                            unequalLetter++;
                        }
                    }
                    cout << last << " " << unequalLetter ;
                    if(unequalLetter==1){
                        last = j;
                        temp.push_back(words[j]);
                    }
                }
            }
            ans.push_back(temp);
            }
        }

        pair<int,int> longSub = {-1,-1}; // longest , index
        for(int i=0;i<ans.size();i++){
            cout << "----------"<< endl;
            for(string s : ans[i]){
                cout << s << " " ;
            }
            cout << endl;
            int m = ans[i].size();
            if(m > longSub.first){
                longSub.first = m;
                longSub.second = i;
            }
        }
        if(longSub.second==-1){
            return words;
        }
        return ans[longSub.second];
    }
}; // woring solution trying 

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
    // cout << countGoodIntegers(3,5);
    cout << checkKthBit(19641,4) ;

    // cout << isKpalindromic(400,4);
    // cout << "Askda";
    // // int goodCount=0;
    //  int x = 110;
    // vector<int> arr;
    // int xc = 3; // count digit
    // int k = 2;
    // stringstream ss;
    // ss << x;
    // string s = ss.str();
    // unordered_map<long long,int> mpp;
    // for(long long i=0;i<xc;i++){
    //     if(s[i]=='0') continue;
    //     for(int j=0;j<xc;j++){
    //         string st = "";
    //         st += s[i];
    //         if(i!=j) st += s[j];
    //         for(int h=0;h<xc;h++){
    //             if(h!=i && h!=j){
    //                 st+=s[h];
    //             }   
    //         }
    //         long long num = stoll(st);
    //         if(mpp.find(num)!=mpp.end()){
    //             continue;
    //         }
    //         mpp[num]++;
    //         cout << num << " " << isKpalindromic(num,k) << endl;
    //     }
       
    // }
    // for(auto c : arr){
    //     cout << c << " ";
    // }

    return 0;
}


int countPrimes(int n) {
    vector<int> prime(n+1,1);
    int ans =0;
    for(long long i=2;i<n;i++){
        if(prime[i]){
            ans++;
            for(long long j=i*i;j<n;j+=i){
                prime[j]=0;
            }
        }
    }
    // Sieve of Eratosthenes - for prime no less than n;
    return ans;
}