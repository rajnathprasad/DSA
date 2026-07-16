class Solution {
public:
    vector<string> ans;
    void rec(int i, string s, long sum, long prev,string &nums, int target ){
        if(i==nums.size()){
            if(sum==target)
                ans.push_back(s);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[i]=='0'){
                break;
            }
            long number=stol(nums.substr(i,j-i+1));
            if(i==0){
                rec(j+1,s+nums.substr(i,j-i+1),number, number,nums, target);
            }else{
                rec(j+1,s+'+'+nums.substr(i,j-i+1),sum+number, number,nums, target);
                rec(j+1,s+'-'+nums.substr(i,j-i+1),sum-number, -number,nums, target);
                rec(j+1,s+'*'+nums.substr(i,j-i+1),sum-prev+(prev*number), prev*number,nums, target);
            }
        }

    }
    vector<string> addOperators(string num, int target) {
        rec(0,"",0,0,num,target);
        return ans;
    }
};