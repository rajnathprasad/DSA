class Solution {
  public:
    string preToInfix(string &s) {
        // code here
        stack <string> st;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='+' ||
            s[i]=='-' ||
            s[i]=='/' ||
            s[i]=='*' ||
            s[i]=='^'){
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                st.push("(" + t1 + s[i] + t2 + ")");
            }
            else{
                st.push(string(1,s[i]));
            }
        }
        return st.top();
    }
};