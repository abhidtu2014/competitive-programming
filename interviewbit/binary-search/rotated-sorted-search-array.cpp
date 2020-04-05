int findPivot (const vector<int> &a) {
    int l = 0, h = a.size()-1, mid, next, prev, n=a.size();
    while(l<=h) {
        if (a[l]<=a[h]) return l;
        mid = (l+h)>>1;
        prev = (mid-1+n)%n;
        next = (mid+1)%n;
        if (a[mid]<=a[prev] && a[mid]<=a[next]) return mid;
        else if (a[mid] <= a[h]) h = mid-1;
        else l =mid+1;
    }
}

int BS (const vector<int> &A, int l, int h, int B) {
    int mid;
    while (l<=h) {
        mid = (l+h)>>1;
        if (A[mid] == B) return mid;
        else if (A[mid] > B) h = mid-1;
        else l = mid+1;
    }
    return -1;
}
int Solution::search(const vector<int> &A, int B) {
    int pivot = findPivot (A);
    int searchLeft = BS(A, 0,pivot-1, B);
    
    if (searchLeft !=-1 ) return searchLeft;
    return BS(A, pivot, A.size()-1, B);
}
