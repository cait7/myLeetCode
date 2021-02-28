class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> elements;
        for (int ele: nums) {
            if (m.find(ele) != m.end()) {
                m[ele]++;
            }
            else {
                m[ele] = 1;
                elements.push_back(ele);
            }
        }
        sort(elements.begin(), elements.end());
        int success = 0, pairs;
        for (int ele: elements) {
            pairs = m[ele];
            if (pairs == 0) {
                continue;
            }
            success += pairs * k;
            for (int i=0; i<k; i++) {
                if (m.find(ele+i) == m.end() || m[ele+i] < pairs) {
                    return false;
                }
                else {
                    m[ele+i] -= pairs;
                }
            }
        }
        return success == nums.size();
    }
};
