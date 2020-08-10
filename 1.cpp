class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> res;

        for (int i=0; i<nums.size(); i++) {
            m.insert(pair<int, int>(nums[i], i));
        }

        for (int i=0; i<nums.size(); i++) {
            int secNum = target - nums[i];
            map<int, int>::iterator iter = m.find(secNum);
            if (iter != m.end() && i != iter->second) {
                res.push_back(i);
                res.push_back(iter->second);
                break;
            }
        }

        return res;
    }
};
