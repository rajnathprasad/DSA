// 6. Check if Array is Sorted

class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        if(arr.size()<=1){
            return true;
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                return false;
            }
        }
        return true;
    }
};

// TC : O(N)
// SC : O(1)