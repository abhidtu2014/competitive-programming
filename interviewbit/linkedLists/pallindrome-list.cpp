ListNode *head;

void reverse (ListNode *p) {
    if (p->next == NULL) {
        head=p;
        return;
    }
    reverse(p->next);
    ListNode *q=p->next;
    q->next=p;
    p->next=NULL;
}

int Solution::lPalin(ListNode* A) {
    if (A == NULL) return 0;
    else if (A->next == NULL) return 1;

    ListNode *slow=A, *fast=A, *midNode=NULL, *prev=A,*cur=A;

    while(fast != NULL && fast->next != NULL) {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if (fast != NULL) {
        slow = slow->next;
    }
    prev->next = NULL;
    reverse(slow);
    
    while (head !=NULL) {
        if (head->val != cur->val) return 0;
        head=head->next;
        cur=cur->next;
    }
    return 1;
}