class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        for (int i=0; i<s.size(); i++) {
            int current = s[i] == '*' ? 9 : (s[i] == '0' ? 0 : 1), last = 0;
            if (i==0) {
                dp[i] = current;
                continue;
            }
            if (s[i-1] == '*') {
                last = s[i] == '*' ? 15: (s[i] <= '6' ? 2 : 1);
            }
            else if (s[i-1] == '0') {
                last = 0;
            }
            else if (s[i] == '*') {
                last = s[i-1] == '1' ? 9 : (s[i-1] == '2' ? 6 : 0);
            }
            else {
                last = (s[i-1] - '0') * 10 + s[i] - '0' <= 26 ? 1 : 0;
            }
            dp[i] = current * dp[i-1] + last * (i > 1 ? dp[i-2] : 1);
            dp[i] %= 1000000007;
        }
        return dp[s.size()-1];
    }
};
