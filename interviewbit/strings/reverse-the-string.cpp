string Solution::solve(string A) {
    int n =A.size();
    string temp="", res="";
    vector<string> v;
    for (int i=0;i<n;i++) {
        if (A[i] == ' ') {
            if (temp.size() > 0) {
                v.push_back(temp);
            }
            temp="";
            continue;
        }
        temp.push_back(A[i]);
    }
    if (temp.size()>0) {
        v.push_back(temp);
    }
    reverse(v.begin(),v.end());
    n = v.size();
    for(int i=0;i<n-1;i++) {
        res += v[i] + ' ';
    }
    if (n-1>=0)
    res += v[n-1];
    return res;
}
