int Solution::adjacent(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();

    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    dp[1][0] =  max(A[0][0], A[1][0]);
    if (m>=2) {
        dp[1][1] = max(max(A[0][1], A[1][1]), dp[1][0]);
    }
    for (int i=2;i<m;i++) {
        dp[1][i] = max(A[0][i], A[1][i]);
        dp[1][i] = max(dp[1][i-1], dp[1][i-2]+dp[1][i]);
    }
    return dp[1][m-1];
}

