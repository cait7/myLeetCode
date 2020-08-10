class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left, right, ans, res;

        ans = res = 0;
        left = 0;
        right = height.size() - 1;

        while (left < right) {
            ans = min(height[left], height[right]) * (right - left);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }

            res = max(res, ans);
        }

        return res;
    }
};
