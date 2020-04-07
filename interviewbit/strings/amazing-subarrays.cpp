int Solution::solve(string A) {
    int n=A.length();
    int sum = 0;
    for (int i=0;i<n;i++) {
        A[i] = tolower(A[i]);
        if (A[i] == 'a' ||
        A[i] == 'e' ||
        A[i] == 'i' ||
        A[i] == 'o' ||
        A[i] == 'u'
        )
        sum = (sum + n-i + 10003) % 10003;
    }
    return sum;
}
