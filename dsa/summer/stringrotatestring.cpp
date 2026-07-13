// https://leetcode.com/problems/rotate-string/

//  tc - O(n^2) , Sc-O(1)
bool rotateString(string s, string goal) {
    int n1 = s.length();
    int n2 = goal.length();
    if(n1!=n2) return false;
    if(s==goal) return true;
    for(int t=0;t<n1;t++){
        if(goal[t]==s[0]){
            int i = 0;
            int j = t;
            while(j<n1){
                if(goal[j]==s[i]){
                    i++;
                    j++;
                }else break;
            }
            if(j==n1){
                if(i==n1) return true;
                else{
                    j=0;
                    while(i<n1){
                        if(s[i]==goal[j]){
                            i++;
                            j++;
                        }else break;
                    }
                    if(i==n1) return true;
                }
            }
        }
    }

    return false;
}

// tc - O(n)
bool rotateString(string s, string goal) {
    return s.length() == goal.length() && (s + s).find(goal) != string::npos;
}
