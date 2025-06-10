// 3403
class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        int maxSubString = n - numFriends + 1;
        for (int i = 0; i < n; i++) {
            res = max(res, word.substr(i, min(maxSubString, n - i)));
        }
        return res;
    }
};

// 1061
class Solution {
public: 
    // tc - o(n+m) sc - O(1)
    int rowOfCharExist(vector<vector<char>> relation,char elem){
        int rn = relation.size();
        for(int i=0;i<rn;i++){
            int rm = relation[i].size();
            for(int j=0;j<rm;j++){
                if(relation[i][j]==elem){
                    return i;
                }
            }
        }
        return -1;
    }
    char smallestCharOfCharRelation(vector<vector<char>> relation,char elem){
        int rn = relation.size();
        for(int i=0;i<rn;i++){
            int rm = relation[i].size();
            for(int j=0;j<rm;j++){
                if(relation[i][j]==elem){
                    return relation[i][0];
                }
            }
        }
        return '1';
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<char>> relation;
        int n = s1.length();
        for(int i=0;i<n;i++){ // O(n)
            if(s1[i]==s2[i]) continue;
            int res1 = rowOfCharExist(relation,s1[i]);// O(26*26)
            int res2 = rowOfCharExist(relation,s2[i]);

            if(res1!=-1 && res2!=-1 && res1==res2) continue;
            else if(res1!=-1 && res2!=-1){
                int nr = relation[res2].size();
                for(int t=0;t<nr;t++){
                    relation[res1].push_back(relation[res2][t]); // 26
                }
                sort(relation[res1].begin(),relation[res1].end()); //O(log 26)
                relation.erase(relation.begin() + res2);  // 26
            }
            else if(res1!=-1){
                relation[res1].push_back(s2[i]);
                sort(relation[res1].begin(),relation[res1].end());
            }else{
                if(res2!=-1){
                    relation[res2].push_back(s1[i]);
                    sort(relation[res2].begin(),relation[res2].end());
                }else{
                    vector<char> temp = {s1[i],s2[i]};
                    sort(temp.begin(),temp.end());
                    relation.push_back(temp);
                }
            }
            cout << "s1 and s2 "<<  s1[i] << " " << s2[i] << endl;
            cout << "=--------------relation -----------------" << endl;
            for(auto i : relation){
                for(auto j : i){
                    cout << j << " ";
                }
                cout << endl;
            }
            cout << "=--------------relation -----------------" << endl;
        }
        for(auto i : relation){
            for(auto j : i){
                cout << j << " ";
            }
            cout << endl;
        }
        int nb = baseStr.length(); 
        for(int i=0;i<nb;i++){ // o(m)
            char res = smallestCharOfCharRelation(relation,baseStr[i]); // o(26*26)
                cout << baseStr[i] << " " << res << endl;
            if(res!='1'){
                baseStr[i]=res;
            }
        }
        return baseStr;
    }
};

// 2434
class Solution {
public:
    string robotWithString(string s) {
        vector<char> p; // paper
        stack<char> t; // robot
        int n = s.length();
       
        //  precomputing  // o(n)
        unordered_map<int,char> smallestChar;
        char sc = s[n-1];
        smallestChar[n-1] = sc;
        for(int i=n-2;i>=0;i--){
            if(s[i]<=sc){
                smallestChar[i] = s[i];
                sc = s[i];
            }else{
                 smallestChar[i] = sc;
            }
        }
  
        for(int i=0;i<n;i++){ // o(n)
            char sm = smallestChar[i];
            while(!t.empty() && t.top() <= sm){ // 2
                p.push_back(t.top());
                t.pop();
            } 
            t.push(s[i]);
            if(s[i]==sm){
                p.push_back(t.top());
                t.pop();
            }
        }
        while(!t.empty()){
            p.push_back(t.top());
            t.pop();
        }
        string str(p.begin(),p.end()); //o(n)
        return str;
    }
};

// 3170
class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                cnt[s[i] - 'a'].push(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!cnt[j].empty()) {
                        s[cnt[j].top()] = '*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};

// 440
class Solution {
public:
    int findKthNumber(int n, int k) {
        long long cur = 1;
        k--;
        while (k > 0) {
            long long steps = 0;
            for (long long first = cur, last = cur + 1; first <= n; first *= 10, last *= 10) {
                steps += min(static_cast<long long>(n) + 1, last) - first; // n+1 to inculde n , and in last we did not because we do not want to include last
            }
            if (steps <= k) {
                k -= steps;
                cur++;
            } else {
                k--;
                cur *= 10;
            }
        }
        return cur;
    }
};

// 386
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        // Start generating numbers from 1 to 9
        for (int start = 1; start <= 9; ++start) {
            generateLexicalNumbers(start, n, lexicographicalNumbers);
        }
        return lexicographicalNumbers;
    }

private:
    void generateLexicalNumbers(int currentNumber, int limit,vector<int>& result) {
        // If the current number exceeds the limit, stop recursion
        if (currentNumber > limit) return;

        // Add the current number to the result
        result.push_back(currentNumber);

        // Try to append digits from 0 to 9 to the current number
        for (int nextDigit = 0; nextDigit <= 9; ++nextDigit) {
            int nextNumber = currentNumber * 10 + nextDigit;
            // If the next number is within the limit, continue recursion
            if (nextNumber <= limit) {
                generateLexicalNumbers(nextNumber, limit, result);
            } else {
                break;  // No need to continue if nextNumber exceeds limit
            }
        }
    }
};

// 3442
class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mpp;

        for(auto it : s){
            mpp[it]++;
        }

        int oddMax = -1;
        int evenMin = INT_MAX;

        for(auto it : mpp){
            if(it.second%2==0){
                evenMin = min(evenMin,it.second);
            }else{
                oddMax = max(oddMax,it.second);
            }
        }
        return oddMax - evenMin;
    }
};

