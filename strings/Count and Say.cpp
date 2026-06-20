class Solution {
public:
    string encode(string s){
        string ans="";
        vector<pair<char,int>> v;
        char c=s[0];
        int count=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==c){
                count++;
            }else{
                v.push_back({c, count});
                c = s[i];
                count = 1;
            };
        }
        v.push_back({c, count});
        for(int i=0;i<v.size();i++){
            ans += to_string(v[i].second);
            ans += v[i].first;
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++){
            ans=encode(ans);
        }
        return ans;
    }
};