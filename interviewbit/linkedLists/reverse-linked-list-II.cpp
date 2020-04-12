/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {
    ListNode* cur=head, *prev=NULL, *next=NULL;
        int i=1;
        for (;i<m;i++) {
            prev=cur;
            cur=cur->next;
        }
        ListNode *front = prev, *tail = cur;
        while(cur!=NULL && i<=n) {
            next = cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
            i++;
        }
        if (front == NULL) {
            head = prev;
        } else {
            front->next = prev;
        }
        tail->next = next;
        return head;
}
