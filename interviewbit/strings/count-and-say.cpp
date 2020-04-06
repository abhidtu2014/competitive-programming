string solve(string s) {
    int n = s.length();
    int cnt =1;
    string temp="";
    s.push_back('$');
    for (int i=1;i<=n;i++) {
        if (s[i] != s[i-1]) {
            temp.push_back(cnt + '0');
            temp.push_back(s[i-1]);
            cnt = 1;
        } else cnt++;
    }
    return temp;
}
string Solution::countAndSay(int A) {
    if (A==0) return "";
    else if (A==1) return "1";
    else if (A==2) return "11";
    else {
        string s = "11";
        for (int i=3;i<=A;i++) {
            s = solve(s);
        }
        return s;
    }
}
