


class Solution {
public:
    int minMaxDifference(int num) {
        int no = num;
        int c = 0;
        vector<int> numv;
        vector<int> vis(10,0);
        while(no){
            c++;
            numv.push_back(no%10);
            vis[no%10] = 1;
            no/=10;
        }
        reverse(numv.begin(),numv.end());
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(int i=0;i<=9;i++){ // maxi 10
            if(vis[i]==1){ 
                int maxtest = 0;
                int mintest = 0;
               for(int d=0;d<c;d++){
                    if(numv[d]==i) maxtest = maxtest *10 + 9;
                    else maxtest = maxtest *10 + numv[d];
                    if(numv[d]==i) mintest = mintest *10 + 0;
                    else mintest = mintest *10 + numv[d];
               }
               maxi = max(maxi,maxtest);
               mini = min(mini,mintest);
            }
        }
        return maxi - mini;
    }
};

class Solution {
public:
    int minMaxDifference(int num) {
        int no = num;
        int c = 0;
        vector<int> numv;
        vector<int> vis(10,0);
        while(no){
            c++;
            numv.push_back(no%10);
            vis[no%10] = 1;
            no/=10;
        }
        reverse(numv.begin(),numv.end());
        int maxi = INT_MIN;
        int mini = INT_MAX;

        no = num;
        for(int i=0;i<9;i++){
            if(vis[i]==1){
                int ntest = 0;
               for(int d=0;d<c;d++){
                    if(numv[d]==i) ntest = ntest *10 + 9;
                    else ntest = ntest *10 + numv[d];
               }
               maxi = max(maxi,ntest);
            }
        }
        for(int i=1;i<=9;i++){
            if(vis[i]==1){
                int ntest = 0;
               for(int d=0;d<c;d++){
                    if(numv[d]==i) ntest = ntest *10 + 0;
                    else ntest = ntest *10 + numv[d];
               }
               mini = min(mini,ntest);
            }
        }
        if(maxi==INT_MIN) maxi = num;
        if(mini==INT_MAX) mini = num;
        return maxi - mini;
    }
};