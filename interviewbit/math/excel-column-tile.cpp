string Solution::convertToTitle(int A) {
    string ans = "";
    int r;
    while (A > 0) { 
        A--;
        r = A % 26;
        ans += (char) (r + 'A');
        A/=26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
