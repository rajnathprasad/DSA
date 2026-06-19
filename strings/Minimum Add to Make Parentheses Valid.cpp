class Solution {
public:
    int minAddToMakeValid(string s) {
        int brack=0;
        int req=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') brack++;
            else if(s[i]==')') brack--;
            if(brack<0){
                req++;
                brack=0;
                continue;
            }
        }
        return abs(brack)+req;
    }
};