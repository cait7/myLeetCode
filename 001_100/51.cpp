class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int *columns = new int [n];
        int *diagonal1 = new int [2*n-1];
        int *diagonal2 = new int [2*n-1];
        memset(columns, 0, sizeof(int)*n);
        memset(diagonal1, 0, sizeof(int)*(2*n-1));
        memset(diagonal2, 0, sizeof(int)*(2*n-1));
        for (int i=0; i<n; i++) {
            map.push_back(string(n, '.'));
        }
        findQueens(0, n, columns, diagonal1, diagonal2);
        return res;
    }

    void findQueens(int row, int n, int *cols, int *diagonal1, int *diagonal2) {
        if (row == n) {
            res.push_back(map);
        }
        int count = 0;
        for (int i=0; i<n; i++) {
            if (!cols[i] && !diagonal1[i+row] && !diagonal2[i-row+n-1]) {
                cols[i] = 1;
                diagonal1[i+row] = 1;
                diagonal2[i-row+n-1] = 1;
                map[row][i] = 'Q';
                findQueens(row+1, n, cols, diagonal1, diagonal2);
                cols[i] = 0;
                diagonal1[i+row] = 0;
                diagonal2[i-row+n-1] = 0;
                map[row][i] = '.';
            }
        }
    }

private:
    vector<string> map;
    vector<vector<string>> res;
};
