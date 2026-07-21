class Solution {
public:
    vector<int> nextSmallerElements(vector<int>& arr) {
        stack<int> st;
        int n=arr.size();
        vector<int> nge(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=n;
            }else{
                nge[i]=st.top();
            }
            st.push(i);
        }
        return nge;
    }
    vector<int> prevSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;
            }
            else{
            ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD=1e9+7;
        vector<int> nse=nextSmallerElements(arr);
        vector<int> pse=prevSmaller(arr);
        long long sum=0;
        for(int i=0;i<arr.size();i++) {
            long long L=i-pse[i];
            long long R=nse[i]-i;
            sum=(sum+L*R%MOD*arr[i])%MOD;
        }
        return sum;
    }
};