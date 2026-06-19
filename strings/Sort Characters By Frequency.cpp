class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;
        string ans="";
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>> v(mpp.begin(),mpp.end());
        sort(v.begin(),v.end(),[](auto &a, auto &b  ){
            return a.second>b.second;
        });
        for(int i=0;i<v.size();i++){
            ans += string(v[i].second, v[i].first);
        }
        return ans;
    }
};