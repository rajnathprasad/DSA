class Solution {
public:
    vector<string> result;
    void solve(string &temp, char prev, int &n){
        if(temp.size()==n){
            result.push_back(temp);
            return;
        }
        if(prev=='0'){
            temp.push_back('1');
            solve(temp, '1', n);
            temp.pop_back();
        }else{
            temp.push_back('1');
            solve(temp, '1', n);
            temp.pop_back();

            temp.push_back('0');
            solve(temp, '0', n);
            temp.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        string temp="";
        temp.push_back('0');
        solve(temp, '0', n);
        temp.pop_back();
        temp.push_back('1');
        solve(temp, '1', n);
        temp.pop_back();
        return result;
    }
};