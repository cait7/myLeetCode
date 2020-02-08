//
//  main.cpp
//  leetCodeProject 波峰波谷法 - 122. 买卖股票的最佳时机 II
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
    int maxProfit(vector<int>& prices) {
        int i, profit, len;
        
        i = profit = 0;
        len = prices.size();
        
        while (i < len - 1) {
            int valley, peak;
            
            valley = peak = prices[i];
            while (i < len - 1 && prices[i] >= prices[i+1]) {
                i++;
            }
            valley = prices[i];
            
            while (i < len - 1 && prices[i] <= prices[i+1]) {
                i++;
            }
            peak = prices[i];
            
            profit += peak - valley;
        }
        
        return profit;
    }
};

int main(int argc, const char * argv[]) {
    int temp[6] = {7,1,5,3,6,4};
    
    Solution singleInstance;
    int result = 0;
    vector<int> nums(temp, temp+6);

    result = singleInstance.maxProfit(nums);
    cout << result << endl;
    
    return 0;
}

