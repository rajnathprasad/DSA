class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int> cuts(n);
        for(int i=0;i<n;i++){
            cuts[i]=i+1;
        }
        
        vector<vector<int>> t(n+1, vector<int>(n+1));
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(cuts[i-1]<=j){
                    t[i][j]=max(price[i-1]+t[i][j-cuts[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        return t[n][n];
    }
};