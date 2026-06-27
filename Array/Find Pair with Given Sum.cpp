// 8. Find Pair with Given Sum: Find a pair of elements that adds up to a target sum.

class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            int complement = target-arr[i];
            if(s.find(complement)!=s.end()){
                return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};

// TC : O(N)
// SC : O(N)