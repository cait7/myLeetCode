class Solution {
public:
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps+1);
        vector<vector<int>> dp(steps+1, vector<int>(arrLen, 0));
        int mod = 1000000007;
        dp[0][0] = 1;
        for (int s=1; s<steps+1; s++) {
            for (int i=0; i<arrLen; i++) {
                dp[s][i] = ((i>0 ? dp[s-1][i-1] : 0) + dp[s-1][i]) % mod + (i+1<arrLen ? dp[s-1][i+1] : 0) % mod;
                dp[s][i] %= mod;
            }
        }
        return dp[steps][0];
    }
};
