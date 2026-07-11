class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int> &nums, vector<int> &temp,int i){
        int n = nums.size();
        if(i==n){
            result.push_back(temp);
            return;
        };
        temp.push_back(nums[i]);
        solve(nums,temp,i+1);
        temp.pop_back();

        while (i + 1 < n && nums[i] == nums[i + 1])
            i++;

        solve(nums, temp,i+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        solve(nums,temp,0);
        return result;
    }
};