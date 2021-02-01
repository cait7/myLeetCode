class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] < 0 && nums[1] < 0) {
            return max(nums[0]*nums[1]*nums.back(), nums[nums.size()-3]*nums[nums.size()-2]*nums.back());
        }
        return nums[nums.size()-3]*nums[nums.size()-2]*nums.back();
    }
};
