class Solution {
public:
    int fun(vector<int> &nums, long long k){
        long long dist=1;
        long long sumNow=0;
        for(long long i=0;i<nums.size();i++){
            if(sumNow+nums[i]<=k){
                sumNow+=nums[i];
            }
            else{
                dist++;
                sumNow=nums[i];
            }
        }
        return dist;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0ll);
        long long mid;
        while(low<=high){
            mid=(high+low)/2;
            long long countInts = fun(nums, mid);
            if(countInts>k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low;
    }
};