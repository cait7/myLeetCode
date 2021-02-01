class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        for (int i=0; i<s.size();) {
            int j=i;
            for (; j<s.size(); j++) {
                if (s[i] != s[j]) {
                    break;
                }
            }
            if (j-i > 2) {
                ans.push_back({i, j-1});
            }
            i = j;
        }
        return ans;
    }
};