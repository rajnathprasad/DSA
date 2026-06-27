// 17. Find the Leader Elements: An element is a leader if it is greater than all elements to its right.



class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n=arr.size()-1;
        int maxRight=arr[n];
        ans.push_back(maxRight);
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=maxRight){
                maxRight=arr[i];
                ans.push_back(maxRight);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// TC : O(n)
// SC : O(n)