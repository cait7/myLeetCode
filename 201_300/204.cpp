class Solution {
public:
    int countPrimes(int n) {
        vector<int> signs(n, 0);
        int ans = 0;
        for (int i=2; i<n; i++) {
            if (signs[i]) continue;
            ans += 1;
            // Fill the multiple numbers
            int m = i;
            while (m < n) {
                signs[m] = 1;
                m += i;
            }
        }
        return ans;
    }
};
