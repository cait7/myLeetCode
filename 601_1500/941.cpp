class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        bool riseUp = true, hasPeak = false;
        for (int i=0; i<arr.size()-1; i++) {
            if (riseUp && arr[i] < arr[i+1]) {
                continue;
            }
            else if (!riseUp && arr[i] > arr[i+1]) {
                continue;
            }
            else if (riseUp && arr[i] > arr[i+1]) {
                hasPeak = i > 0;
                riseUp = false;
            }
            else {
                return false;
            }
        }
        return hasPeak;
    }
};
