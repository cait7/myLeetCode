class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> aNum(s.size(), 0);
        aNum[0] = s[0] == 'a';
        for (int i=1; i<s.size(); i++) {
            aNum[i] = aNum[i-1] + (s[i] == 'a');
        }
        int ans = aNum.back(), left, right;
        for (int i=0; i<s.size(); i++) {
            left = i + 1 - aNum[i];
            right = aNum.back() - aNum[i];
            ans = min(ans, left + right);
        }
        return ans;
    }
};
