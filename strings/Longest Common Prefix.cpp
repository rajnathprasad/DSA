class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str1=strs[0];
        string str2=strs[strs.size()-1];
        int lowSize=min(str1.size(),str2.size());
        string ans="";
        for(int i=0;i<lowSize;i++){
            if(str1[i]==str2[i]){
                ans+=str1[i];
            }else break;
        }
        return ans;
    }
};