class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> ans(1001, 0);
        for (int i=0; i<target.size(); i++) {
            ans[target[i]]++;
            ans[arr[i]]--;
        }
        for (int i=0; i<1001; i++) {
            if (ans[i]) {
                return false;
            }
        }
        return true;
    }
};
