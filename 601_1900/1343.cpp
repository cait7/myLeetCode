class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, i = 0, ans = 0;
        threshold *= k;
        for (; i<k; i++) {
            sum += arr[i];
        }
        if (sum >= threshold) {
            ans++;
        }
        for (; i<arr.size(); i++) {
            sum += arr[i] - arr[i-k];
            if (sum >= threshold) {
                ans++;
            }
        }
        return ans;
    }
};
