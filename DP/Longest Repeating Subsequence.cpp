class Solution {
  public:
    int longestRepSubseq(string &s) {
        // Code here
        string s1=s;
        string s2=s;
        
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1] && i!=j){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};