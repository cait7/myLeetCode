class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans, left, right, currCost;
        ans = left = right = currCost = 0;
        for (; right<s.size(); right++) {
            currCost += abs(s[right]-t[right]);
            while (currCost > maxCost) {
                currCost -= abs(s[left]-t[left]);
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};
