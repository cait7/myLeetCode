class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int maxDist = max(abs(R-r0-1), r0) + max(abs(C-c0-1), c0);
        vector<vector<vector<int>>> buckets(maxDist+1, vector<vector<int>>());
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                int dist = abs(r0-i) + abs(c0-j);
                buckets[dist].push_back({i, j});
            }
        }
        vector<vector<int>> ans;
        for (vector<vector<int>> &b: buckets) {
            for (vector<int> &p: b) {
                ans.push_back(p);
            }
        }
        return ans;
    }
};
