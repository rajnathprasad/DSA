class Solution {
  public:
    int solve(vector<vector<int>> &ans, vector<int> &arr, int i, int j){
        if(ans[i][j]!=-1){
            return ans[i][j];
        }
        if(i>=j) return 0;
        int mini=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int tempAns= solve(ans, arr, i, k) + 
                        solve(ans, arr, k+1,j) + 
                        (arr[i-1]*arr[k]*arr[j]);
            mini=min(tempAns, mini);
        }
        return ans[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>> ans(n+1,vector<int> (n+1,-1));
        return solve(ans, arr,1, n-1);
    }
};