class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        if (!nums.size()) {
            return 0;
        }
        vector<int> dp(nums.size(), 0);
        ans = dp[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]) {
                dp[i] = dp[i-1] + 1;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};
