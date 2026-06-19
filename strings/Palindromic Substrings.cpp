class Solution {
public:
    bool isPalindrome(string &sub){
        for(int i=0;i<sub.size()/2;i++){
            if(sub[i]!=sub[sub.size()-i-1]) return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            string str="";
            for(int j=i;j<s.size();j++){
                str+=s[j];
                if(isPalindrome(str)) count++;
            }
        }
        return count;
    }
};