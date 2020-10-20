
int function1(int n, int m) {
    
    if (m == 1 || n == 0) {
        return 1;
    }
    
    if (m > n) {
        return function1(n, n);
    }
    
    return function1(n, m-1) + function1(n-m, m);
}
