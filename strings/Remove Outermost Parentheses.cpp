class Solution {
public:
    string removeOuterParentheses(string s) {
        int brack=0;
        int starting=0;
        string s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                brack++;
            }else if(s[i]==')'){
                brack--;
            }
            if(brack==0){
                s1.insert(s1.size(),s.substr(starting+1,i-starting-1));
                starting=i+1;
            }
        }
        return s1;
    }
};