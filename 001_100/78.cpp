class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans({ vector<int>() });
        int size;
        for (auto ele: nums) {
            size = ans.size();
            for (int i=0; i<size; i++) {
                vector<int> subset = ans[i];
                subset.push_back(ele);
                ans.push_back(subset);
            }
        }
        return ans;
    }
};
