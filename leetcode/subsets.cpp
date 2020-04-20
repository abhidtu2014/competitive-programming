class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res, intermediate;
        vector <int> temp;
        res.push_back(temp);
        for (auto it:nums) {
            intermediate = res;
            for (auto ir: intermediate) {
                temp = ir;
                temp.push_back(it);
                res.push_back(temp);
            }
        }
        return res;
    }
};