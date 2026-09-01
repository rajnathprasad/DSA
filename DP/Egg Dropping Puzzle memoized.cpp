class Solution {
  public:
    int solve(int e, int f, vector<vector<int>> &dp){
        if(dp[e][f]!=-1) return dp[e][f];
        if(f==0 || f==1) return f;
        if(e==1) return f;
        int mn=INT_MAX;
        int temp;
        for(int k=1;k<=f;k++){
            temp=1+max(solve(e-1,k-1, dp), solve(e,f-k, dp));
            mn=min(mn,temp);
        }
        return dp[e][f]=mn;
    }
    int eggDrop(int e, int f) {
        // code here
        vector<vector<int>> dp(e+1,vector<int> (f+1,-1));
        return solve(e, f, dp);
    }
};