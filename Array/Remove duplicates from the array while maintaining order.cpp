// 9. Remove Duplicates from Array: Remove duplicates from the array while maintaining order.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return n;
        }
        int k=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

// TC : O(N)
// SC : O(1)