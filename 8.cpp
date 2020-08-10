class Solution {
public:
    int myAtoi(string str) {
        long res;
        int maxValue, minValue, start, len, flag, overflow;

        maxValue = 0x7fffffff;
        minValue = (int)0x80000000;
        start = 0;
        res = 0;
        len = str.size();

        if (!len) return 0;

        for (int i=0; i<len; i++) {
            if (str[i] == ' ')
                continue;
            else if (str[i] == '+') {
                flag = 1;
                start = i+1;
                break;
            }
            else if (str[i] == '-') {
                flag = -1;
                start = i+1;
                break;
            }
            else if (str[i] >= '0' && str[i] <= '9') {
                flag = 1;
                start = i;
                break;
            }
            else {
                return 0;
            }
        }

        while(str[start] >= '0' && str[start] <= '9') {
            res = res * 10 + (str[start] - '0') * flag;
            start += 1;

            if (res > maxValue || res < minValue) {
                overflow = true;
                break;
            }
            else {
                overflow = false;
            }
        }

        if (res > maxValue) {
            return maxValue;
        }
        else if (res < minValue) {
            return minValue;
        }
        else {
            return res;
        }
    }
};
