class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        return total%2 ? findKthNumber(nums1, nums2, (total-1)/2) : (findKthNumber(nums1, nums2, (total-1)/2) + findKthNumber(nums1, nums2, (total-1)/2 + 1))/2.0;

    }

    int findKthNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int id1 = 0, id2 = 0;
        while (k--) {
            if (id1 == nums1.size()) {
                id2++;
            }
            else if (id2 == nums2.size()) {
                id1++;
            }
            else {
                nums1[id1] > nums2[id2] ? id2++ : id1++;
            }
        }
        return id1==nums1.size() ? nums2[id2] : (id2==nums2.size() ? nums1[id1] : min(nums1[id1], nums2[id2]) );
    }
};
