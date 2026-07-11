class Solution {
public:
    vector<vector<int>> result;
    void solve(vector<int> &candidates, vector<int> &temp, int i, int sum, int target){
        if(sum == target){
            result.push_back(temp);
            return;
        }
        if(sum>target || i==candidates.size())
            return;
        temp.push_back(candidates[i]);
        solve(candidates, temp,i+1,sum+candidates[i], target);
        temp.pop_back();
        while (i+1<candidates.size() && candidates[i]==candidates[i+1])
            i++;
        solve(candidates, temp,i+1,sum, target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(candidates, temp,0,0, target);
        return result;
    }
};