class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size(), ans = 0;
        vector<int> dp(len, 0);
        for (int i=1; i<len; i++) {
            if (s[i] == '(') {
                continue;
            }
            if (s[i-1] == '(') {
                dp[i] = (i>1 ? dp[i-2] : 0) + 2;
            }
            else {
                int cnt = 0, index = i;
                while(index>0) {
                    int previous = index-1, mid = previous-dp[previous];
                    if ( mid >= 0 && s[mid] == '(' ) {
                        cnt += dp[previous] + (mid>0 ? dp[mid-1] : 0) + 2;
                        dp[i] = cnt;
                        break;
                    }
                    else {
                        cnt += dp[previous];
                        index = mid;
                    }
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
