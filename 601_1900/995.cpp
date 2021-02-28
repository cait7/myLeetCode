class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int reverses = 0, i;
        vector<bool> turned(A.size(), 0);
        for (i=0; i<K-1 && i<=A.size()-K; i++) {
            if ( reverses%2 ^ !(A[i]) ) {
                turned[i] = 1;
                reverses++;
            }
        }
        for (; i<A.size(); i++) {
            if ( reverses%2 ^ !(A[i]) ) {
                if (i > A.size() - K) {
                    return -1;
                }
                turned[i] = 1;
                reverses++;
            }
            if (i-K+1 >= 0)
                reverses -= turned[i-K+1];
        }
        int ans = 0;
        for (auto ele: turned) {
            ans += ele;
        }
        return ans;
    }
};
