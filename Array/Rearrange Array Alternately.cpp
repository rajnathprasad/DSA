// 24. Rearrange Array Alternately: Rearrange an array such that elements alternate between the largest and smallest.

class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        
        int maxIdx = n-1;
        int minIdx = 0;
        
        long long maxEle = arr[n-1]+1;
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                arr[i]+=(arr[maxIdx]%maxEle)*maxEle;
                maxIdx--;
            }
            else{
                arr[i]+=(arr[minIdx]%maxEle)*maxEle;
                minIdx++;
                
            }
        }
        for(int i=0;i<n;i++){
            arr[i]/=maxEle;
        }
    }
};

// TC : O(n)
// SC : O(1)