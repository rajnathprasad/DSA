class Solution {
  public:
    struct Meeting{
        int start;
        int end;
        int pos;
    };
    static bool mComp(Meeting m1, Meeting m2){
        return m1.end<m2.end;
    }
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n=s.size();
        vector<Meeting> meetings(n);
        for(int i=0;i<n;i++){
            meetings[i].start=s[i];
            meetings[i].end=f[i];
            meetings[i].pos=i+1;
        }
        sort(meetings.begin(),meetings.end(),mComp);
        int freeTime=meetings[0].end;
        int count=1;
        vector<int> ans;
        ans.push_back(meetings[0].pos);
        for(int i=1;i<n;i++){
            if(freeTime<meetings[i].start){
                count++;
                freeTime=meetings[i].end;
                ans.push_back(meetings[i].pos);
            }
        }
        
        return ans;
    }
};