
//Definition for singly-linked list.
struct ListNode {
    int val;
   struct ListNode *next;
};

#include <stdio.h>
#include <stdbool.h>
bool hasCycle(struct ListNode *head) {
    if (head==NULL) return false;
    typedef struct ListNode bucket;
    bucket *slow=head;
    bucket *fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) return true;
    }
    return false;
}