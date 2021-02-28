class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int emptyBottles = 0, ans = 0;
        while (numBottles) {
            // 喝掉了所有酒，剩下空瓶子
            emptyBottles += numBottles;
            ans += numBottles;
            // 兑换酒
            numBottles = emptyBottles / numExchange;
            emptyBottles %= numExchange;
        }
        return ans;
    }
};
