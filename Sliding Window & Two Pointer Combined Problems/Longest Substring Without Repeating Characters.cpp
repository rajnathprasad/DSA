class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        int maxLen=0;
        vector<int> arr(255,-1);
        while(r<n){
            if(arr[s[r]]!=-1 && arr[s[r]] >= l){
                l=arr[s[r]]+1;
            }
            maxLen=max(maxLen,r-l+1);
            arr[s[r]]=r;
            r++;
        }
        return maxLen;
    }
};