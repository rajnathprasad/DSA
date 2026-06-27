// 18. Move Zeroes to End: Move all zeroes in an array to the end while maintaining the order of non-zero elements.

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                swap(nums[k],nums[i]);
                k++;
            }
        }
    }
};

// TC : O(N)
// SC : O(1)