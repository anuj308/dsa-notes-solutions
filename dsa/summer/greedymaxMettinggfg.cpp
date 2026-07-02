
// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1

// tc - O(n log n), sc - O(2n)
class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        vector<int> ans;
        int n = s.size();
        
        vector<pair<int,pair<int,int>>> meeting; // endtime ,{ index,starttime}
        // this order is for as based on question so with sort we achive what we want
        // first endtime explain below, index as in question want if endtime is same choose smaller index
        
        // first make the metting with start and end visualise
        //  we will sort from end time as we want  maximum metting to conduct
        // so by this the meeting end first we get it will schedule first as 
        // so we can schedule meeting with less time first
        for(int i=0;i<n;i++){
            meeting.push_back({f[i],{i,s[i]}}); 
        }
        
        sort(meeting.begin(),meeting.end());
        
        int last = -1;
        for(int i=0;i<n;i++){
            int currStart = meeting[i].second.second;
            int index = meeting[i].second.first;
            int meetEnd = meeting[i].first;
            if(currStart>last){
                ans.push_back(index+1);
                last = meetEnd;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};