class Solution {
public:
    int xorOperation(int n, int start) {
        int ans = start;
        for (int i=1; i<n; i++) {
            ans ^= 2*i + start;
        }
        return ans;
    }
};