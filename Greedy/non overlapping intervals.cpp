class Solution {
public:
    static bool intervalComp(vector<int> i1, vector<int> i2){
        return i1[1]<i2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),intervalComp);
        int lastInterval=intervals[0][1];
        int erased = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<lastInterval){
                erased++;
            }
            else{
                lastInterval=intervals[i][1];
            }
        }
        return erased;
    }
};