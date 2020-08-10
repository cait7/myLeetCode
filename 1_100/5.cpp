class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = s.size();
        vector<vector<int>> table(len, vector<int>(len, 0));
        string res;

        for (int i=len; i>=0; i--) {
            for (int j=i; j<len; j++) {
                if (i == j)
                    table[i][j] = 1;
                else if (i+1 == j)
                    table[i][j] = (s[i] == s[j]);
                else {
                    table[i][j] = table[i+1][j-1] && s[i] == s[j];
                }

                if (table[i][j] && res.size() < (j-i+1)) {
                    res = s.substr(i, j-i+1);
                }
            }
        }

        return res;

    }
};
