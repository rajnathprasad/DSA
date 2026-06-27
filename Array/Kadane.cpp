// 23. Maximum Sum Subarray (Kadane's Algorithm)

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int maxi = INT_MIN;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            maxi = max(maxi,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};

// TC : O(n)
// SC : O(1)