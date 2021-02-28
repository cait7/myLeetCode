class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<int, int> m;
        for (auto c: s) {
            if (m.find(c) == m.end()) {
                m[c] = 1;
            }
            else {
                m[c] += 1;
            }
        }
        int ans = 1;
        for (auto iter: m) {
            ans -= iter.second % 2;
        }
        return ans >= 0;
    }
};
