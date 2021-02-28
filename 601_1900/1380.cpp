class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> luckyRow(m, 0), luckyCol(n, 0);
        for (int i=0; i<m; i++) {
            int lucky = 0;
            for (int j=0; j<n; j++) {
                if (matrix[i][lucky] > matrix[i][j]) {
                    lucky = j;
                }
            }
            luckyRow[i] = lucky;
        }
        for (int i=0; i<n; i++) {
            int lucky = 0;
            for (int j=0; j<m; j++) {
                if (matrix[j][i] > matrix[lucky][i]) {
                    lucky = j;
                }
            }
            luckyCol[i] = lucky;
        }
        vector<int> ans;
        for (int i=0; i<m; i++) {
            if (luckyCol[ luckyRow[i] ] == i) {
                ans.push_back( matrix[i][luckyRow[i]] );
            }
        }
        return ans;
    }
};
