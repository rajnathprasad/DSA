class Solution {
  public:
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
    int sumOfMax(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int> ngl=nextGreaterLeft(arr);
        vector<int> ngr=nextGreaterRight(arr);
        int sum = 0;
        for (int i=0; i<n;i++) {
            int left=i-ngl[i];
            int right=ngr[i]-i;
            sum+=arr[i]*left*right;
        }
    return sum;
        
    }
};