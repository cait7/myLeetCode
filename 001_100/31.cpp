class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int iIndex, jIndex;
        for (iIndex=nums.size()-2; iIndex>=0; iIndex--) {
            if (nums[iIndex] < nums[iIndex+1]) {
                break;
            }
        }
        if (iIndex < 0) {
            reverse(nums, 0, nums.size());
            return;
        }
        for (jIndex=nums.size()-1; jIndex>iIndex; jIndex--) {
            if (nums[jIndex] > nums[iIndex]) {
                break;
            }
        }
        int temp = nums[iIndex];
        nums[iIndex] = nums[jIndex];
        nums[jIndex] = temp;
        reverse(nums, iIndex+1, nums.size());
    }

    void reverse(vector<int>& nums, int l, int r) {
        vector<int> c = nums;
        int len = nums.size();
        for (int i=l; i<r; i++) {
            nums[i] = c[len-i+l-1];
        }
    }
};
