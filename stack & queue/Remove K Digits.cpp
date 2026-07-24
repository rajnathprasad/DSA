class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size() && ans[i]=='0')
            i++;
        ans = ans.substr(i);
        return ans.empty()?"0":ans;
    }
};