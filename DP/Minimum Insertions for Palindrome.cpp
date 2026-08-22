class Solution {
public:
    int minInsertions(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;

        int n=s1.length();
        int m=s2.length();

        vector<vector<int>> t(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        int lcs=t[n][m];

        return s.size()-lcs;
    }
};