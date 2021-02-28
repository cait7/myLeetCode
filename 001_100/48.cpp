class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp;
        for (int i=0; i<matrix.size(); i++) {
            for (int j=i; j<matrix.size(); j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (int i=0; i<matrix.size(); i++) {
            for (int j=0; j<matrix.size()/2; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[i][ matrix.size()-j-1 ];
                matrix[i][ matrix.size()-j-1 ] = temp;
            }
        }
    }
};
