int Solution::findMin(const vector<int> &A) {
    int l = 0, h = A.size()-1,mid, next, prev,n=A.size();
    while (l<=h) {
        mid = (l+h)>>1;
        if (A[l] <= A[h]) return A[l];
        
        next = (mid+1)%n;
        prev = (mid-1+n)%n;
        
        if (A[mid] <= A[prev] && A[mid] <= A[next]) return A[mid];
        else if (A[mid] <= A[h]) h = mid -1;
        else l = mid +1;
    }
}