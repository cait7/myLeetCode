class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> oddLen(arr.size(), 1), evenLen(arr.size(), 1);
        int ans = 1;
        for (int i=0; i<arr.size()-1; i++) {
            if (i%2 ? arr[i] > arr[i+1] : arr[i] < arr[i+1]) {
                evenLen[i+1] = evenLen[i] + 1;
                ans = max(evenLen[i+1], ans);
            }
            if (i%2 ? arr[i] < arr[i+1] : arr[i] > arr[i+1]) {
                oddLen[i+1] = oddLen[i] + 1;
                ans = max(oddLen[i+1], ans);
            }
        }
        return ans;
    }
};
