class Solution {
public:
    int robHelper(vector<int>& nums){
        int n=nums.size();
        if(n<2) return nums[0];
        vector<int> t(n);
        t[0]=nums[0];
        t[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            t[i]=max(nums[i]+t[i-2],t[i-1]);
        }
        return t[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return nums[0];
        vector<int> skip_last(n-1,0);
        vector<int> skip_first(n-1,0);

        for(int i=0;i<n-1;i++){
            skip_last[i]=nums[i];
            skip_first[i]=nums[i+1];
        }
        int skipLast=robHelper(skip_last);
        int skipFirst=robHelper(skip_first);

        return max(skipFirst,skipLast);
    }
};