//
//  main.cpp
//  leetCodeProject
//
//  Created by 蔡倓 on 2020/2/1.
//  Copyright © 2020 蔡倓. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        vector<int>::iterator iter = nums.begin();
        for (; iter < nums.end() - 1; ) {
            vector<int>::iterator nextIter = iter + 1;
            if (*iter == *nextIter) {
                nums.erase(nextIter);
            }
            else {
                iter++;
            }
        }
        
        return nums.size();
    }
};

int main(int argc, const char * argv[]) {
    int temp[5] = {1, 1, 2, 2, 5};
    
    Solution singleInstance;
    vector<int> nums(temp, temp+5);

    singleInstance.removeDuplicates(nums);
    
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}
