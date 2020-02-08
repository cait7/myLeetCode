//
//  main.cpp
//  leetCodeProject
//
//  Created by 蔡倓 on 2020/2/8.
//  Copyright © 2020 蔡倓. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        if (row == 0) {
            col = 0;
        }
        else {
            col = matrix[0].size();
        }
        
        for (int i=0; i<row; i++) {
            vector<int> tempRow;
            int sum = 0;
            
            for (int j=0; j<col; j++) {
                sum += matrix[i][j];
                tempRow.push_back(sum);
            }
            
            sumsData.push_back(tempRow);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row2 = row2 >= row ? row - 1: row2;
        col2 = col2 >= col ? col - 1: col2;
        
        int res = 0;
        if (col1 == 0) {
            for (int i=row1; i<=row2; i++) {
                res += sumsData[i][col2];
            }
        }
        else {
            for (int i=row1; i<=row2; i++) {
                res += sumsData[i][col2] - sumsData[i][col1-1];
            }
        }
        
        return res;
    }
    
private:
    int row, col;
    vector<vector<int>> sumsData;
};

int main() {
    vector<int> row1({1, 2, 3});
    vector<vector<int>> matrix({row1, row1, row1});
    
    NumMatrix *obj = new NumMatrix(matrix);
    int res = obj->sumRegion(1, 1, 2, 2);
    
    cout << res << endl;
    return 0;
}
