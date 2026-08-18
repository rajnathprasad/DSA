class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> t(n+1,vector<int>(W+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=W;j++){
                if(j>=wt[i-1]){
                    t[i][j]=max(
                        val[i-1]+t[i-1][j-wt[i-1]],
                        t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][W];
    }
};