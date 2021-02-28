class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change = 1;
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] <= nums[i+1]) {
                continue;
            }
            int value;
            bool check1, check2;
            value = nums[i];
            nums[i] = nums[i+1];
            check1 = isPossibility(nums);
            nums[i] = nums[i+1] = value;
            check2 = isPossibility(nums);
            return check1 || check2;
        }
        return true;
    }

    bool isPossibility(vector<int>& nums) {
        for (int i=0; i<nums.size()-1; i++) {
            if (nums[i] <= nums[i+1]) {
                continue;
            }
            return false;
        }
        return true;
    }
};
