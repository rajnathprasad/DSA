class Solution {
  public:
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        
        vector<vector<int>> t(n, vector<int>(4,0));
        
        // base case
        for(int last=0;last<4;last++){
            for(int activity=0;activity<3;activity++){
                if(activity!=last){
                    t[0][last]=max(t[0][last], mat[0][activity]);
                }
            }
        }
        
        //other cases
        for(int day=1;day<n;day++){
            for(int last=0;last<4;last++){
                for(int activity=0;activity<3; activity++){
                    if(last!=activity){
                        t[day][last]=max(t[day][last], mat[day][activity]+t[day-1][activity]);
                    }
                }
            }
        }
        
        
        return t[n-1][3];
    }
};