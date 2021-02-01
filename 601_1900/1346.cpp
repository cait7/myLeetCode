class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int len = arr.size();
        sort(arr.begin(), arr.end());
        for (int i=0; i<len; i++) {
            int ele = arr[i]*2, l, r;
            l = arr[i] > 0 ? i+1 : 0;
            r = arr[i] > 0 ? len-1 : i-1;
            while (l<=r) {
                int mid = (l+r)/2;
                if (arr[mid] == ele && mid != i) {
                    return true;
                }
                else if (arr[mid] < ele) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return false;
    }
};
