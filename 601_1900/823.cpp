class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> dp;
        int factor = 1000000007;
        int ans = 0;
        for (int i=0; i<arr.size(); i++) {
            dp[arr[i]] = 1;
            for (int j=0; j<i; j++) {
                if (arr[i]%arr[j] == 0 && dp.find(arr[i]/arr[j]) != dp.end()) {
                    dp[arr[i]] = (dp[arr[i]] + ((long long)dp[arr[j]] * dp[arr[i]/arr[j]])) % factor;
                }
            }
            ans = (ans + dp[arr[i]]) % factor;
        }
        return ans;
    }
};
