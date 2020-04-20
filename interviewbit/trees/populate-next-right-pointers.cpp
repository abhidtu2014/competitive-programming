/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) { // Level Order Traversal of Binary Tree
    if (!A) return;
    queue<TreeLinkNode*> q;
    q.push(A);
    q.push(NULL); // NULL marker at end of first Level
    while (!q.empty()) {
        A = q.front();
        q.pop();
        
        if (A == NULL) {
            if (!q.empty())
                q.push(NULL); // NULL marker at the end of next Level
             continue;
        }
        A->next = q.front();
        if (A->left) q.push(A->left);
        if (A->right) q.push(A->right);
    }
}
