class Solution {
public:
    int translateNum(int num) {
        string numStr = to_string(num);
        vector<int> dp(numStr.size(), 0);
        for (int i=0; i<numStr.size(); i++) {
            if (i==0) {
                dp[i] = 1;
                continue;
            }
            if ((numStr[i-1]-'0')*10 + numStr[i]-'0' < 26 && (numStr[i-1]-'0')*10 + numStr[i]-'0' >= 10) {
                dp[i] = dp[i-1] + (i > 1 ? dp[i-2] : 1);
            }
            else {
                dp[i] = dp[i-1];
            }
        }
        return dp[numStr.size()-1];
    }
};
