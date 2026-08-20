class Solution {
  public:
    int countSubsetSum(vector<int> arr, int sum){
        int n=arr.size();
        vector<vector<int>> t(n+1,vector<int> (sum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        return t[n][sum];
    }
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int arrSum=0;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            arrSum+=arr[i];
        }
        
        if (arrSum < diff || (arrSum + diff) % 2 != 0)
        return 0;
        
        int sum = (diff+arrSum)/2;
        
        return countSubsetSum(arr,sum);
    }
};