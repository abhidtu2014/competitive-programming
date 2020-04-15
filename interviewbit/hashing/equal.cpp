vector<int> Solution::equal(vector<int> &A) {
    int n=A.size();
    map <int , vector<pair<int,int>> > m;
    vector<int> values;
    map<int,int> cnt;
    int a1,b1,c1,d1;
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (m.find(A[i]+A[j]) != m.end()) {
                auto iv =  m[A[i]+A[j]];
                a1 = iv.back().first;
                b1 = iv.back().second;
                c1 = i;
                d1 = j;
                if (a1<b1 && c1<d1 && a1<c1 && b1!=d1 && b1!=c1) {
                    m[A[i]+A[j]].push_back({i,j});
                }
            } else {
                m[A[i]+A[j]].push_back({i,j});
            }
            cnt[A[i]+A[j]]++;
            values.push_back(A[i]+A[j]);
        }
    }
    vector <int> res;
    
    for (auto i1: values) {
        if (cnt[i1] > 1 && m[i1].size()>1) {
            auto iv = m[i1];
            a1 = iv[0].first;
            b1 = iv[0].second;
            c1 = iv[1].first;
            d1 = iv[1].second;
            res.push_back(a1);
            res.push_back(b1);
            res.push_back(c1);
            res.push_back(d1);
            return res;
        }
    }
    return res;            
}
