/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* head) {
    ListNode *cur=head,*prev=NULL,*next=NULL;
    while (cur!=NULL) {
        next = cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
ListNode* Solution::reorderList(ListNode* head) {
    // if (!head || !head->next) head;
    ListNode *slow=head,*fast=head,*prev=NULL;
    while (fast != NULL && fast->next != NULL) {
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode *second=slow;
    if (fast != NULL) {
        second = slow->next;
        slow->next = NULL;
    } else if (prev){
        prev->next=NULL;
    }
    
    second = reverseList(second);
    ListNode *first =head, *temp1=NULL,*temp2=NULL;
    
    while (first != NULL && second != NULL) {
        temp1 = first->next;
        temp2 = second->next;
        first->next = second;
        second->next=temp1;
        first = temp1;
        second = temp2;
    }
    return head;
}
