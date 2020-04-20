vector<vector<int>> ans;
vector<int> temp;
unordered_map<string, int> m;

void solve (vector<int>& nums, int index, int sum, int target, string hash) {
    if (sum ==0 && !m[hash]) {
        ans.push_back(temp);
        m[hash]=1;
        return;
    }
    for (int i=index;i<nums.size();i++) {
        if (sum-nums[i]>=0) {
            int count = sum/nums[i];
            int j=count;
            while (j>0) {
                temp.push_back(nums[i]);
                hash.append(to_string(nums[i]));
                j--;
            }
            j=count;
            while (j>0) {
                solve(nums, i+1, sum-j*nums[i], target, hash);
                temp.pop_back();
                int l = to_string(nums[i]).size();
                while(l--) {
                    hash.pop_back();
                }
                j--;
            }
        }
    }
}
    
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    ans.clear();
    temp.clear();
    m.clear();
    sort(A.begin(), A.end());
    
    vector<int> temp;
    solve(A, 0, B, B, "");
    return ans;
}
