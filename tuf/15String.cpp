#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    //  tc - O(N) sc - O(N)
    int op = 0;
    int cp = 0;
    int n = s.size();
    string result = "";
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            if(op!=0){ // not include open parentheses
                result+=s[i];
            }
            op++;
        }
        else {
            cp++;
            if(op==cp){   // not add close parentheses          
                op=0;
                cp=0;
            }else{
                result+=s[i];
            }
        }    
    }
return result;
}
string reverseWords(string s) {
    string result = "";
    int n = s.size();

    vector<string> rev;
    string st = "";
    for(int i=0;i<n;i++){
        if(s[i]==' ' && !st.empty()){
            rev.push_back(st);
            // cout << st << " " << i <<  st.size() << endl;
            st="";
            continue;
        }
        if(s[i]!=' ') st.push_back(s[i]);
        if(i==n-1 && !st.empty()) rev.push_back(st);
    }

    int nRev = rev.size();
    for(int i=nRev-1;i>=0;i--){
        cout << rev[i] << result << endl;
        result+=rev[i];
        if(i==0) break;
        result+=' ';
    }
    // cout << result;
    return result;
}
string reverseWords(string s) {
    int n = s.size();
    string result = "";
    string st = "";

    for(int i=0;i<n;i++){
        if(s[i]==' ' && !st.empty()){
            result = st + result;
            result = ' ' + result;
            st="";  
            continue;
        }
        if(s[i]!=' ') st.push_back(s[i]);
        if(i==n-1 && !st.empty()) result = st + result;
    }

    if(result[0]==' ') return result.substr(1);
    
    return result;
}
string largestOddNumber(string num) {
    // not works for large input as stoi can take 32 bit integer only
    if(stoi(num)%2!=0){
        return num;
    }
    int n = num.length();
    int maxNum = INT_MIN;
    for(int i=0;i<n;i++){
        string s = "";
        for(int j=i;j<n;j++){
            s+=num[j];
            if(stoi(s)%2!=0){ // if odd then check
                maxNum=max(maxNum,stoi(s));
            }
        }
    }

    if(maxNum!=INT_MIN) return to_string(maxNum);
    return "";
}

string longestCommonPrefix(vector<string>& strs) {
    string longStr="";
    int n = strs.size();
    int strN = strs[0].length();
    if(n==1) return strs[0];
    // for(int i=0;i<n;i++){
        string s = "";
        for(int j=0;j<strN;j++){
            int c = 0;
            // cout << j << " " << n << " element: " <<  strs[0][j] << endl;
            for(int k=1;k<n;k++){
                if(strs[0][j]==strs[k][j]){
                    c++;
                }
            }
            // cout << "count"<< c << endl;
            if(j==strN-1 && c==n-1){
                s += strs[0][j];
                break;
                // if(s.length() > longStr.length()) longStr = s;
                // cout << "long str" << longStr << " " <<  s << endl;
            }
            if(c==n-1){
                s += strs[0][j];
                // cout <<  "s str" << s << endl;
            }else{
                // if(s.length() > longStr.length()) longStr = s;
                return s;
                // cout << "long str" << longStr << " " <<  s << endl;
                s="";
            }
        }
    // }
    // return longStr;
    return s;
    // return "";
}
string longestCommonPrefix(vector<string>& strs) {
    string longStr="";
    int n = strs.size();
    int strN = strs[0].length();
    if(n==1) return strs[0];
    string s = "";
    for(int j=0;j<strN;j++){
        int c = 0;
        for(int k=1;k<n;k++){
            if(strs[0][j]==strs[k][j]){
                c++;
            }
        }
        if(j==strN-1 && c==n-1){
            s += strs[0][j];
            break;
        }
        if(c==n-1){
            s += strs[0][j];
        }else{
            return s;
            s="";
        }
    }

    return s;
}

int main()
{
    // ctrl + shift + b
    // for sublime ctrl + b
   
    return 0;
}