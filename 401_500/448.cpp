class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            while (nums[i] != i+1) {
                if (nums[i] == nums[ nums[i] - 1 ]) {
                    break;
                }
                swap(nums, i, nums[i]-1);
            }
        }
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != i+1) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }

    void swap(vector<int>& nums, int i, int j) {
        nums[i] += nums[j];
        nums[j] = nums[i] - nums[j];
        nums[i] = nums[i] - nums[j];
    }
};

