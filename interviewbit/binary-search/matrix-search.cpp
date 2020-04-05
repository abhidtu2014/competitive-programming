int searchRow (vector<vector<int> > &A, int B) {
    int low =0, high =A.size()-1, mid, m=A[0].size();
    while(low<=high) {
        mid = (low+high)>>1;
        if (A[mid][0] <= B && A[mid][m-1] >= B) return mid;
        else if (A[mid][0] > B && A[mid][m-1] > B) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int BS (const vector<int> &A, int l, int h, int B) {
    int mid;
    while (l<=h) {
        mid = (l+h)>>1;
        if (A[mid] == B) return 1;
        else if (A[mid] > B) h = mid-1;
        else l = mid+1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    if (!A.size()) return 0;
    int row = searchRow(A, B);
    if (row == -1) return 0;
    return BS(A[row], 0, A[row].size()-1, B);
}
