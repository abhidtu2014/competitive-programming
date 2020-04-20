vector<int> Solution::findSubstring(string s, const vector<string> &words) {
    unordered_map<string, int> m,has;
    vector<int> ans;
    
    int st=0,en=0,n=s.size(),wn=words.size();
    if (n==0 || wn==0) return ans;
    
    int tl=words[0].size()*wn, wl = words[0].size(); // tl = total_length, wl=word_length
    
    for (auto it: words) has[it]++; // Store count of words
    bool match;
    
    for (int i=0;i<=n-tl;i++) {
        match = true;
        for (int j=i;j<i+tl;j+=wl) {
            m[s.substr(j, wl)]++; // Count of words(j, wl) in substring(i,tl)
        }
        
        for (auto iw: words) {
            if (m[iw] != has[iw]) { // If counts don't match
                match = false;
                break;
            }
        }
        m.clear();
        if (match) {
            ans.push_back(i);
        }
    }
    has.clear();
    return ans;
}
