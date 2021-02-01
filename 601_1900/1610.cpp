class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int origin = 0;
        // Part one
        double theta, dist;
        vector<double> thetas;
        for (auto& p: points) {
            if (p == location) {
                origin++;
                continue;
            }
            theta = (atan2(p[1]-location[1], p[0]-location[0])/M_PI)*180;
            thetas.push_back(theta < 0 ? theta + 360 : theta);
        }
        sort(thetas.begin(), thetas.end());
        // Part two
        int ans = 0, left = 0, right = 0;
        for (; left<thetas.size(); ) {
            dist = thetas[right%thetas.size()] - thetas[left];
            dist = right < thetas.size() ? dist : 360 + dist;
            if (dist <= angle) {
                right++;
                ans = max(ans, right-left);
            }
            else {
                left++;
            }
        }
        return ans + origin;
    }
};
