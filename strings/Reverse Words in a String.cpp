class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string sub="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                sub+=s[i];
            }else if(sub!=""){
                words.push_back(sub);
                sub="";
            }
        }
        if(sub!=""){
            words.push_back(sub);
        }
        sub="";
        for(int i=words.size()-1;i>=0;i--){
            sub+=words[i];
            if(i!=0){
                sub+=" ";
            }
        }
        return sub;
    }
};