string findCommon (string a, string b) {
    int n = min(a.length(), b.length());
    string s= "";
    for (int i=0;i<n;i++) {
        if (a[i]==b[i]) s.push_back(a[i]);
    }
    return s;
}
string Solution::longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    string ans = A[0];
    for (int j=1;j<n;j++) {
        ans = findCommon(ans, A[j]);
    }
    return ans;
}
