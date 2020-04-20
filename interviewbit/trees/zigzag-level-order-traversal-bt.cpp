/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void fill1 (vector<vector<int>> &ans, deque <int> d) {
    vector <int> v;
    while (!d.empty()) {
        v.push_back(d.front());
        d.pop_front();
    }
    ans.push_back(v);
}
void fill2 (vector<vector<int>> &ans, deque <int> d) {
    vector <int> v;
    while (!d.empty()) {
        v.push_back(d.back());
        d.pop_back();
    }
    ans.push_back(v);
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    queue<TreeNode*> q;
    int front = 1;
    vector<vector<int>> ans;
    deque <int> temp;
    
    q.push(A);
    q.push(NULL);
    
    while(!q.empty()) {
        A = q.front();
        q.pop();
        if (A == NULL) {
            if (!q.empty()) q.push(NULL);
            if (front == 1) {
                fill1 (ans, temp);
            } else {
                fill2(ans, temp);
            }
            front*=-1;
            temp.clear();
            continue;
        }
        temp.push_back(A->val);
        if (A->left) q.push(A->left);
        if (A->right) q.push(A->right);
        
    }
    return ans;
}
