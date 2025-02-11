
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    typedef struct ListNode bucket;
    bucket *reverse=malloc(sizeof(bucket));
    if (head==NULL) return reverse;
    bucket *current=head;
    while (current!=NULL) {
        bucket *prev=current;
        current->next=reverse;
        reverse=current;
        current=prev;
    }
    return reverse;
}