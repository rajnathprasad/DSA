class Solution {
public:
    int myAtoi(string s) {
        string ansString = "";
        int sign = 1;
        bool started = false;
        for(int i = 0; i < s.size(); i++) {
            if(!started && s[i] == ' ')
                continue;
            if(!started && (s[i] == '+' || s[i] == '-')) {
                started = true;

                if(s[i] == '-')
                    sign = -1;

                continue;
            }
            if(isdigit(s[i])) {
                started = true;
                ansString += s[i];
            }
            else {
                break;
            }
        }
        if(ansString.empty())
            return 0;
        long long ans = 0;
        for(char c : ansString) {
            int digit = c - '0';
            if(sign == 1) {
                if(ans > INT_MAX / 10 ||
                   (ans == INT_MAX / 10 && digit > 7))
                    return INT_MAX;
            }
            else {
                if(ans > INT_MAX / 10 ||
                   (ans == INT_MAX / 10 && digit > 8))
                    return INT_MIN;
            }
            ans = ans * 10 + digit;
        }
        return sign * ans;
    }
};