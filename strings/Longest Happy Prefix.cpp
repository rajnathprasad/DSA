class Solution {
public:
    vector<int> buildLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);

        int len = 0;
        int i = 1;

        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            }
            else {
                if (len != 0)
                    len = lps[len - 1];
                else
                    i++;
            }
        }

        return lps;
    }

    string longestPrefix(string s) {
        vector<int> lps = buildLPS(s);

        int len = lps.back();

        return s.substr(0, len);
    }
};