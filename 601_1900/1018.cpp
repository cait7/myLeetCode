class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans(A.size(), 0);
        int ele = 0;
        for (int i=0; i<A.size(); i++) {
            ele = (ele*2 + A[i])%5;
            ans[i] = ele ? false : true;
        }
        return ans;
    }
};
