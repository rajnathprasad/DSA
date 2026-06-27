// 21. Find the Kth Smallest Element

class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};

// TC : O(nlogn)
// SC : O(logn)