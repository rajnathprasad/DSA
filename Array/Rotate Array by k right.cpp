// 7. Rotate Array by k Positions: Rotate the array to the right by k positions.

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
}


// TC : O(N)
// SC : O(1)