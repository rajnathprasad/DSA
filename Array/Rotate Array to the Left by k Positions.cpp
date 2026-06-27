// 20. Rotate Array to the Left by k Positions

class Solution {
  public:
    void rotateArr(vector<int>& nums, int d) {
        // code here
        int n=nums.size();
        d=d%n;
        reverse(nums.begin(),nums.begin()+d);
        reverse(nums.begin()+d,nums.end());
        reverse(nums.begin(),nums.end());
    }
};

// TC : O(n)
// SC : O(1)