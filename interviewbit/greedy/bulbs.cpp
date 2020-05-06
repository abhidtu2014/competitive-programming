// Idea is to propagate count forward
// if forwaded count for current index is odd, toggle value at current Index
// If Toggle value comes out to be zero itself, increase count
int Solution::bulbs(vector<int> &A) {
    int cnt = 0, n=A.size();
    for (int i=0;i<n;i++) {
        A[i] = A[i]-(cnt&1);
        if (A[i] == 0) cnt++;
    }
    return cnt;
}
