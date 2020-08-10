class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> table;
        int len, i, j, res;

        len = s.size();
        i = j = res = 0;
        for (i=0; i<len; i++) {
            
            while (j < len && !table.count(s[j])) {
                table.insert(s[j]);
                j++;
            }

            res = res > table.size() ? res : table.size();

            table.erase(s[i]);
        }

        return res;
    }
};
