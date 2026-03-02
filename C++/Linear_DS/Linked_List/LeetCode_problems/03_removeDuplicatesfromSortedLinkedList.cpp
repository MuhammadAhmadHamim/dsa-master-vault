/* 
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.
*/
#include<iostream>
using namespace std;
ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL) return head; // Incase of empty list
    
    ListNode* prev=head; //tracking the previous node
    ListNode* next=head->next; //tracking the next node
    
    while(next!=NULL){ //loop continues as long as next node isn't null(end of tail)
        if(prev->val == next-> val){ //if both have same values(duplicates)
            prev->next=next->next; //skip the node at next ptr
        }
        else{ //if not then move the previous pointer forward
            prev=prev->next;
        }
        next=next->next; //next pointer would move regardless of anything to iterate through the list since it's the loop variable
    }
    return head; //returning the head(start of the chain)
}