class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row1(rowIndex+1, 1), row2(rowIndex+1, 1);
        int iterator = 1;
        for (int i=1; i<=rowIndex+1; i++) {
            // row1 -> row2
            if (i%2 == 0) {
                for (int j=1; j<i-1; j++) {
                    row2[j] = row1[j-1] + row1[j];
                }
            }
            // row2 -> row1
            else {
                for (int j=1; j<i-1; j++) {
                    row1[j] = row2[j-1] + row2[j];
                }
            }
        }
        return rowIndex % 2 ? row2 : row1;
    }
};
