class Solution {
  public:
    string preToPost(string &s) {
        // code here
        stack<string> st;
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
                st.push(t1 + t2 + s[i]);
            }
            else{
                st.push(string(1,s[i]));
            }
        }
        return st.top();
    }
};