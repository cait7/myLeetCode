class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l, r, sum;
        vector<vector<int>> ans;
        l = r = sum = 1;
        while (r != target) {
            while (sum < target) {
                r++;
                sum += r;
            }
            if (sum == target) {
                vector<int> seq(r-l+1, 0);
                for (int i=0; i<r-l+1; i++) {
                    seq[i] = i+l;
                }
                ans.push_back(seq);
            }
            sum -= l;
            l++;
        }
        return ans;
    }
};
