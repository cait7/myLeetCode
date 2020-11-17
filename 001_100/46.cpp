class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        executePermute(nums, res, 0, len);
        return s;
    }

    void executePermute(vector<int>& nums, vector<int>& res, int l, int r) {
        if (l==r) {
            s.push_back(res);
        }
        for (int i=l; i<r; i++) {
            res.push_back(nums[i]);
            // swap
            int temp;
            temp = nums[l];
            nums[l] = nums[i];
            nums[i] = temp;
            executePermute(nums, res, l+1, r);
            // swap
            temp = nums[l];
            nums[l] = nums[i];
            nums[i] = temp;
            res.pop_back();
        }
    }

private:
    vector<vector<int>> s;
};
