class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans = {-1, -1};
        ans[0] = findLasttNum(nums, target);
        ans[1] = findFirstNum(nums, target);
        return ans;
    }

    int findFirstNum(vector<int>& nums, int target) {
        int len = nums.size(), l = 0, r = len -1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target && ((mid + 1) >= len || nums[mid+1] > target)) {
                return mid;
            }
            else if (nums[mid] <= target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }

    int findLasttNum(vector<int>& nums, int target) {
        int len = nums.size(), l = 0, r = len -1, mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target && ((mid - 1) < 0 || nums[mid-1] < target)) {
                return mid;
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return -1;
    }
};
