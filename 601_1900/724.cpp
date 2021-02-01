class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (!nums.size()) {
            return -1;
        }
        vector<int> sums(nums.size(), 0);
        sums[0] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        int left, right;
        for (int i=0; i<nums.size(); i++) {
            left = i > 0 ? sums[i-1] : 0;
            right = sums.back()-sums[i];
            if (left == right) {
                return i;
            }
        }
        return -1;
    }
};
