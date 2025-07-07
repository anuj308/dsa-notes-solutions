// 455 , tc -O(n log n) , sc O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    int ans = 0;
    int gn = g.size();
    int sn = s.size();
    sort(s.begin(),s.end());
    sort(g.begin(),g.end());
    int i=0;
    int j=0;
    while(i<gn && j<sn){
        if(g[i]<=s[j]){
            ans++;
            i++;
            j++;
        }else{
            j++;
        }
    }
    return ans;
}

// 866
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        unordered_map<int,int> money;
        money[5]=0;
        money[10]=0;
        money[20]=0;
        for(int i=0;i<n;i++){
            money[bills[i]]++;
            if(bills[i]>5){
                if(bills[i]==10){
                    if(money[5]>=1){
                        money[5]--;
                    }else{
                        return false;
                    }
                }
                if(bills[i]==20){
                    if(money[5]>=1 && money[10]>=1){
                        money[5]--;
                        money[10]--;
                    }else if(money[5]>=3){
                        money[5]-=3;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//  678
bool checkValidString(string s) {
    int l = 0;
    int st = 0;
    int n = s.length();
    stack<char> q;
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            while(!q.empty() && q.top()=='*'){
                st++;
                q.pop();
            }
            if(!q.empty() && q.top()=='('){
                q.pop();
                while(st){
                    q.push('*');
                    st--;
                }
            }else{
                if(st>=1){
                    st--;
                    while(st){
                        q.push('*');
                        st--;
                    }  
                }else{
                    return false;
                }
            }
        }else{
            q.push(s[i]);

        }
            // cout << s[i] << " " <<  q.empty() << " "  << endl;            
    }
    while(!q.empty()){
        if(q.top()=='*') st++;
        else{
            if(st>=1) st--;
            else return false;
        }
        // cout << st << " " << q.top() << endl;
        q.pop();
    }
    if(q.empty()) return true;
    return false;
}


//  55
bool canJump(vector<int>& nums) {
    int n = nums.size();
    int g=n-1;
    if((n-1)==0) return true;
    for(int i=n-2;i>=0;i--){
        if((g - i)<=nums[i]) g = i;
    }
    if(g==0) return true;
    return false;
}

// 45
int jump(vector<int>& nums) {
    int n = nums.size();
    int l=0;
    int r=0;
    int j=0;
    if(n-1==0) return 0;
    while(l<n && r<n){
        int l1 = l;
        int r1 = r;
        if(nums[r]>0) l = r+1;
        while(l1<=r1){
            r = max(r,l1+nums[l1]);
            l1++;
        }
        j++;
        if(r>=(n-1)) return j;
    }
    return j;
}

// 135 hard brute force tc-O(n) , sc-O(n)
int candy(vector<int>& ratings) {
    int ans = 0;
    int n = ratings.size();
    vector<int> left(n,1);
    vector<int> right(n,1);
    for(int i=1;i<n;i++){ // left side
        if(ratings[i-1]>ratings[i]){
            if(left[i-1]<=left[i]) left[i-1]=left[i]+1;// else not
        } 
        if(ratings[i]>ratings[i-1]){
            if(left[i]<=left[i-1]) left[i]=left[i-1]+1;// else not
        }
    }
    for(int i=n-1;i>0;i--){// right side
        if(ratings[i-1]>ratings[i]){
            if(right[i-1]<=right[i]) right[i-1]=right[i]+1;// else not
        } 
        if(ratings[i]>ratings[i-1]){
            if(right[i]<=right[i-1]) right[i]=right[i-1]+1;// else not
        }
    }
    for(int i=0;i<n;i++){
        ans+=max(left[i],right[i]);
    }
    return ans;
}


// 56
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back()[1]<arr[i][0]){
                ans.push_back(arr[i]);
            }else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};

// 57
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n==0){ 
            ans.push_back(newInterval);
            return ans;
        }
        bool done = false;
        for(int i=0;i<n;i++){
            if(newInterval[1] < intervals[i][0] && !done){
                ans.push_back(newInterval);
                done = true;
                ans.push_back(intervals[i]);
            }
            else if((intervals[i][0]>newInterval[0] || newInterval[0]<=intervals[i][1]) && !done){
                  int r = max(intervals[i][1],newInterval[1]);
                int l = min(intervals[i][0],newInterval[0]);
                i++;
                while(i<n && intervals[i][0]<=r){
                    i++;
                }
                i--;
                r = max(intervals[i][1],newInterval[1]);
                done=true;
                ans.push_back({l,r});
            }else{
                ans.push_back(intervals[i]);
            }
        }
        if(intervals[n-1][1] < newInterval[0]){
            ans.push_back(newInterval);
        }
        return ans;
    }