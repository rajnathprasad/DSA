class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i=0;i<s.size();i++){
            string prefix=s.substr(0,i);
            string suffix=s.substr(i);
            if(suffix+prefix==goal) return true;
        }
        return false;
    }
};