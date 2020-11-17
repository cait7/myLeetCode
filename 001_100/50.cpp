class Solution {
public:
    double myPow(double x, int n) {
        if (n==0 || x==1) {
            return 1;
        }
        long long N = n;
        return n > 0 ? quickPow(x, N) : 1/quickPow(x, -N);
    }

    double quickPow(double x, long long n) {
        if (n==1) {
            return x;
        }
        if (n==2) {
            return x*x;
        }
        return n%2 ? quickPow(x*x, n/2)*x : quickPow(x*x, n/2);
    }
};
