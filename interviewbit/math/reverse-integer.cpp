int Solution::reverse(int A) {
    long long int rev=0,x;
    bool isNev = false;
    if (A<0) {
        isNev = true;
        A*=-1;
    }
    while (A>0) {
        rev = rev*10 + A%10;
        A/=10;
    }
    if (isNev) rev*=-1;
    if (rev > INT_MAX || rev < INT_MIN) {
        return 0;
    }
    return rev;
}
