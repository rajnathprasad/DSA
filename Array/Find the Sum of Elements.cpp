// 3. Find the Sum of Elements

class Solution {
  public:
    int arraySum(vector<int>& arr) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        return sum;
    }
};

// TC : O(N)
// SC : O(1)