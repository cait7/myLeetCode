class Solution {
public:
    int minFlips(string target) {
        int ans = 0;
        for (int i=0; i<target.size(); i++) {
            if (target[i] == '0' && ans%2 == 0 || target[i] == '1' && ans%2 == 1 ) {
                continue;
            }
            ans++;
        }
        return ans;
    }

    inline void reverse(string& str, int start) {
        for (; start<str.size(); start++) {
            str[start] = str[start] == '0' ? '1' : '0';
        }
    }
};
