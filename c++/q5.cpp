// 

#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string sen;
    string from;
    string too;
    
    getline(cin,sen);
    getline(cin,from);
    getline(cin,too);
    
    if(sen.find(from)!=string::npos){
        size_t pos = 0;
        while((pos = sen.find(from,pos)) != string::npos){
            sen.replace(pos,from.length(),too);
            pos += too.length();
        }
    }
    
    cout << sen << endl;
    
    return 0;
}

// one testcase id falied