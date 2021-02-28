class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int satisfy = 0, i, ans;
        for (i=0; i<grumpy.size(); i++) {
            satisfy += grumpy[i] ? 0 : customers[i];
        }
        for (i=0; i<X; i++) {
            satisfy += grumpy[i] ? customers[i] : 0;
        }
        ans = satisfy;
        for (; i<grumpy.size(); i++) {
            satisfy += grumpy[i] ? customers[i] : 0;
            satisfy += grumpy[i-X] ? -customers[i-X] : 0;
            ans = max(ans, satisfy);
        }
        return ans;
    }
};
