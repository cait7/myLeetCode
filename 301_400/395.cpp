class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s, 0, s.size(), k);
    }

    int longestSubstring(string& str, int s, int e, int k) {
        if (s > e) {
            return 0;
        }
        vector<int> letters(26, 0);
        for (int i=s; i<e; i++) {
            letters[str[i]-'a']++;
        }
        for (int i=0; i<26; i++) {
            if (letters[i] > 0 && letters[i] < k) {
                int ans = 0;
                for (int t=s; t<=e; t++) {
                    if (t == e || str[t] == i+'a') {
                        ans = max(ans, longestSubstring(str, s, t, k));
                        s = t+1;
                    }
                }
                return ans;
            }
        }
        return e-s;
    }
};
