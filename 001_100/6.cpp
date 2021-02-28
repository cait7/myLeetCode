class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int col = (s.size() / (numRows * 2 - 2) + 1) * (numRows-1);
        vector<vector<char>> ans(numRows, vector<char>(col, ' '));
        int x = 0, y = 0, index = 0;
        bool down = true;
        for (; index<s.size(); index++) {
            if (x == 0) {
                down = true;
            }
            else if (x == numRows-1) {
                down = false;
            }
            ans[x][y] = s[index];
            if (down) {
                x += 1;
            }
            else {
                x -= 1;
                y += 1;
            }
        }
        string res;
        for (int i=0; i<numRows; i++) {
            for (int j=0; j<col; j++) {
                if (ans[i][j] == ' ') {
                    continue;
                }
                res += ans[i][j];
            }
        }
        return res;
    }
};
