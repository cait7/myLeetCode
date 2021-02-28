class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return isMonotonic(A, true) || isMonotonic(A, false);
    }

    bool isMonotonic(vector<int>& A, bool direction) {
        for (int i=0; i<A.size()-1; i++) {
            if (direction ? A[i] <= A[i+1] : A[i] >= A[i+1]) {
                continue;
            }
            return false;
        }
        return true;
    }
};
