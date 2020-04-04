int Solution::titleToNumber(string A) {
    reverse(A.begin(), A.end());
    int n = A.size();
    int num=0;
    for (int i = 0;i<n ;i++) {
        num += pow(26, i) * (int)(A[i] - 'A' + 1);
    }
    return num;
}
