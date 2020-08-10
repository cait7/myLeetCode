#include <sstream>

class Solution {
public:
    bool isPalindrome(int x) {
        stringstream ss;
        string str;

        ss << x;
        ss >> str;

        int start, end;
        start = 0;
        end = str.size()-1;

        while (start < end) {
            if (str[start] == str[end]) {
                start++;
                end--;
                continue;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
