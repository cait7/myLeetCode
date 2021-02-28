class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if (nums.size() * nums[0].size() != r*c) {
            return nums;
        }
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<nums[0].size(); j++) {
                ans[ (i*nums[0].size()+j)/c ][ (i*nums[0].size()+j)%c ] = nums[i][j];
            }
        }
        return ans;
    }
};
