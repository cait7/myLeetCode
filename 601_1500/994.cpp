////
////  main.cpp
////  leetCodeProject
////
////  Created by 蔡倓 on 2020/2/9.
////  Copyright © 2020 蔡倓. All rights reserved.
////
//
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int count, old_count;
        
        count = 0;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }
        

        int times = 0;
        while (count) {
            
            old_count = count;
            
            for (int i=0; i<grid.size(); i++) {
                for (int j=0; j<grid[0].size(); j++) {
                    if (grid[i][j] == 2) {
                        if (j-1 >= 0 && grid[i][j-1] == 1) {
                            grid[i][j-1] = -1;
                            count--;
                        }
                        if (j+1 < grid[0].size() && grid[i][j+1] == 1) {
                            grid[i][j+1] = -1;
                            count--;
                        }
                        if (i-1 >= 0 && grid[i-1][j] == 1) {
                            grid[i-1][j] = -1;
                            count--;
                        }
                        if (i+1 < grid.size() && grid[i+1][j] == 1) {                       grid[i+1][j] = -1;
                            count--;
                        }
                    }
                }
            }
            
            for (int i=0; i<grid.size(); i++) {
                for (int j=0; j<grid[0].size(); j++) {
                    grid[i][j] = grid[i][j] == -1 ? 2 : grid[i][j] ;
                }
            }
            
            if (old_count == count) {
                return -1;
            }

            times++;
        }

        return times;
    }
};

int main() {
    Solution *obj = new Solution();

    vector<vector<int>> nums(3, vector<int>(3));

    nums[0][0] = 2;
    nums[0][1] = nums[0][2] = nums[1][0] = nums[1][1] = nums[2][1] = nums[2][2] = 1;
    
    cout << obj->orangesRotting(nums) << endl;
    return 0;
}

