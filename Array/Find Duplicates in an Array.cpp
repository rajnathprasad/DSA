// Find Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map <int, int> mpp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// TC : O(N)
// SC : O(1)