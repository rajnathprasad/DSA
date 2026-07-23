class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int n=s.size();
        int maxLen=0;
        int maxF=0;
        vector<int> mpp(26,0);
        while(r<n){
            mpp[s[r]-'A']++;
            maxF=max(maxF,mpp[s[r]-'A']);
            while((r-l+1)-maxF>k){
                mpp[s[l]-'A']--;
                maxF=0;
                for(int i=0;i<26;i++){
                    maxF=max(maxF,mpp[i]);
                }
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};