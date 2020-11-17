//class Solution {
//public:
//    void solveSudoku(vector<vector<char>>& board) {
//        vector<vector<int>> row(len, vector<int>(len+1, 0)), col(len, vector<int>(len+1, 0)), box(len, vector<int>(len+1, 0));
//        for (int i=0; i<len; i++) {
//            for (int j=0; j<len; j++) {
//                if (board[i][j]!='.') {
//                    int ele = board[i][j]-'0';
//                    row[i][ele] = 1;
//                    col[j][ele] = 1;
//                    box[i/3*3+j/3][ele] = 1;
//                }
//            }
//        }
//        searchSudoku(board, row, col, box);
//    }
//
//    bool searchSudoku(vector<vector<char>> &board, vector<vector<int>> &row, vector<vector<int>> &col, vector<vector<int>> &box) {
//        for (int i=0; i<len; i++) {
//            for (int j=0; j<len; j++) {
//                if (board[i][j] == '.') {
//                    for (int k=1; k<len+1; k++) {
//                        if (!row[i][k] && !col[j][k] && !box[i/3*3+j/3][k]) {
//                            board[i][j] = k + '0';
//                            row[i][k] = col[j][k] = box[i/3*3+j/3][k] = 1;
//                            if (!searchSudoku(board, row, col, box)) {
//                                row[i][k] = col[j][k] = box[i/3*3+j/3][k] = 0;
//                                board[i][j] = '.';
//                            }
//                            else {
//                                return true;
//                            }
//                        }
//                    }
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//
//private:
//    int len = 9;
//};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        len = 9;
        row = col = box = vector<bitset<9>>(len, bitset<9>());
        int count = 0;
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                if (board[i][j] == '.') {
                    count += 1;
                    continue;
                }
                int ele = board[i][j]-'1';
                row[i] |= (1<<ele);
                col[j] |= (1<<ele);
                box[i/3*3+j/3] |= (1<<ele);
            }
        }
        searchSudoku(board, count);
    }

    bool searchSudoku(vector<vector<char>>& board, int count) {
        if (count == 0) return true;
        vector<int> pos = nextPosition(board);
        for (int i=1; i<10; i++) {
            int r = pos[0], c = pos[1];
            if (!row[r].test(i-1) && !col[c].test(i-1) && !box[r/3*3+c/3].test(i-1)) {
                board[r][c] = i + '0';
                row[r].set(i-1);
                col[c].set(i-1);
                box[r/3*3+c/3].set(i-1);
                if (searchSudoku(board, count-1)) return true;
                board[r][c] = '.';
                row[r].reset(i-1);
                col[c].reset(i-1);
                box[r/3*3+c/3].reset(i-1);
            }
        }
        return false;
    }

    vector<int> nextPosition(vector<vector<char>> &board) {
        vector<int> ans;
        int minCnt = INT_MAX;
        for (int i=0; i<len; i++) {
            for (int j=0; j<len; j++) {
                if (board[i][j]=='.') {
                    bitset<9> tmp = row[i] | col[j] | box[i/3*3+j/3];
                    if (len - tmp.count() < minCnt) {
                        minCnt = len - tmp.count();
                        ans = {i, j};
                    }
                }
            }
        }
        return ans;
    }

private:
    int len;
    vector<bitset<9>> row, col, box;
};
