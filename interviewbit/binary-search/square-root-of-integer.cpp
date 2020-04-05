int Solution::sqrt(int A) {
    int low=1, high=A, mid, ans=0;
    while(low <= high) {
        mid = (low+high)/2.0;
        if ( mid <= A/mid) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid-1;
        }
    }
    return ans;
}
