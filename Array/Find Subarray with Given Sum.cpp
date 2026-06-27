// 19. Find Subarray with Given Sum.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int presum=0;
        unordered_map <int, int> mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int diff = presum-k;
            count+=mpp[diff];
            mpp[presum]++;
        }
        return count;
    }
};

// TC : O(n)
// SC : O(n)