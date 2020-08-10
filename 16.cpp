class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        int res = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i=0; i<len; i++) {

            if (i==0 || nums[i] != nums[i-1]) {
                for (int j=i+1; j<len; j++) {

                    if (j==i+1 || nums[j] != nums[j-1]) {
                        
                        int l, r;

                        l =j+1;
                        r = len-1;

                        while(l<=r) {
                            int sums = nums[(l+r+1)/2] + nums[i] + nums[j];
                            res = abs(sums-target) > abs(res-target) ? res : sums;

                            if (sums < target) {
                                l = (l+r+1)/2 + 1;
                            }
                            else if (sums > target) {
                                r = (l+r+1)/2 - 1;
                            }
                            else {
                                return target;
                            }
                        }
                    }
                }
            }

        }

        return res;
    }
};

