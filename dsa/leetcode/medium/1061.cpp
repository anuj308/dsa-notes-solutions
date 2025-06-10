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