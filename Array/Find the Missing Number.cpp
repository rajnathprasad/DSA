// Find the Missing Number: Find the missing number in an array of size n containing numbers from 1 to n.

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n*(n+1)/2;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        return totalSum-sum;
    }
};

// TC : O(N)
// SC : O(1)