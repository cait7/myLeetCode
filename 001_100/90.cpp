class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto ele: nums) {
            if (m.find(ele) == m.end()) {
                m[ele] = 1;
            }
            else {
                m[ele] += 1;
            }
        }
        vector<vector<int>> ans({vector<int>()});
        int size = 0;
        for (auto iter: m) {
            size = ans.size();
            for (int i=0; i<size; i++) {
                vector<int> subset = ans[i];
                for (int j=1; j<=iter.second; j++) {
                    subset.push_back(iter.first);
                    ans.push_back(subset);
                }
            }
        }
        return ans;
    }
};
