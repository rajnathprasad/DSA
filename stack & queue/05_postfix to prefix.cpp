class Solution {
  public:
    string postToPre(string s) {
        // code here
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' ||
            s[i]=='-' ||
            s[i]=='/' ||
            s[i]=='*' ||
            s[i]=='^'){
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                st.push(s[i] + t2 + t1);
            }
            else{
                st.push(string(1,s[i]));
            }
        }
        return st.top();
    }
};