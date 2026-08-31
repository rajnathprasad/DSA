class Solution {
  public:
    int solve(vector<vector<bool>> &pal, vector<vector<int>> &t,string &s, int i, int j){
        if(i>=j) return 0;
        if(pal[i][j]) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int mini=INT_MAX;
        int tempAns=0;
        for (int k = i; k < j; k++) {
            if (pal[i][k]) {
                tempAns = 1 + solve(pal, t, s, k + 1, j);
                mini = min(mini, tempAns);
            }
        }
        return t[i][j]=mini;
    }
    int palPartition(string &s) {
        int n=s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i=n-1; i>=0; i--) {
            for (int j=i; j<n; j++) {
                if (s[i]==s[j] && (j-i<=2 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                }
            }
        }
        vector<vector<int>> t(n,vector<int>(n,-1));
        return solve(pal,t, s, 0, n-1);
    }
};