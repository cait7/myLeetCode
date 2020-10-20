class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> row[9];
        unordered_map<int, int> col[9];
        unordered_map<int, int> box[9];

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                char val = board[i][j];
                
                if (val == '.') {
                    continue;
                }

                if (row[i].find(val) != row[i].end()) {
                    return false;
                }
                else {
                    row[i].insert(unordered_map<int,int>::value_type(val, 1));
                }

                if (col[j].find(val) != col[j].end()) {
                    return false;
                }
                else {
                    col[j].insert(unordered_map<int,int>::value_type(val, 1));
                }

                int boxIndex = (j/3)*3 + i/3;
                if (box[boxIndex].find(val) != box[boxIndex].end()) {
                    return false;
                }
                else {
                    box[boxIndex].insert(unordered_map<int,int>::value_type(val, 1));
                }

            }
        }

        return true;
    }
};
