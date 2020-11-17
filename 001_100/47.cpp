class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        sort(nums.begin(), nums.end());
        executePermute(nums, res, 0, len);
        return s;
    }

    void executePermute(vector<int>& nums, vector<int>& res, int l, int r) {
        if (l==r) {
            s.push_back(res);
        }
        set<int> visited;
        for (int i=l; i<r; i++) {
            if (visited.find(nums[i]) != visited.end()) {
                continue;
            }
            else {
                visited.insert(nums[i]);
            }
            res[l] = nums[i];
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
        }
    }

private:
    vector<vector<int>> s;
};
