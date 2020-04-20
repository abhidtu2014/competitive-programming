class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void solve (vector<int>& nums, int index, int sum, int target) {
        if (sum ==0) {
            ans.push_back(temp);
            return;
        }
        for (int i=index;i<nums.size();i++) {
            if (sum-nums[i]>=0) {
                temp.push_back(nums[i]);
                solve(nums, i, sum-nums[i], target);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        temp.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(candidates, 0, target, target);
        return ans;
    }
};