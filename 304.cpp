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
        sumsData = nullptr;
        if (matrix.empty()) {
            return;
        }
        
        row = matrix.size();
        col = matrix[0].size();
        
        sumsData = new int* [row+1];
        for (int i=0; i<row+1; i++) {
            sumsData[i] = new int [col+1];
        }
        for (int i=0; i<row+1; i++) {
            for (int j=0; j<col+1; j++) {
                sumsData[i][j] = 0;
            }
        }
        
        for (int i=1; i<row+1; i++) {
            for (int j=1; j<col+1; j++) {
                sumsData[i][j] = matrix[i-1][j-1] + sumsData[i][j-1] + sumsData[i-1][j] - sumsData[i-1][j-1];
            }
        }
    }
    
    ~NumMatrix() {
        for (int i=0; i<row+1; i++) {
            delete [] sumsData[i];
        }
        delete [] sumsData;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sumsData == nullptr) {
            return 0;
        }
        return sumsData[row2+1][col2+1] + sumsData[row1][col1] - sumsData[row1][col2+1] - sumsData[row2+1][col1];
    }
    
private:
    int row, col;
    int **sumsData;
};

int main() {
    vector<int> row1({3,0,1,4,2});
    vector<int> row2({5,6,3,2,1});
    vector<int> row3({1,2,0,1,5});
    vector<int> row4({4,1,0,1,7});
    vector<int> row5({1,0,3,0,5});
    vector<vector<int>> matrix({row1, row2, row3, row4, row5});
    
    NumMatrix *obj = new NumMatrix(matrix);
    cout << obj->sumRegion(2, 1, 4, 3) << endl;
    cout << obj->sumRegion(1, 1, 2, 2) << endl;
    cout << obj->sumRegion(1, 2, 2, 4) << endl;

    return 0;
}
