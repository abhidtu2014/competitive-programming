void subset(vector<int> &A, vector<vector<int>> &ans, vector<int> temp, int index) {
    ans.push_back(temp); // Soln
    for (int i=index;i<A.size();i++) {
        temp.push_back(A[i]); // Include possible solution
        subset(A, ans, temp, i+1);
        temp.pop_back(); // Exclude possible solution
    }
    return;
}
vector<vector<int>> Solution::subsets(vector<int> &A) {
    sort(A.begin(), A.end());
    vector<vector<int>> ans;
    vector<int> temp;
    subset(A, ans, temp, 0);
    return ans;
}
