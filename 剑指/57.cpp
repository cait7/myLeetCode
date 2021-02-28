class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (auto ele: nums) {
            if (m.find(ele) == m.end()) {
                m[ele] = 1;
            }
            else {
                m[ele]++;
            }
        }
        for (auto ele: nums) {
            m[ele]--;
            if (m.find(target-ele) != m.end() && m[target-ele] > 0) {
                return vector<int>({ele, target-ele});
            }
            m[ele]++;
        }
        return vector<int>();
    }
};
