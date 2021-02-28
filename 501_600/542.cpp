typedef vector<int> Point;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<Point> q;
        int distance = 1, currNodes = 0, nextNodes;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (matrix[i][j] == 0) {
                    ans[i][j] = 0;
                    currNodes++;
                    q.push( vector<int>({i, j}) );
                }
            }
        }
        // set directions
        vector<vector<int>> directions(4, vector<int>(2));
        directions[0][0] = directions[1][0] = directions[2][1] = directions[3][1] = 0;
        directions[0][1] = directions[2][0] = 1;
        directions[1][1] = directions[3][0] = -1;
        // bfs
        while (!q.empty()) {
            nextNodes = 0;
            while (currNodes--) {
                for (int i=0; i<4; i++) {
                    Point p = q.front();
                    p[0] += directions[i][0];
                    p[1] += directions[i][1];
                    if (isValidPoint(p[0], p[1], row, col) && ans[p[0]][p[1]] == -1) {
                        ans[p[0]][p[1]] = distance;
                        nextNodes++;
                        q.push(p);
                    }
                }
                q.pop();
            }
            distance++;
            currNodes = nextNodes;
        }
        return ans;
    }

    inline bool isValidPoint(int x, int y, int row, int col) {
        return x >= 0 && y >= 0 && x < row && y < col;
    }
};
