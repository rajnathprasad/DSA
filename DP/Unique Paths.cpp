class Solution {
public:
    int solve(int m, int n, int i, int j, vector<vector<int>> &t){
        
        if(i>=m || j>=n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(t[i][j]!=0) return t[i][j];

        return t[i][j]= solve(m,n, i+1, j, t) + solve(m,n, i, j+1, t);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int> (n,0));
        for(int i=0;i<m;i++){
            t[i][0]=1;
        }
        for(int j=0;j<n;j++){
            t[0][j]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                t[i][j]=t[i][j-1]+t[i-1][j];
            }
        }


        return t[m-1][n-1];
    }
};