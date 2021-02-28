class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<bitset<26>> bWords, bPuzzles;
        for (auto& str: words) {
            bitset<26> b = str2Bitset(str);
            bWords.push_back(b);
        }
        for (auto& str: puzzles) {
            bitset<26> b = str2Bitset(str);
            bPuzzles.push_back(b);
        }
        vector<int> ans(puzzles.size(), 0);
        for (int i=0; i<puzzles.size(); i++) {
            for (int j=0; j<words.size(); j++) {
                if (aCondition(bWords[j], puzzles[i][0]) && bCondition(bPuzzles[i], bWords[j])) {
                    ans[i]++;
                }
            }
        }
        return ans;
    }

    bitset<26> str2Bitset(string& str) {
        bitset<26> b;
        for (auto c: str) {
            b[c-'a'] = 1;
        }
        return b;
    }

    inline bool aCondition(bitset<26> &a, char c) {
        return a[c-'a'];
    }

    inline bool bCondition(bitset<26> &a, bitset<26> &b) {
        return !((a & b) ^ b).any();
    }
};
