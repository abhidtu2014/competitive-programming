int BS (int l, int h, bool searchFirst, const vector<int> &A, int B) {
    int mid, res=-1;
    while (l<=h) {
        mid = (h+l)>>1;
        if (A[mid] > B) h = mid -1;
        else if (A[mid] < B) l = mid+1;
        else {
            res = mid;
            if (searchFirst) {
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
    }
    return res;
}
int Solution::findCount(const vector<int> &A, int B) {
    int firstIdx = BS(0, A.size()-1, true, A, B);
    if (firstIdx == -1) {
        return 0;
    } else {
        int lastIdx = BS(0, A.size()-1, false, A, B);
        return lastIdx - firstIdx + 1;
    }
}
