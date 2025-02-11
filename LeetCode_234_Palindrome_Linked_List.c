#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
typedef struct ListNode bucket;

bucket *reverseList(bucket *head) { // function to reverse the passed linked list
    bucket *prev=NULL;
    bucket *current=head;
    bucket *next=NULL;
    while (current!=NULL) {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head==NULL || head->next==NULL) return true;
    // use the Hare-Tortoise algorithm to find the middle of the passed list
    bucket *slow=head; 
    bucket *fast=head;
    while (fast!=NULL && fast->next!=NULL) {
        slow=slow->next;
        fast=fast->next->next;
    }
    bucket *firstHalf=head;
    bucket *secondHalf=reverseList(slow);
    // check value of each nodde of the first half with the corresponding node from the reverse second half
    while (secondHalf!=NULL) {
        if (firstHalf->val!=secondHalf->val) return false;
        firstHalf=firstHalf->next;
        secondHalf=secondHalf->next;
    }
    return true;
}