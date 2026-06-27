// 4. Find the Second Largest Element

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int maxi=INT_MIN;
        int secondMaxi=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                secondMaxi=maxi;
                maxi=arr[i];
            }
            else if(arr[i]>secondMaxi && arr[i]!=maxi){
                secondMaxi = arr[i];
            }
        }
        if(secondMaxi == INT_MIN){
            return -1;
        }
        return secondMaxi;
    }
};

// TC : O(N)
// SC : O(1)