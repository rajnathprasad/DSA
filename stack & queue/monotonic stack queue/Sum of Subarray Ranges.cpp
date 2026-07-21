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
    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=nextSmallerElements(arr);
        vector<int> pse=prevSmaller(arr);
        long long sum=0;
        for(int i=0;i<arr.size();i++) {
            long long L=i-pse[i];
            long long R=nse[i]-i;
            sum+=1LL*L*R*arr[i];;
        }
        return sum;
    }
    vector<int> nextGreaterLeft(vector<int> &arr){
        int n=arr.size();
        vector<int> ngl(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ngl[i] =-1;
            }else{
                ngl[i] =st.top();
            }
            st.push(i); 
        }
        return ngl;
    }
    vector<int> nextGreaterRight(vector<int> &arr){
        int n=arr.size();
        vector<int> ngr(n);
        stack <int> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ngr[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ngr;
    }
    long long sumOfMax(vector<int> &arr) {
        int n=arr.size();
        vector<int> ngl=nextGreaterLeft(arr);
        vector<int> ngr=nextGreaterRight(arr);
        long long sum = 0;
        for (int i=0; i<n;i++) {
            int left=i-ngl[i];
            int right=ngr[i]-i;
            sum+=1LL*arr[i]*left*right;
        }
    return sum; 
    }
    long long subArrayRanges(vector<int>& nums) {
        long long maxSums=sumOfMax(nums);
        long long minSums=sumSubarrayMins(nums);
        return maxSums-minSums;
    }
};