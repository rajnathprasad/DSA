class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if (st.empty()) {
                st.push(asteroids[i]);
                continue;
            }
            if(st.top()>0 && asteroids[i]<0){
                
                while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i]){
                    st.pop();
                }
                if(st.empty()){
                    st.push(asteroids[i]);
                }
                else if(st.top() == -asteroids[i]){
                    st.pop();
                }
                else if(st.top()<0){
                    st.push(asteroids[i]);
                }
            }else{
                st.push(asteroids[i]);
            }
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};