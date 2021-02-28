class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i = 0, length;
        priority_queue<int, vector<int>, greater<int>> q;
        for (; i<heights.size()-1; i++) {
            if (heights[i] >= heights[i+1]) {
                continue;
            }
            length = heights[i+1] - heights[i];
            if (q.size() < ladders) {
                q.emplace(length);
                continue;
            }
            else if (q.size() != 0 && length > q.top()) {
                bricks = bricks - q.top();
                q.pop();
                q.emplace(length);
            }
            else {
                bricks -= length;
            }
            if (bricks < 0) {
                break;
            }
        }
        return i;
    }
};
