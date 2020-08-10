//
//  main.cpp
//  leetCodeProject
//
//  Created by 蔡倓 on 2020/2/9.
//  Copyright © 2020 蔡倓. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int temp = num, c = 0;
        
        while (temp > 0) {
            temp >>= 1;
            c = (c << 1) + 1;
        }

        return c - num;
    }
};

int main() {
    Solution *obj = new Solution();
    cout << obj->findComplement(5);
    return 0;
}
