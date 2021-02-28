class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s;
        for (int ele: nums) {
            s.insert(ele);
        }
        int value = 1;
        while (true) {
            if (s.find(value) != s.end()) {
                value++;
                continue;
            }
            break;
        }
        return value;
    }
};
