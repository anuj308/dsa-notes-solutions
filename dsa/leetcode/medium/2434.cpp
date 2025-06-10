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