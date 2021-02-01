class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int len = A.size(), l = 0, r = len-1, mid;

        while (l < r) {
            mid = (l+r)/2;
            if (A[mid] > 0) {
                r = mid - 1;
            }
            else if (A[mid] < 0) {
                l = mid + 1;
            }
            else {
                break;
            }
        }

        vector<int> res(len, 0);
        int lIndex , rIndex, count = len;

        mid = l == r ? l : mid;
        lIndex = A[mid] > 0 ? mid-1 : mid;
        rIndex = A[mid] > 0 ? mid : mid+1;

        while(count) {
            if (lIndex < 0 || rIndex < len && A[lIndex]*A[lIndex] > A[rIndex]*A[rIndex]) {
                res[len-count] = A[rIndex]*A[rIndex];
                rIndex += 1;
            }
            else {
                res[len-count] = A[lIndex]*A[lIndex];
                lIndex -= 1;
            }

            count -= 1;
        }


        return res;
        
    }
};
