/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* head, int k) {
    ListNode* cur = head, *prev =NULL, *next=NULL,*front=NULL,*tail=NULL, *newHead=NULL, *prevTail=NULL;
    int i=0;
    while(cur != NULL) {
        front = cur;
        tail = cur;
        i=0;
        while (front !=NULL && i<k) {
            next = front->next;
            front->next=prev;
            prev=front;
            front=next;
            i++;
        }
        if (newHead == NULL) {
            newHead = prev;
        }
        if (prevTail != NULL) {
          prevTail->next = prev;   
        }
        prev=tail;
        prevTail = tail;
        tail ->next = front;
        cur = front;
    }
    return newHead;
}
