class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNums = 0;
        for (int a: nums) {
            zeroNums += a == 0;
        }
        int j=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (int i=nums.size()-zeroNums; i<nums.size(); i++) {
            nums[i] = 0;
        }
    }
};
