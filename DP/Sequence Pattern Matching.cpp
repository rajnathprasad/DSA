class Solution {
  public:
    int isSubseq(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>> t(n+1,vector<int> (m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j],
                                t[i][j-1]);
                }
            }
        }

        int lcs=t[n][m];
        
        return n==lcs || lcs==m;
    }
};
