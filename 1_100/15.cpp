class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len;
        vector<vector<int>> res;

        len = nums.size();
        sort(nums.begin(), nums.end());

        for (int i=0; i<len; i++) {
            if (i==0 || nums[i]!=nums[i-1]) {
                for (int j=i+1; j<len; j++) {
                    if (j==i+1 || nums[j]!=nums[j-1]) {
                        if (search(nums, -1*(nums[i]+nums[j]), j+1)) {
                            vector<int> temp(3, 0);
                            temp[0] = nums[i];
                            temp[1] = nums[j];
                            temp[2] = -1*(nums[i]+nums[j]);

                            res.push_back(temp);
                        }
                    }
                }
            }
        }

        return res;
    }

    bool search(vector<int>& nums, int val, int pos) {
        int l, r;

        l = pos;
        r = nums.size()-1;

        while (l <= r) {
            int medium = nums[ (l+r)/2 ];

            if (medium == val) {
                return true;
            }
            else if (medium > val) {
                r = (l+r)/2 - 1;
            }
            else {
                l = (l+r)/2 + 1;
            }
        }

        return false;
    }
};
