class Solution {
  public:
    int solve(string &s, int i, int j, bool isTrue){
        if(i>j) return false;
        if(i==j){
            if(isTrue){
                return s[i]=='T';
            }
            else{
                return s[i]=='F';
            }
        }
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            int LT=solve(s, i, k-1, true);
            int LF=solve(s, i, k-1, false);
            int RT=solve(s, k+1, j, true);
            int RF=solve(s, k+1, j, false);
            
            if(s[k]=='&'){
                if(isTrue){
                    ans+=LT*RT;
                }
                else{
                    ans+=LT*RF + LF*RT + RF*LF;
                }
            }
            
            else if(s[k]=='|'){
                if(isTrue){
                    ans+=LT*RF + LF*RT + LT*RT;
                }
                else{
                    ans+=LF*RF;
                }
            }
            
            else if(s[k]=='^'){
                if(isTrue){
                    ans+=LT*RF + RT*LF;
                }
                else{
                    ans+=LT*RT + RF*LF;
                }
            }
            
            
        }
        return ans;
    }
    int countWays(string &s) {
        // code here
        int n=s.size();
        return solve(s,0, n-1, true );
    }
};