//
//  main.cpp
//  leetCodeProject  旋转数组 使用环状替代和反转两种方法
//
//  Created by 蔡倓 on 2020/2/2.
//  Copyright © 2020 蔡倓. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len;
        len = nums.size();
        
        if (len == 0) {
            return;
        }
        
        k = k % len;
        int *temp = new int [k];
        
        for (int i = 0; i < k; i++) {
            temp[i] = nums[len-k+i];
        }
        
        for (int i=len-1; i>=k; i--) {
            nums[i] = nums[i-k];
        }
        
        for (int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
        
        delete [] temp;
    }
    
    void rotate_v2(vector<int>& nums, int k) {
        int len;
        len = nums.size();
        
        if (len == 0) {
            return;
        }
        
        k = k % len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main(int argc, const char * argv[]) {
    int temp[6] = {7,1,5,3,6,4};

    Solution singleInstance;
    vector<int> nums(temp, temp+6);

    singleInstance.rotate_v2(nums, 2);
    
    for (int i=0; i<6; i++) {
        cout << nums[i] << endl;
    }
    
    return 0;
}
