/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
pair<int,int> tree[4000005];

pair<int,int> merge (pair<int,int> a, pair<int,int> b) {
    return (a.first>b.first)? a:b;
}

void buildSegTree (vector<int> &A, int treeIdx, int low, int high) {
    if (low==high) {
        tree[treeIdx] = {A[low], low};
        return;
    }
    int mid = (low+high)>>1;
    buildSegTree(A, 2*treeIdx+1, low, mid);
    buildSegTree(A, 2*treeIdx+2, mid+1, high);
    
    tree[treeIdx] = merge(tree[2*treeIdx+1], tree[2*treeIdx+2]);
}

pair<int,int> querySegTree(int treeIndex, int lo, int hi, int i, int j)
{
    if (lo > j || hi < i)               
        return {0,0};                      
    if (i <= lo && j >= hi)             
        return tree[treeIndex];

    int mid = lo + (hi - lo) / 2;      

    if (i > mid)
        return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    else if (j <= mid)
        return querySegTree(2 * treeIndex + 1, lo, mid, i, j);

    pair<int,int> leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
    pair<int,int> rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

    return merge(leftQuery, rightQuery);
}

TreeNode* constructTree(vector<int> &A, int lo, int hi, int n) {
    if (lo>hi) return NULL;
    pair<int,int> node = querySegTree(0,0,n-1, lo, hi);
    TreeNode * root = new TreeNode(node.first);
    root->left = constructTree(A, lo, node.second-1, n);
    root->right = constructTree(A, node.second+1, hi, n);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    int n =A.size();
    for (int i=0;i<4*n;i++) {
        tree[i] = {0,i};
    }
    buildSegTree(A, 0, 0, n-1);
    return constructTree(A, 0, n-1, n);
}
