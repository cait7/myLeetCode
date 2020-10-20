class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<vector<string>> dp(n+1, vector<string>());

        dp[0].push_back("");
        dp[1].push_back("()");

        for (int i=2; i<n+1; i++) {
            for (int j=0; j<i; j++) {
                // dp[i] = dp[j] + dp[i-j-1];

                int len1, len2;

                len1 = dp[j].size();
                len2 = dp[i-j-1].size();

                for (int m=0; m<len1; m++) {
                    for (int n=0; n<len2; n++) {
                        string temp = "";

                        temp = "(" + dp[j][m] + ")" + dp[i-j-1][n];
                        dp[i].push_back(temp);
                    }
                }
            }
        }

        return dp[n];
    }
};
