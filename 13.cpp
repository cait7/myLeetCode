class Solution {
public:
    int romanToInt(string s) {
        string symbol[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        int index = 0;
        int res = 0;

        while (index < s.size()) {
            int i, j;

            for (i=0; i<13; i++) {
                for (j=0; j<symbol[i].size(); j++) {
                    if (symbol[i][j] != s[index+j]) {
                        break;
                    }
                }

                if (j==symbol[i].size()) {
                    res += nums[i];
                    index += symbol[i].size();
                    continue;
                }
            }
        }

        return res;
    }
};
