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
    vector<int> processQueries(vector<int>& queries, int m) {

        int* position = new int [m];
        for (int i=0; i<m; i++) {
            position[i] = i+1;
        }

        vector<int> res;

        for (int i=0; i<queries.size(); i++) {
            int temp1, temp2;
            temp1 = position[0];
            for (int j=0; j<m; j++) {
                if (position[j] == queries[i]) {
                    position[0] = queries[i];
                    position[j] = temp1;
                    res.push_back(j);
                    break;
                }

                if (j > 0) {
                    temp2 = position[j];
                    position[j] = temp1;
                    temp1 = temp2;
                }
            }
            
            for (int w=0; w<m; w++) {
                cout << position[w] << " ";
            }
            cout << endl;
        }

        return res;
    }
};

int main() {
    Solution *obj = new Solution();
    int nums[4] = {3, 1, 2, 1};

    vector<int> query(nums, nums+4);
    vector<int> res = obj->processQueries(query, 5);
    
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}

