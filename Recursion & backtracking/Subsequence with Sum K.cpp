class Solution {
  public:
    bool solve(vector<int>& arr, int k, int sum,int idx){
        
        if(sum==k){
            return true;
        }
        if(sum>k){
            return false;
        }
        if(idx==arr.size()){
            return false;
        }

        if(solve(arr,  k, sum+arr[idx], idx+1)){
            return true;
        }


        if(solve(arr,  k, sum, idx+1)){
            return true;
        }
        
        return false;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        int sum=0;
        int idx=0;
        if(solve(arr,k, sum, idx)){
            return true;
        }
        return false;
    }
};