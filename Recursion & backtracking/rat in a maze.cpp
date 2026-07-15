class Solution {
  public:
    vector<string> result;
    void solve(vector<vector<int>>& maze,int n,int row,int col,string &temp){
        if(row<0 || row>=n || col<0 || col>=n)
            return;
        if(maze[row][col]==0){
            return;
        }
        if(row==n-1 && col==n-1){
            result.push_back(temp);
            return;
        }
        
        maze[row][col] = 0;
        
        if(row<n-1){
            temp.push_back('D');
            solve(maze,n,row+1,col, temp);
            temp.pop_back();
        }
        if(col>0){
            temp.push_back('L');
            solve(maze,n,row,col-1, temp);
            temp.pop_back();
        }
        if(col<n-1){
            temp.push_back('R');
            solve(maze,n,row,col+1, temp);
            temp.pop_back();
        }
        if(row>0){
            temp.push_back('U');
            solve(maze,n,row-1,col, temp);
            temp.pop_back();
        }
        
        maze[row][col] = 1;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        if (maze.empty() || maze[0][0] == 0)
            return {};
        int n=maze.size();
        string temp;
        solve(maze,n,0,0, temp);
        return result;
        
    }
};