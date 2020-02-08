//
//  main.cpp
//  leetCodeProject
//
//  Created by 蔡倓 on 2020/2/2.
//  Copyright © 2020 蔡倓. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) {
        arrays = nums;
    }
    
    int sumRange(int i, int j) {
        j = j > arrays.size() - 1 ? arrays.size() - 1: j;
        
        int res = 0;
        for (; i <= j; i++) {
            res += arrays[i];
        }
        
        return res;
    }
    
private:
    vector<int> arrays;
};

int main(int argc, const char * argv[]) {
    int temp[6] = {7, 7, 1, 1, 5};
    
    vector<int> nums(temp, temp+6);

    NumArray *obj = new NumArray(nums);
    int res = obj->sumRange(0, 2);
    cout << res << endl;
    
    return 0;
}
