class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        k = cardPoints.size() - k;
        // 计算 sum
        int sum = 0;
        for (auto ele: cardPoints) {
            sum += ele;
        }
        // 计算最小连续和
        int curr = 0, minSum;
        for (int i=0; i<k; i++) {
            curr += cardPoints[i];
        }
        minSum = curr;
        for (int i=k; i<cardPoints.size(); i++) {
            curr += cardPoints[i] - cardPoints[i-k];
            minSum = min(curr, minSum);
        }
        return sum - minSum;
    }
};
