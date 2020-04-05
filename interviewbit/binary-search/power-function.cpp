int Solution::pow(int x, int n, int d) {
    long long int res=1;
    if (x == 0) {
        return 0;
    }
    while (n>0) {
        if (n&1) res = (res * x * 1LL + d) %d;
        x = (x * 1LL * x + d) %d;
        n>>=1;
    }
    return res;
}
