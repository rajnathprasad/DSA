class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int brack=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brack++;
            }
            if(s[i]==')'){
                brack--;
            }
            maxi=max(maxi, brack);
        }
        return maxi;
    }
};