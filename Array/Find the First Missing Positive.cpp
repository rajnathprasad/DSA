// 27. Find the First Missing Positive: Find the smallest positive integer missing in the array.
#include<vector>
// #include<iostrem>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1] !=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};

// TC : O(n)
// SC : O(1)