int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    if (n==0) return 0;
    int m = A[0].size();
    if (m == 0) return 0;
    
    vector<vector<int>> cnt(n+1, vector<int>(m+1, 0));
    
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (i == 0) cnt[i][j] = A[i][j];
            else cnt[i][j] = (A[i][j]==1)?(1+cnt[i-1][j]):0;
            
    for (int i=0;i<n;i++)
    sort(cnt[i].rbegin(), cnt[i].rend());
    
    int ans = 0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            ans = max(ans, cnt[i][j]*(j+1));
    return ans;
}
