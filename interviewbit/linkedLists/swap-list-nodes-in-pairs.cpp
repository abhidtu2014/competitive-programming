/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 ListNode* reverseList (ListNode *head, int k) {
    int i =0;
    ListNode *cur=head,*prev=NULL,*next=NULL;
    while(cur!=NULL && i<k) {
        next = cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
        i++;
    }
    if (next) {
        head->next = reverseList(next, k);
    }
    return prev;
}

ListNode* Solution::swapPairs(ListNode* A) {
    return reverseList(A, 2);
}
