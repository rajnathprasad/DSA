class Solution {
  public:
    int solve(int day, int last, vector<vector<int>> &mat, vector<vector<int>> &t){
        if(t[day][last]!=-1) return t[day][last];
        if(day==0){
            int maxi=0;
            for(int activity=0;activity<3;activity++){
                if(activity!=last){
                    maxi=max(maxi, mat[0][activity]);
                }
            }
            return t[0][last]=maxi;
        }
        int maxi=0;
        for(int activity=0;activity<3;activity++){
            if(activity!=last){
                int curr=mat[day][activity] + solve(day-1, activity, mat, t);
                maxi=max(maxi, curr);
            }
        }
        return t[day][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        vector<vector<int>> t(n, vector<int> (4,-1));
        return solve(n-1, 3, mat, t);
    }
};