class Solution {
  public:
    unordered_map<string, bool> dp;
    bool isScramble(string a, string b) {
        // code here
        
        if(a==b) return true;
        if (a.length() != b.length()) return false;
        if(a.length()<=1) return false;
        
        string key = a + "#" + b;
        if (dp.find(key) != dp.end()) return dp[key];
        
        int n=a.length();
        bool flag=false;
        

        for(int i=1;i<n;i++){
            
            bool swapped=(isScramble(a.substr(0,i), b.substr(n-i,i)) &&
                    isScramble(a.substr(i,n-i), b.substr(0,n-i)));
                    
            bool unSwapped(isScramble(a.substr(0,i), b.substr(0,i)) &&
                    isScramble(a.substr(i,n-i), b.substr(i,n-i)));
            
            
            if(swapped || unSwapped){
                return dp[key] = true;
            }
        }
        
        
        return dp[key] = false;
    }
};
