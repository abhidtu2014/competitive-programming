void preCompute (vector <vector <int> > &nck, int n, int k, long long int m) {
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=min(i,k);j++) {
            if (j==0 || j==i) nck[i][j]=1;
            else {
                nck[i][j] = (nck[i-1][j-1]+nck[i-1][j])%m;
            }
        }
    }
}

int getLeft (int n) {
    int h = log2(n+1);
    int nodes = 1<<h;
    int last = n - ((1 << h) - 1); 
      if (last >= (nodes>>1))
        return (1 << h) - 1;
    else
        return (1 << h) - 1 - ((nodes>>1) - last);
}

int numOfHeaps (vector <vector <int> > &nck, vector<int> &dp, int n, long long int m) {
    if (n<=1) return 1;
    if (dp[n]!=-1) return dp[n];
    int left = getLeft(n);
    long long int ans = ( nck[n-1][left] * 1LL )%m;
    long long int pre = ( numOfHeaps(nck, dp, left, m) * 1LL * numOfHeaps(nck, dp, n-left-1, m) )%m;
    ans = (ans * pre)%m;
    dp[n] = ans;
    return ans;
}
int Solution::solve(int A) {
    long long int m = 1e9+7;
    vector<int> dp (A+1, -1);
    vector <vector <int> > nck (A+1, vector <int> (A+1, -1));
    preCompute(nck, A, A, m);
    return numOfHeaps(nck, dp, A, 1e9+7);
}

