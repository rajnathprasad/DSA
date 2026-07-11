class Solution {
public:
    unordered_map<char, string> mpp={
            {'1' , ""},
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };
    vector<string> result;
    void solve(string &digits,int idx, string &temp){
        if(digits.size()==temp.size()){
            result.push_back(temp);
            return;
        }
        for (char ch : mpp[digits[idx]]){
            temp.push_back(ch);
            solve(digits, idx + 1, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string temp="";
        solve(digits,0,temp);
        return result;
    }
};