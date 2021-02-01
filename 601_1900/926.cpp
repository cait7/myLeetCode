class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> hasOne(S.size(), 0);
        int ones = 0;
        for (int i=0; i<S.size(); i++) {
            ones += S[i] - '0';
            hasOne[i] = ones;
        }
        int ans = S.size() - hasOne.back(), convert2Zero, convert2One;
        for (int i=0; i<S.size(); i++) {
            convert2Zero = hasOne[i];
            convert2One = S.size() - i - 1 - (hasOne.back() - hasOne[i]);
            ans = min(ans, convert2One + convert2Zero);
        }
        return ans;
    }
};
