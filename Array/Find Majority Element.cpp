// 25. Find Majority Element: Find the element that appears more than n/2 times.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count=1;
                el=nums[i];
            }
            else if(nums[i]==el){
                count++;
            }
            else{
                count--;
            }
        }
        return el;
    }
};

// TC : O(n)
// SC : O(1)