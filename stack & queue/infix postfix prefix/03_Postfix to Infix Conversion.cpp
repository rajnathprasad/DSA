class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string> st;
        string s;
        for(int i=0;i<exp.size();i++){
            if(exp[i]=='+' ||
                exp[i]=='-' ||
                exp[i]=='/' ||
                exp[i]=='*' ||
                exp[i]=='^'){
                    string t1=st.top();
                    st.pop();
                    string t2=st.top();
                    st.pop();
                    st.push("(" + t2 + exp[i] + t1 + ")");
                }
                else{
                    st.push(string(1, exp[i]));
                    
                }
        }
        return st.top();
    }
};