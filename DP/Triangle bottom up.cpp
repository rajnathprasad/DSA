class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> t(n);
        for(int j=0;j<n;j++){
            t[n-1].push_back(triangle[n-1][j]);
        }

        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                t[i].push_back(triangle[i][j] + min(t[i+1][j],t[i+1][j+1]));
            }
        }
        return t[0][0];
    }
};