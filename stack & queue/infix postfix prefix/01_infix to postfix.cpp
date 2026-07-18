class Solution {
  public:
    int priority(char c){
        if(c=='+' || c=='-') return 1;
        if(c=='*' || c=='/') return 2;
        if(c=='^') return 3;
        return -1;
    }
    string infixToPostfix(string& s) {
        // code here
        string ans;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if((s[i]>='A' && s[i]<='Z')
            || (s[i]>='a' && s[i]<='z')
            || (s[i]>='0' && s[i]<='9')){
                ans.push_back(s[i]);
            }
            else if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                while(st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }    
                st.pop();
            }
            else{
                while(!st.empty() && st.top()!='(' &&
                (priority(st.top()) > priority(s[i]) ||
                (priority(st.top()) == priority(s[i]) && s[i] != '^'))){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
