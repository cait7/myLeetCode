class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> direction(4, vector<int>(2));
        direction[0][0] = direction[2][0] = direction[1][1] = direction[3][1] = 0;
        direction[0][1] = direction[1][0] = 1;
        direction[2][1] = direction[3][0] = -1;
        int count = 1, x = 0, y = -1;
        while (count <= n * n) {
            // right, down, left, up
            for (int i=0; i<4; i++) {
                while (true) {
                    x += direction[i][0];
                    y += direction[i][1];
                    if (isOutBounds(x, y, n) || ans[x][y]) {
                        break;
                    }
                    ans[x][y] = count++;
                }
                x -= direction[i][0];
                y -= direction[i][1];
            }
        }
        return ans;
    }

    inline bool isOutBounds(int x, int y, int n) {
        return !(x >= 0 && y >= 0 && x < n & y < n);
    }
};
