class Solution {
public:
    string compressString(string S) {
        if (S.size() < 1) {
            return "";
        }
        string ans;
        ans += S[0];
        int count = 1;
        for (int i=1; i<S.size(); i++) {
            if (S[i] != S[i-1]) {
                ans += to_string(count);
                ans += S[i];
                count = 0;
            }
            count += 1;
        }
        ans += to_string(count);
        return ans.size() < S.size() ? ans : S;
    }
};
