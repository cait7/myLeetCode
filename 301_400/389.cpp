class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> table(26, 0);
        for (char c: s) {
            table[c-'a'] += 1;
        }
        for (char c: t) {
            if (table[c-'a'] <= 0) return c;
            table[c-'a'] -= 1;
        }
        return ' ';
    }
};
