class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> range;
        for (int ele: nums) {
            if (!range.size() || (range.back()+1 == ele && range.size() == 1)) {
                range.push_back(ele);
            }
            else if (range.back()+1 == ele && range.size() == 2) {
                range[1] = ele;
            }
            else {
                ans.push_back(range);
                range = vector<int>({ele});
            }
        }
        if (range.size() != 0) {
            ans.push_back(range);
        }
        vector<string> strAns;
        for (vector<int>& v: ans) {
            if (v.size() == 1) {
                strAns.push_back(to_string(v[0]));
            }
            else {
                strAns.push_back(to_string(v[0])+"->"+to_string(v[1]));
            }
        }
        return strAns;
    }
};
