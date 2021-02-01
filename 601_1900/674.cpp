class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        int ans;
        ans = dp[0] = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
                ans = max(ans, dp[i]);
            }
            else {
                dp[i] = 1;
            }
        }
        return ans;
    }
};
