//
//  main.cpp
//  leetCodeProject 121. 买卖股票的最佳时机 I
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
        if (prices.size() == 0) {
            return 0;
        }
        
        int minPrice, maxProfit;
        
        minPrice  = prices[0];
        maxProfit = 0;
        for (int i=0; i<prices.size(); i++) {
            minPrice = min(prices[i], minPrice);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        
        return maxProfit;
    }
};

int main(int argc, const char * argv[]) {
    int temp[6] = {7,1,5,3,6,4};
    
    Solution singleInstance;
    int result = 0;
    vector<int> nums(temp, temp+5);

    result = singleInstance.maxProfit(nums);
    cout << result << endl;
    
    return 0;
}
