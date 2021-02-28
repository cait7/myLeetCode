class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }

    int mergeSort(vector<int>& nums, int s, int e) {
        if (s >= e) {
            return 0;
        }
        int ans = 0, mid = (s + e) / 2;
        ans += mergeSort(nums, s, mid);
        ans += mergeSort(nums, mid+1, e);
        ans += merge(nums, s, mid, e);
        return ans;
    }

    int merge(vector<int>& nums, int s, int m, int e) {
        // nums1: [s, m]; nums2: [m+1, e]
        vector<int> mergeArray(e-s+1, 0);
        int id1 = s, id2 = m+1, ans = 0;
        for (int i=0; i<e-s+1; i++) {
            if (id1 == m+1) {
                mergeArray[i] = nums[id2];
                id2++;
            }
            else if (id2 == e+1 || nums[id1] < nums[id2]) {
                mergeArray[i] = nums[id1];
                id1++;
            }
            else {
                mergeArray[i] = nums[id2];
                int indexLargerThanId2 = id1;
                for (; indexLargerThanId2<=m; indexLargerThanId2++) {
                    if (nums[indexLargerThanId2] != nums[id2]) {
                        break;
                    }
                }
                ans += m - indexLargerThanId2 + 1;
                id2++;
            }
        }
        // copy
        for (int i=0; i<e-s+1; i++) {
            nums[i+s] = mergeArray[i];
        }
        return ans;
    }
};

