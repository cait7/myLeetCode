class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> contains, left, right;
        for (int i=0; i<nums.size(); i++) {
            if (contains.find(nums[i]) == contains.end()) {
                contains[nums[i]] = 1;
            }
            else {
                contains[nums[i]]++;
            }
            if (left.find(nums[i]) == left.end()) {
                left[nums[i]] = i;
            }
            if (right.find(nums[ nums.size() - 1 - i ]) == right.end()) {
                right[nums[ nums.size() - 1 - i ]] = nums.size() - 1 - i;
            }
        }
        int degree = 0;
        for (auto& iter: contains) {
            if (iter.second > degree) {
                degree = iter.second;
            }
        }
        int ans = INT_MAX;
        for (auto& iter: contains) {
            if (iter.second == degree) {
                ans = min(ans, right[iter.first] - left[iter.first] + 1);
            }
        }
        return ans;
    }
};
