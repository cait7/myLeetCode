class Solution {
public:
    string sortString(string s) {
        unordered_map<char, int> m;
        for (char c: s) {
            if (m.find(c)==m.end()) {
                m[c] = 1;
            }
            else {
                m[c]++;
            }
        }
        return auxSortString(m);
    }

    string auxSortString(unordered_map<char, int> &m) {
        if (!m.size()) return "";
        string ans = "";
        // step 1-3
        for (int i=0; i<26; i++) {
            if (m.find(i+'a')!=m.end()) {
                ans += i+'a';
                if (m[i+'a'] > 1) {
                    m[i+'a']--;
                }
                else {
                    m.erase(i+'a');
                }
            }
        }
        // step 4-6
        for (int i=25; i>=0; i--) {
            if (m.find(i+'a')!=m.end()) {
                ans += i+'a';
                if (m[i+'a'] > 1) {
                    m[i+'a']--;
                }
                else {
                    m.erase(i+'a');
                }
            }
        }
        return ans + auxSortString(m);
    }
};
