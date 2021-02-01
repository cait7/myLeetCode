class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp = triangle;
        int left, right;
        for (int i=1; i<triangle.size(); i++) {
            for (int j=0; j<triangle[i].size(); j++) {
                left = (j < triangle[i-1].size()) ? triangle[i-1][j] : INT_MAX;
                right = (j > 0) ? triangle[i-1][j-1] : INT_MAX;
                triangle[i][j] += min(left, right);
            }
        }
        int ans = INT_MAX;
        for (int i=0; i<triangle[triangle.size()-1].size(); i++) {
            ans = min(ans, triangle[triangle.size()-1][i]);
        }
        return ans;
    }
};
