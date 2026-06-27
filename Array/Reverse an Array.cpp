// 1. Reverse an Array

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int low = 0;
        int high = arr.size()-1;
        while(low<high){
            swap(arr[low],arr[high]);
            low++;
            high--;
        }
    }
};

// TC : O(N)
// SC : O(1)