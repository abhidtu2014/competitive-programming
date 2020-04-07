class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size(),i;
        vector<vector<string>> ans(n);
        if (n == 0) return ans;
        
        string s;
        vector< pair <string,string> > v;
        for (i = 0; i < n;i++) {
            s = strs[i];
            sort(s.begin(), s.end());
            v.push_back({s, strs[i]});
        }
        
        sort(v.begin(), v.end());
            
        ans[0].push_back(v[0].second);
        i = 0;
        for (int j=1;j<n;j++) {
            if (v[j].first == v[j-1].first) {
                ans[i].push_back(v[j].second);
            } else {
                ++i;
                ans[i].push_back(v[j].second);
            }
        }
        ans.resize(i+1);
        return ans;
    }
};