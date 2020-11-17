class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> visited(candidates.size(), 0);
        vector<vector<int>> ans;
        ans = findCombinations(candidates, target, visited);
        return ans;
    }

    vector<vector<int>> findCombinations(vector<int> &candidates, int target, vector<int> &visited) {
        if (target < 0) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ans;
        vector<int> prune = visited;
        for (int i=0; i<candidates.size(); i++) {
            int ele = candidates[i];
            if (visited[i]) {
                continue;
            }
            if (ele==target) {
                ans.push_back(vector<int>(1, target));
            }
            else {
                vector<vector<int>> tmp;
                tmp = findCombinations(candidates, target-ele, prune);
                for (vector<int>& i: tmp) {
                    i.push_back(ele);
                    ans.push_back(i);
                }
            }
            prune[i] = 1;
        }
        return ans;
    }
};
