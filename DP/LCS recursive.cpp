class Solution {
  public:
    int solve(string &s1, string &s2, int n, int m){
        if(m==0 || n==0) return 0;
        if(s1[n-1]==s2[m-1]){
            return 1+solve(s1,s2,n-1,m-1);
        }
        else{
            return max(solve(s1,s2,n-1,m),
                        solve(s1,s2,n,m-1));
        }
    }
    int lcs(string &s1, string &s2) {
        // code here
        int n=s1.size();
        int m=s2.size();
        return solve(s1,s2,n,m);
    }
};
