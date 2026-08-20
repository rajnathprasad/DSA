class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>> t(n+1, vector<int>(capacity+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=capacity;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=capacity;j++){
                if(wt[i-1]<=j){
                    t[i][j]=max(val[i-1]+t[i][j-wt[i-1]], t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        return t[n][capacity];
    }
};