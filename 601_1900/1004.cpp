class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        vector<bool> status(A.size(), false);
        int ans = 0, left = 0, right;
        for (right = 0; right < A.size(); right++) {
            if (A[right]) {

            }
            else if (!A[right] && K > 0) {
                K--;
                status[right] = true;
            }
            else if (!A[right] && K == 0) {
                bool canMove = false;
                for(; left<right; left++) {
                    if (status[left]) {
                        status[right] = true;
                        status[left] = false;
                        canMove = true;
                        left++;
                        break;
                    }
                }
                if (!canMove) {
                    left++;
                }
            }
            ans = max(ans, right+1-left);
        }
        return ans;
    }
};
