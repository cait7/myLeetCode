class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int aSum, bSum;
        aSum = bSum = 0;
        for (auto num: A) {
            aSum += num;
        }
        for (auto num: B) {
            bSum += num;
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for (auto num1: A) {
            for (auto num2: B) {
                if (aSum - num1 + num2 == bSum - num2 + num1 ) {
                    return vector<int>({num1, num2});
                }
            }
        }
        return vector<int>();
    }
};
