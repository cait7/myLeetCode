class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int ringLen = ring.size(), keyLen = key.size(), ans = 30000;
        vector<vector<int>> dp(keyLen, vector<int>(ringLen, 0));
        // dp[i][j] 表示第i个key字符，第j个ring字符 移到12点钟方向
        for (int i=0; i<keyLen; i++) {
            for (int j=0; j<ringLen; j++) {
                dp[i][j] = ans;
                if (key[i] != ring[j]) continue;
                else if (i == 0) {
                    dp[i][j] = min(dp[i][j], min(j, ringLen-j)+1);
                }
                else {
                    for (int p=0; p<ringLen; p++) {
                        dp[i][j] = min(dp[i][j], dp[i-1][p] + min(abs(p-j), ringLen-abs(j-p))+1);
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int j=0; j<ringLen; j++) {
            res = min(res, dp[keyLen-1][j]);
        }
        return res;
    }
};
